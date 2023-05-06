/*****************************************************************************
 FILE NAME      : DisplayFrame.cpp
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
#include "DisplayFrame.h"

/*****************************************************************************!
 * Function : DisplayFrame
 *****************************************************************************/
DisplayFrame::DisplayFrame
() : QFrame()
{
    Initialize();
}

/*****************************************************************************!
 * Function : ~DisplayFrame
 *****************************************************************************/
DisplayFrame::~DisplayFrame
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
DisplayFrame::Initialize(void)
{
    BlockFrame = NULL;
}

/*****************************************************************************!
 * Function : GetBlockFrame
 *****************************************************************************/
QFrame*
DisplayFrame::GetBlockFrame(void)
{
    
    return BlockFrame;
}

/*****************************************************************************!
 * Function : SetBlockFrame
 *****************************************************************************/
void
DisplayFrame::SetBlockFrame
(
 QFrame*                                InBlockFrame
)
{
    
    BlockFrame = InBlockFrame;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
DisplayFrame::resizeEvent
(
 QResizeEvent*                          in_event
)
{
    QSize                               size;    
    int                                 width, height;
    QSize				bsize;
    QPoint				bpos;
    int					bwidth, bheight;
    size   = in_event->size();
    width  = size.width();
    height = size.height();

    if ( BlockFrame &&
	 colorFrame1 && colorFrame2 &&
	 colorFrameSelect1 && colorFrameSelect2 ) {

	bsize = BlockFrame->size();
	bpos = BlockFrame->pos();
	
	bwidth = (width - bpos.x()) - 10;
	bheight = (height - bpos.y()) - 10;
	BlockFrame->resize(bwidth, bheight);
	
	colorFrame1->resize(bwidth-21, bheight/2+1);
	colorFrame2->move(20, bheight/2-1);
	colorFrame2->resize(bwidth-21, bheight/2+1);
	colorFrameSelect2->move(5, bheight/2-1);
    }
}

/*****************************************************************************!
 * Function : GetColorFrame1
 *****************************************************************************/
QFrame*
DisplayFrame::GetColorFrame1(void)
{
    return colorFrame1;    
}

/*****************************************************************************!
 * Function : SetColorFrame1
 *****************************************************************************/
void
DisplayFrame::SetColorFrame1
(
 QFrame*                                InColorFrame1
)
{
    colorFrame1 = InColorFrame1;    
}

/*****************************************************************************!
 * Function : GetColorFrame2
 *****************************************************************************/
QFrame*
DisplayFrame::GetColorFrame2(void)
{
    return colorFrame2;    
}

/*****************************************************************************!
 * Function : SetColorFrame2
 *****************************************************************************/
void
DisplayFrame::SetColorFrame2
(
 QFrame*                                InColorFrame2
)
{
    colorFrame2 = InColorFrame2;    
}

/*****************************************************************************!
 * Function : GetColorFrameSelect1
 *****************************************************************************/
QRadioButton*
DisplayFrame::GetColorFrameSelect1(void)
{
    return colorFrameSelect1;    
}

/*****************************************************************************!
 * Function : SetColorFrameSelect1
 *****************************************************************************/
void
DisplayFrame::SetColorFrameSelect1
(
 QRadioButton*                          InColorFrameSelect1
)
{
    colorFrameSelect1 = InColorFrameSelect1;    
}

/*****************************************************************************!
 * Function : GetColorFrameSelect2
 *****************************************************************************/
QRadioButton*
DisplayFrame::GetColorFrameSelect2(void)
{
    return colorFrameSelect2;    
}

/*****************************************************************************!
 * Function : SetColorFrameSelect2
 *****************************************************************************/
void
DisplayFrame::SetColorFrameSelect2
(
 QRadioButton*                          InColorFrameSelect2
)
{
    colorFrameSelect2 = InColorFrameSelect2;    
}
