/*****************************************************************************
 FILE NAME      : ColorFrame.cpp
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
#include "ColorFrame.h"

/*****************************************************************************!
 * Function : ColorFrame
 *****************************************************************************/
ColorFrame::ColorFrame
() : QFrame()
{
    Initialize();
}

/*****************************************************************************!
 * Function : ~ColorFrame
 *****************************************************************************/
ColorFrame::~ColorFrame
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
ColorFrame::Initialize(void)
{
    SubWindowsCreate();
}

/*****************************************************************************!
 * Function : SubWindowsCreate
 *****************************************************************************/
void
ColorFrame::SubWindowsCreate(void)
{
    simpleFrame = new SimpleColorFrame();
    simpleFrame->setParent(this);
    simpleFrame->move(0, 0);
    simpleFrame->show();

    gradientFrame = new GradientColorFrame();
    gradientFrame->setParent(this);
    gradientFrame->move(0, 100);
    gradientFrame->show();

    connect(simpleFrame,   SIGNAL(SignalColorsChanged(QColor, QColor)),
	    gradientFrame, SLOT(SlotColorChanged(QColor, QColor)));
    connect(simpleFrame,   SIGNAL(SignalColorFrame1Selected()),
	    gradientFrame, SLOT(SlotColorFrame1ForceSelect()));
    connect(simpleFrame,   SIGNAL(SignalColorFrame2Selected()),
	    gradientFrame, SLOT(SlotColorFrame2ForceSelect()));
    
    connect(gradientFrame, SIGNAL(SignalColorsChanged(QColor, QColor)),
	    simpleFrame,   SLOT(SlotColorChanged(QColor, QColor)));
    connect(gradientFrame,   SIGNAL(SignalColorFrame1Selected()),
	    simpleFrame, SLOT(SlotColorFrame1ForceSelect()));
    connect(gradientFrame,   SIGNAL(SignalColorFrame2Selected()),
	    simpleFrame, SLOT(SlotColorFrame2ForceSelect()));
    
    tabWidget = new QTabWidget(this);
    tabWidget->addTab(simpleFrame, "Color");
    tabWidget->addTab(gradientFrame, "Gradient");
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ColorFrame::resizeEvent
(
 QResizeEvent*                          in_event
)
{
    QSize                               size;    
    int                                 width, height;
    size   = in_event->size();
    width  = size.width();
    height = size.height();
    tabWidget->resize(width, height);
}
