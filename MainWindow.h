/*****************************************************************************
 FILE NAME      : MainWindow.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _mainwindow_h_
#define _mainwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMainWindow>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_WIDTH                       660
#define MAIN_WINDOW_HEIGHT                      480
#define MAIN_WINDOW_Y                           100
#define MAIN_WINDOW_X                           100

/*****************************************************************************!
 * Exported Class : MainWindow
 *****************************************************************************/
class MainWindow : public QMainWindow
{
    Q_OBJECT;

 //! Constructors
 public :
    MainWindow                  ();
    MainWindow                  (QWidget* );

 //! Destructor
 public :
    ~MainWindow                 ();

 //! Protected Data
 protected :

 //! Public Data
 public :
    MainDisplayWindow*          display_window;

 //! Public Methods
 public :

 //! Public Actions
 public :
    QAction*                    action_exit;

 //! Public Slots
 public slots :
    void                        slotexit                (void);

 //! Public Signals
 signals :

 //! Private Data
 private :
    QMenuBar*                   menubar;
    QStatusBar*                 statusbar;

 //! Private Methods
 private :
    void                        initialize              ();
    void                        subwindows_create       ();
    void                        resizeEvent             (QResizeEvent* event);
    void                        actions_create          ();
    void                        menus_create            ();

};

#endif /* _mainwindow_h_*/
