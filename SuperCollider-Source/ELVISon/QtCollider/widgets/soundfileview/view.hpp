/************************************************************************
*
* Copyright 2010 Jakob Leben (jakob.leben@gmail.com)
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

#ifndef QC_SOUND_FILE_VIEW_H
#define QC_SOUND_FILE_VIEW_H

#include "../../Common.h"
#include "../../QcHelper.h"

#include <sndfile.h>

#include <QVBoxLayout>
#include <QScrollBar>
#include <QSlider>
#include <QPixmap>
#include <QThread>

class QcWaveform;
class SoundCacheStream;

struct SoundCache {
  SoundCache() : min(0), max(0), sum(0), sum2(0) {};
  ~SoundCache() {
    delete [] min;
    delete [] max;
    delete [] sum;
    delete [] sum2;
  }
  short *min;
  short *max;
  float *sum;
  float *sum2;
};

class QcWaveform : public QWidget, public QcHelper {

  Q_OBJECT

  Q_PROPERTY( float readProgress READ loadProgress );
  Q_PROPERTY( int startFrame READ startFrame );
  Q_PROPERTY( int frames READ frames );
  Q_PROPERTY( double viewFrames READ viewFrames );
  Q_PROPERTY( double viewStartFrame READ viewStartFrame WRITE scrollTo );
  Q_PROPERTY( float scrollPos READ scrollPos WRITE setScrollPos );
  Q_PROPERTY( int currentSelection READ currentSelection WRITE setCurrentSelection );
  Q_PROPERTY( VariantList selections READ selections );

  Q_PROPERTY( float yZoom READ yZoom WRITE setYZoom );
  Q_PROPERTY( float xZoom READ xZoom WRITE setXZoom );
  Q_PROPERTY( bool cursorVisible READ cursorVisible WRITE setCursorVisible );
  Q_PROPERTY( bool cursorEditable READ cursorEditable WRITE setCursorEditable );
  Q_PROPERTY( int cursorPosition READ cursorPosition WRITE setCursorPosition );
  Q_PROPERTY( bool gridVisible READ gridVisible WRITE setGridVisible );
  Q_PROPERTY( float gridOffset READ gridOffset WRITE setGridOffset );
  Q_PROPERTY( float gridResolution READ gridResolution WRITE setGridResolution );
  Q_PROPERTY( bool drawsWaveform READ drawsWaveform WRITE setDrawsWaveform );
  Q_PROPERTY( QColor background READ background WRITE setBackground );
  Q_PROPERTY( QColor peakColor READ peakColor WRITE setPeakColor );
  Q_PROPERTY( QColor rmsColor READ rmsColor WRITE setRmsColor );
  Q_PROPERTY( QColor cursorColor READ cursorColor WRITE setCursorColor );
  Q_PROPERTY( QColor gridColor READ gridColor WRITE setGridColor );

public:
  Q_INVOKABLE void load( const QString& filename );

  // NOTE: Using int instead of sf_count_t for accessibility from SC language.
  Q_INVOKABLE void load( const QString& filename, int beginning, int duration );

  Q_INVOKABLE void load( const QVector<double> & data, int offset = 0,
                         int channels = 1, int samplerate = 44100 );

  Q_INVOKABLE void allocate ( int frames, int channels = 1, int samplerate = 44100 );

  Q_INVOKABLE void write( const QVector<double> & data, int offset );

public:

  struct Selection {
    Selection() : start(0), size(0), editable(true), color(QColor(0,0,150)) {}
    sf_count_t start;
    sf_count_t size;
    bool editable;
    QColor color;
  };

  QcWaveform( QWidget * parent = 0 );
  ~QcWaveform();

  float loadProgress();
  sf_count_t startFrame() { return _rangeBeg; }
  sf_count_t frames() { return _rangeDur; }

  double viewStartFrame() { return _beg; }
  double viewFrames() { return _dur; }
  float scrollPos(); // as fraction of scrolling range
  float zoom(); //visible fraction
  float xZoom(); //visible seconds
  float yZoom(); //factor

  VariantList selections() const;
  int currentSelection() const { return _curSel; }
  void setCurrentSelection( int i );
  // for SC: selection start relative to first loaded frame
  Q_INVOKABLE VariantList selection( int index ) const;
  // for SC: selection start relative to first loaded frame
  Q_INVOKABLE void setSelection( int index, VariantList data );
  void setSelection( int i, sf_count_t a, sf_count_t b );
  Q_INVOKABLE void setSelectionStart( int i, sf_count_t frame );
  Q_INVOKABLE void setSelectionEnd( int i, sf_count_t frame );
  Q_INVOKABLE void setSelectionEditable( int index, bool editable );
  Q_INVOKABLE void setSelectionColor( int index, const QColor &clr );
  Q_PROPERTY( VariantList waveColors READ waveColors WRITE setWaveColors );

  bool cursorVisible() const { return _showCursor; }
  void setCursorVisible( bool b ) { _showCursor = b; update(); }
  int cursorPosition() const { return _cursorPos; }
  void setCursorPosition( int pos ) { _cursorPos = pos; update(); }
  bool cursorEditable() const { return _cursorEditable; }
  void setCursorEditable( bool b ) { _cursorEditable = b; }

  bool gridVisible() const { return _showGrid; }
  void setGridVisible( bool b ) { _showGrid = b; update(); }
  float gridOffset() const { return _gridOffset; }
  void setGridOffset( float f ) { _gridOffset = f; update(); }
  float gridResolution() const { return _gridResolution; }
  void setGridResolution( float f ) { _gridResolution = f; update(); }

  bool drawsWaveform() const { return _drawWaveform; }
  void setDrawsWaveform( bool b ) { _drawWaveform = b; update(); }
  VariantList waveColors() const;
  void setWaveColors( const VariantList & );

  const QColor & background() const { return _bkgColor; }
  void setBackground( const QColor &c )
  {
      if(_bkgColor == c) return;
      _bkgColor = c;
      setAttribute(Qt::WA_OpaquePaintEvent, c.isValid() && c.alpha() == 255);
      update();
  }
  const QColor & peakColor() const { return _peakColor; }
  void setPeakColor( const QColor &clr ) { _peakColor = clr; redraw(); }
  const QColor & rmsColor() const { return _rmsColor; }
  void setRmsColor( const QColor &clr ) { _rmsColor = clr; redraw(); }
  const QColor & cursorColor() const { return _cursorColor; }
  void setCursorColor( const QColor &c ) { _cursorColor = c; update(); }
  const QColor & gridColor() const { return _gridColor; }
  void setGridColor( const QColor &c ) { _gridColor = c; update(); }

  QSize sizeHint() const { return QSize( 400, 200 ); }
  QSize minimumSizeHint() const { return QSize( 100, 20 ); }

public Q_SLOTS:
  void zoomTo( double fraction );
  //void zoomTo( float fraction, quint64 frame );
  void zoomBy( double factor );
  void zoomAllOut();
  void zoomSelection( int selectionIndex );
  void scrollTo( double frame );
  void scrollBy( double frames );
  void setScrollPos( double fraction ); // as fraction of scrolling range
  void scrollToStart();
  void scrollToEnd();
  void setYZoom( double factor );
  void setXZoom( double seconds );


Q_SIGNALS:

  void loadProgress( int );
  void loadingDone();

  void action();
  void metaAction();

public Q_SLOTS:

  void redraw() {
    dirty = true;
    update();
  }

protected:

  virtual void resizeEvent( QResizeEvent * );
  virtual void paintEvent( QPaintEvent * );
  virtual void keyPressEvent( QKeyEvent * );
  virtual void mousePressEvent( QMouseEvent * );
  virtual void mouseDoubleClickEvent ( QMouseEvent * );
  virtual void mouseMoveEvent( QMouseEvent * );

private:

  void doLoad( SNDFILE *new_sf, const SF_INFO &new_info, sf_count_t beginning, sf_count_t duration );
  inline void updateFPP() { _fpp = width() ? (double) _dur / width() : 0.0; }
  void rebuildCache ( int maxFramesPerCache, int maxRawFrames );
  void draw ( QPixmap *, int x, int width, double beginning, double duration );

  // data
  SNDFILE *sf;
  SF_INFO sfInfo;
  sf_count_t _rangeBeg;
  sf_count_t _rangeDur;
  sf_count_t _rangeEnd;

  SoundCacheStream *_cache;

   // selections
  Selection _selections[64];
  int _curSel;

  // cursor
  bool _showCursor;
  sf_count_t _cursorPos;
  bool _cursorEditable;

  //grid
  bool _showGrid;
  float _gridResolution;
  float _gridOffset;

  // view
  double _beg;
  double _dur;
  double _fpp;
  float _yZoom;

  // painting
  QPixmap *pixmap;
  QColor _bkgColor;
  QColor _peakColor;
  QColor _rmsColor;
  QColor _cursorColor;
  QColor _gridColor;
  bool dirty;
  bool _drawWaveform;
  QList<QColor> _waveColors;

  // interaction
  enum DragAction {
    NoDragAction,
    Navigate,
    Select,
    MoveSelection,
    MoveCursor
  };
  DragAction _dragAction;
  QPointF _dragPoint;
  sf_count_t _dragFrame;
  double _dragData;
  double _dragData2;
};

class SoundStream {
public:
  inline int channels() { return _ch; }

  inline sf_count_t beginning() { return _beg; }

  inline sf_count_t duration() { return _dur; }

  virtual bool displayData( int channel, double offset, double duration,
                            short *minBuffer,
                            short *maxBuffer,
                            short *minRMS,
                            short *maxRMS,
                            int bufferSize ) = 0;

  virtual short *rawFrames( int channel, sf_count_t beginning, sf_count_t duration, bool *interleaved ) = 0;

protected:
  SoundStream()
  : _ch( 0 ), _beg( 0 ), _dur( 0 ) {}

  SoundStream( int channels, sf_count_t beginning, sf_count_t duration ) :
    _ch( channels ), _beg( beginning ), _dur( duration ) {}

  int _ch;
  sf_count_t _beg;
  sf_count_t _dur;
};

class SoundFileStream : public SoundStream
{
public:
  SoundFileStream();
  SoundFileStream( SNDFILE *sf, const SF_INFO &sf_info, sf_count_t beginning, sf_count_t duration );
  ~SoundFileStream();
  void load( SNDFILE *sf, const SF_INFO &sf_info, sf_count_t beginning, sf_count_t duration );
  bool integrate( int channel, double offset, double duration,
                  short *minBuffer,
                  short *maxBuffer,
                  float *sumBuffer,
                  float *sum2Buffer,
                  int bufferSize );
  bool displayData( int channel, double offset, double duration,
                    short *minBuffer,
                    short *maxBuffer,
                    short *minRMS,
                    short *maxRMS,
                    int bufferSize );
  short *rawFrames( int channel, sf_count_t beginning, sf_count_t duration, bool *interleaved );
private:
  short *_data;
  sf_count_t _dataSize;
  sf_count_t _dataOffset;
};

class SoundCacheLoader;

class SoundCacheStream : public QObject, public SoundStream
{
  friend class SoundCacheLoader;

  Q_OBJECT

public:
  SoundCacheStream();
  ~SoundCacheStream();
  void load( const QVector<double> & data, int frames, int offset, int channels );
  void load( SNDFILE *sf, const SF_INFO &info, sf_count_t beg, sf_count_t dur,
             int maxFramesPerUnit, int maxRawFrames );
  void allocate ( int frames, int channels );
  void write( const QVector<double> & data, int offset, int count );

  inline double fpu() { return _fpu; }
  inline bool ready() { return _ready; }
  inline bool loading() { return _loading; }
  inline int loadProgress() { return _loadProgress; }
  bool displayData( int channel, double offset, double duration,
                    short *minBuffer,
                    short *maxBuffer,
                    short *minRMS,
                    short *maxRMS,
                    int bufferSize );
  short *rawFrames( int channel, sf_count_t beginning, sf_count_t duration, bool *interleaved );

Q_SIGNALS:
  void loadProgress( int );
  void loadingDone();

private Q_SLOTS:
  void onLoadProgress( int );
  void onLoadingDone();

private:
  SoundCache *_caches;
  double _fpu; // soundfile frames per cache unit
  sf_count_t _dataOffset; // offset into soundfile of first frame cached (in frames)
  sf_count_t _dataSize; // amount of cache units
  bool _ready;
  bool _loading;
  SoundCacheLoader *_loader;
  int _loadProgress;
};

class SoundCacheLoader : public QThread
{
  Q_OBJECT
public:
  SoundCacheLoader( SoundCacheStream *cache ) : QThread( cache ), _cache( cache ), _sf(0) {}
  void load( SNDFILE *sf, const SF_INFO &info );

Q_SIGNALS:
  void loadProgress( int );
  void loadingDone();
private:
  void run();

  SoundCacheStream *_cache;
  SNDFILE *_sf;
  SF_INFO _info;
};

#endif
