/*****************************************************************************
 FILE NAME      : ColorFrame.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _colorframe_h_
#define _colorframe_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QTabWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SimpleColorFrame.h"
#include "GradientColorFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ColorFrame
 *****************************************************************************/
class ColorFrame : public QFrame
{
    Q_OBJECT;

 //! Constructors
 public :
    ColorFrame                  ();

 //! Destructor
 public :
    ~ColorFrame                 ();

 //! Protected Data
 protected :

 //! Public Data
 public :

 //! Public Methods
 public :
    void                        Initialize              (void);

 //! Public Actions
 public :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Private Data
 private :
    GradientColorFrame*         gradientFrame;
    SimpleColorFrame*           simpleFrame;
    QTabWidget*                 tabWidget;

 //! Private Methods
 private :
    void                        SubWindowsCreate        (void);
    void                        resizeEvent             (QResizeEvent* event);

};

#endif /* _colorframe_h_*/
