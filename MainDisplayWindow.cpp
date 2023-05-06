/*****************************************************************************
 FILE NAME      : MainDisplayWindow.cpp
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

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
() : QWidget()
{
    initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : subwindows_create
 *****************************************************************************/
void
MainDisplayWindow::subwindows_create()
{
    colorFrame = new ColorFrame();
    colorFrame->setParent(this);
    colorFrame->move(0, 0);
    colorFrame->show();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(
 QResizeEvent*				InResize             
)
{
    colorFrame->resize(InResize->size());
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
MainDisplayWindow::initialize()
{
    subwindows_create();    
}
