/************************************************************************
*
* Copyright 2010-2012 Jakob Leben (jakob.leben@gmail.com)
*
* This file is part of SuperCollider Qt GUI.
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
************************************************************************/

#include "primitives.h"

#include "../Common.h"
#include "../Slot.h"
#include "../QcApplication.h"
#include "../QObjectProxy.h"
#include "../style/style.hpp"
#include "QtCollider.h"

#ifdef Q_WS_MAC
# include "../hacks/hacks_mac.hpp"
#endif

#include <PyrKernel.h>

#include <QFontDatabase>
#include <QFontInfo>
#include <QFontMetrics>
#include <QDesktopWidget>
#include <QStyleFactory>
#include <QWebSettings>
#include <QCursor>

namespace QtCollider {

QC_LANG_PRIMITIVE( QtGUI_SetDebugLevel, 1, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  QtCollider::setDebugLevel( Slot::toInt(a) );
  return errNone;
}

QC_LANG_PRIMITIVE( QtGUI_DebugLevel, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  SetInt( r, QtCollider::debugLevel() );
  return errNone;
}

QC_LANG_PRIMITIVE( QWindow_ScreenBounds, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QRect screenGeometry = QApplication::desktop()->screenGeometry();
  Slot::setRect( r, screenGeometry );
  return errNone;
}

QC_LANG_PRIMITIVE( QWindow_AvailableGeometry, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QRect rect = QApplication::desktop()->availableGeometry();
  Slot::setRect( r, rect );
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_StringBounds, 2, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  QString str = Slot::toString( a );

  QFont f = Slot::toFont( a+1 );

  QFontMetrics fm( f );
  QRect bounds = fm.boundingRect( str );

  // we keep the font height even on empty string;
  if( str.isEmpty() ) bounds.setHeight( fm.height() );

  Slot::setRect( r, bounds );
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_AvailableFonts, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  QFontDatabase database;
  VariantList l;
  Q_FOREACH( QString family, database.families() ) {
    l.data << QVariant(family);
  }
  Slot::setVariantList( r, l );
  return errNone;
}

QC_LANG_PRIMITIVE( QFont_SetDefaultFont, 2, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
    if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

    if ( !isKindOfSlot( a+0, SC_CLASS(QFont) ) )
        return errWrongType;

    QFont font( Slot::toFont(a+0) );
    const char *className = IsSym(a+1) ? slotRawSymbol(a+1)->name : 0;

    QApplication::setFont( font, className );

    return errNone;
}

QC_LANG_PRIMITIVE( QFont_DefaultFamilyForStyle, 1, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
    // NOTE:
    // On X11 systems we rely on default fontconfig mappings of font familiy names,
    // as style hints are not necessarily supported.
    // On other systems, style hints should work.

    if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

    if ( !IsInt(a) )
        return errWrongType;

    QFont::StyleHint styleHint;
    QString family;
    switch (slotRawInt(a)) {
    case 0:
        styleHint = QFont::SansSerif;
        family = "sans-serif";
        break;
    case 1:
        styleHint = QFont::Serif;
        family = "serif";
        break;
    case 2:
        styleHint = QFont::TypeWriter;
        family = "monospace";
        break;
    default:
        styleHint = QFont::AnyStyle;
    }

    QFont font(family);
    font.setStyleHint(styleHint);

    QFontInfo fontInfo(font);
    Slot::setString( r, fontInfo.family() );

    return errNone;
}

QC_LANG_PRIMITIVE( Qt_GlobalPalette, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QPalette p( QApplication::palette() );
  Slot::setPalette( r, p );
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_SetGlobalPalette, 1, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QPalette p = Slot::toPalette( a );
  QApplication::setPalette( p );

  return errNone;
}

QC_LANG_PRIMITIVE( Qt_FocusWidget, 0,  PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QWidget *w = QApplication::focusWidget();

#ifdef Q_WS_MAC
  // On Mac we need to make additional checks, as Qt does not monitor
  // focus changes to native Cocoa windows in the same application.
  if( w && !QtCollider::Mac::isKeyWindow( w ) )
    w = 0;
#endif

  if( w ) {
    QObjectProxy *proxy = QObjectProxy::fromObject(w);
    if( proxy && proxy->scObject() ) {
      SetObject( r, proxy->scObject() );
      return errNone;
    }
  }

  SetNil(r);
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_SetStyle, 1, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QString str = Slot::toString( a );
  if( str.isEmpty() ) return errFailed;

  QStyle *style = QStyleFactory::create( str );
  if( !style ) return errFailed;

  QApplication::setStyle( new QtCollider::Style::StyleImpl( style ) );
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_AvailableStyles, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  VariantList list;
  Q_FOREACH( QString key, QStyleFactory::keys() ) {
    list.data << QVariant(key);
  }

  Slot::setVariantList( r, list );
  return errNone;
}

QC_LANG_PRIMITIVE( QWebView_ClearMemoryCaches, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

  QWebSettings::clearMemoryCaches();

  return errNone;
}

QC_LANG_PRIMITIVE( Qt_IsMethodOverridden, 2, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
  if(NotObj(a) || NotSym(a+1))
    return errWrongType;

  PyrObject *self = slotRawObject(r);
  PyrObjectHdr *superclass = slotRawObject(a);
  PyrSymbol *method = slotRawSymbol(a+1);

  for(PyrClass *klass = self->classptr;
      klass != superclass && klass != class_object;
      klass = slotRawSymbol(&klass->superclass)->u.classobj)
  {
    PyrSlot *methodSlot = &klass->methods;
    if(!IsObj(methodSlot)) continue;
    PyrObject *methodArray = slotRawObject(methodSlot);
    PyrSlot *methods = methodArray->slots;
    for(int i = 0; i < methodArray->size; ++i)
    {
      PyrMethod *m = slotRawMethod(methods+i);
      if(slotRawSymbol(&m->name) == method){
        SetTrue(r);
        return errNone;
      }
    }
  }

  SetFalse(r);
  return errNone;
}

QC_LANG_PRIMITIVE( Qt_CursorPosition, 0, PyrSlot *r, PyrSlot *a, VMGlobals *g )
{
    if( !QcApplication::compareThread() ) return QtCollider::wrongThreadError();

    Slot::setPoint(r, QCursor::pos());
    return errNone;
}

void defineMiscPrimitives()
{
  LangPrimitiveDefiner definer;
  definer.define<QtGUI_SetDebugLevel>();
  definer.define<QtGUI_DebugLevel>();
  definer.define<QWindow_ScreenBounds>();
  definer.define<QWindow_AvailableGeometry>();
  definer.define<Qt_StringBounds>();
  definer.define<Qt_AvailableFonts>();
  definer.define<QFont_SetDefaultFont>();
  definer.define<QFont_DefaultFamilyForStyle>();
  definer.define<Qt_GlobalPalette>();
  definer.define<Qt_SetGlobalPalette>();
  definer.define<Qt_FocusWidget>();
  definer.define<Qt_SetStyle>();
  definer.define<Qt_AvailableStyles>();
  definer.define<Qt_IsMethodOverridden>();
  definer.define<QWebView_ClearMemoryCaches>();
  definer.define<Qt_CursorPosition>();
}

} // namespace QtCollider
