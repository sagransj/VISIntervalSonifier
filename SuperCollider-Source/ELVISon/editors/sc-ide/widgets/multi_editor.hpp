/*
    SuperCollider Qt IDE
    Copyright (c) 2012 Jakob Leben & Tim Blechmann
    http://www.audiosynth.com

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*/

#ifndef SCIDE_WIDGETS_MULTI_EDITOR_HPP_INCLUDED
#define SCIDE_WIDGETS_MULTI_EDITOR_HPP_INCLUDED

#include <QWidget>
#include <QTabBar>
#include <QAction>
#include <QPushButton>
#include <QToolButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QGridLayout>
#include <QTextDocument>
#include <QSplitter>
#include <QSignalMapper>

namespace ScIDE {

class CodeEditorBox;
class Document;
class DocumentManager;
class GenericCodeEditor;
class Main;
class MultiSplitter;
class Session;
class SignalMultiplexer;

namespace Settings { class Manager; }

class MultiEditor : public QWidget
{
    Q_OBJECT

public:

    enum ActionRole
    {
        // Edit
        Undo,
        Redo,
        Cut,
        Copy,
        Paste,
        IndentLineOrRegion,
        TriggerAutoCompletion,
        TriggerMethodCallAid,
        ToggleComment,
        ToggleOverwriteMode,

        CopyLineUp,
        CopyLineDown,
        MoveLineUp,
        MoveLineDown,

        GotoPreviousBlock,
        GotoNextBlock,
        SelectEnclosingBlock,

        GotoPreviousRegion,
        GotoNextRegion,
        GotoPreviousEmptyLine,
        GotoNextEmptyLine,

        SelectRegion,

        // View
        EnlargeFont,
        ShrinkFont,
        ResetFontSize,
        ShowWhitespace,
        IndentWithSpaces,

        NextDocument,
        PreviousDocument,
        SwitchDocument,

        SplitHorizontally,
        SplitVertically,
        RemoveCurrentSplit,
        RemoveAllSplits,

        // Language
        EvaluateCurrentDocument,
        EvaluateRegion,
        EvaluateLine,

        ActionRoleCount
    };

    MultiEditor( Main *, QWidget * parent = 0 );

    int tabCount() { return mTabs->count(); }
    Document * documentForTab( int index );
    int tabForDocument( Document * doc );

    GenericCodeEditor *currentEditor();
    CodeEditorBox *currentBox() { return mCurrentEditorBox; }
    void split( Qt::Orientation direction );

    QAction * action( ActionRole role )
        { return mActions[role]; }

    void saveSession( Session * );
    void switchSession( Session * );

signals:
    void currentDocumentChanged( Document * );

public slots:

    void setCurrent( Document * );

    void showNextDocument();
    void showPreviousDocument();
    void switchDocument();

    void splitHorizontally() { split(Qt::Horizontal); }
    void splitVertically() { split(Qt::Vertical); }
    void removeCurrentSplit();
    void removeAllSplits();

private slots:
    void onOpen( Document *, int initialCursorPosition, int selectionLength );
    void onClose( Document * );
    void show( Document *, int cursorPosition = -1, int selectionLenght = 0 );
    void update( Document * );
    void onCloseRequest( int index );
    void onCurrentTabChanged( int index );
    void onCurrentEditorChanged( GenericCodeEditor * );
    void onBoxActivated( CodeEditorBox * );
    void onDocModified( QObject * );

private:
    void makeSignalConnections();
    void breakSignalConnections();
    void createActions();
    void updateActions();
    int addTab( Document * );
    CodeEditorBox *newBox();
    void setCurrentBox( CodeEditorBox * );
    void setCurrentEditor( GenericCodeEditor * );
    void loadBoxState( CodeEditorBox *box, const QVariantList & data, const QList<Document *> & documentList );
    void loadSplitterState( QSplitter *, const QVariantMap & data, const QList<Document *> & documentList );

    QAction *mActions[ActionRoleCount];

    SignalMultiplexer * mEditorSigMux;
    SignalMultiplexer * mBoxSigMux;
    QSignalMapper mDocModifiedSigMap;

    // gui
    QTabBar *mTabs;
    CodeEditorBox *mCurrentEditorBox;
    MultiSplitter *mSplitter;
    QIcon mDocModifiedIcon;
};

} // namespace ScIDE

#endif // SCIDE_WIDGETS_MULTI_EDITOR_HPP_INCLUDED
