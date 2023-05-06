/*****************************************************************************
 FILE NAME      : MainDisplayWindow.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ColorFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
    Q_OBJECT;

 //! Constructors
 public :
    MainDisplayWindow           ();

 //! Destructor
 public :
    ~MainDisplayWindow          ();

 //! Protected Data
 protected :

 //! Public Data
 public :

 //! Public Methods
 public :

 //! Public Actions
 public :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Private Data
 private :
    ColorFrame*                 colorFrame;

 //! Private Methods
 private :
    void                        subwindows_create       ();
    void                        resizeEvent             (QResizeEvent* );
    void                        initialize              ();

};

#endif /* _maindisplaywindow_h_*/
