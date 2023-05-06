/*****************************************************************************
 FILE NAME      : ControlsFrame.cpp
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
#include "ControlsFrame.h"

/*****************************************************************************!
 * Function : ControlsFrame
 *****************************************************************************/
ControlsFrame::ControlsFrame
() : QFrame()
{
    Initialize();
}

/*****************************************************************************!
 * Function : ~ControlsFrame
 *****************************************************************************/
ControlsFrame::~ControlsFrame
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
ControlsFrame::Initialize(void)
{
    colorFrame = NULL;
}

/*****************************************************************************!
 * Function : GetColorFrame
 *****************************************************************************/
QFrame*
ControlsFrame::GetColorFrame(void)
{
    return colorFrame;    
}

/*****************************************************************************!
 * Function : SetColorFrame
 *****************************************************************************/
void
ControlsFrame::SetColorFrame
(
 QFrame*                                InColorFrame
)
{
    colorFrame = InColorFrame;    
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ControlsFrame::resizeEvent
(
 QResizeEvent*                          in_event
)
{
    QSize                               size;    
    int                                 width, height;
    size   = in_event->size();
    width  = size.width();
    height = size.height();

    if ( colorFrame ) {
	QPoint				p = colorFrame->pos();
	colorFrame->resize(width - (p.x() * 2),
			   height - (p.y() + 10));
    }
}
