/*****************************************************************************
 FILE NAME      : MainWindow.cpp
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMenuBar>
#include <QStatusBar>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindow.h"

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
() : QMainWindow()
{
}

/*****************************************************************************!
 * Function : MainWindow
 *****************************************************************************/
MainWindow::MainWindow
(
 QWidget*                               parent
) : QMainWindow(parent)
{
    initialize();
    actions_create();
    menus_create();
    subwindows_create();
}

/*****************************************************************************!
 * Function : ~MainWindow
 *****************************************************************************/
MainWindow::~MainWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainWindow::initialize()
{
    display_window = NULL;    
}

/*****************************************************************************!
 * Function : subwindows_create
 *****************************************************************************/
void
MainWindow::subwindows_create()
{
    display_window = new MainDisplayWindow();    
    display_window->setParent(this);
    statusbar = statusBar();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainWindow::resizeEvent
(
 QResizeEvent*                          in_event
)
{
    int                                 width;
    int                                 height;
    QSize                               size;
    QSize                               statusbar_size;
    QSize                               menu_size;
    size = in_event->size();
    menu_size = menubar->size();
    statusbar_size = statusbar->size();
    width = size.width();
    height = size.height() - (menu_size.height() + statusbar_size.height());
    if ( display_window ) {
	display_window->move(0, menu_size.height());
	display_window->resize(width, height);
    }
}

/*****************************************************************************!
 * Function : actions_create
 *****************************************************************************/
void
MainWindow::actions_create()
{
    action_exit = new QAction("E&xit", this);
    connect(action_exit, SIGNAL(triggered()), this, SLOT(slotexit()));
}

/*****************************************************************************!
 * Function : menus_create
 *****************************************************************************/
void
MainWindow::menus_create()
{
    QMenu*                              menu;
    menubar = menuBar();
    menu = menubar->addMenu("&File");
    menu->addAction(action_exit);
}

/*****************************************************************************!
 * Function : slotexit
 *****************************************************************************/
void
MainWindow::slotexit(void)
{
    exit(0);
}
