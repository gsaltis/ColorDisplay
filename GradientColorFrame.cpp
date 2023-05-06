/*****************************************************************************
 FILE NAME      : GradientColorFrame.cpp
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
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "GradientColorFrame.h"

/*****************************************************************************!
 * Function : GradientColorFrame
 *****************************************************************************/
GradientColorFrame::GradientColorFrame
() : SimpleColorFrame()
{
    Initialize();
}

/*****************************************************************************!
 * Function : ~GradientColorFrame
 *****************************************************************************/
GradientColorFrame::~GradientColorFrame
()
{
}

/*****************************************************************************!
 * Function : SetColorFrame
 *****************************************************************************/
void
GradientColorFrame::SetColorFrame(void)
{
    QPalette				pal  = colorFrame->palette();
    QSize				size = colorFrame->size();
    QLinearGradient			grad;

    
    grad.setStart(QPoint(0, 0));
    if ( Direction == Horizontal ) {
	grad.setFinalStop(QPoint(size.width(), 0));
    } else if ( Direction == Vertical ) {
	grad.setFinalStop(QPoint(0, size.height()));
    } else {
	grad.setFinalStop(QPoint(size.width(), size.height()));
    }

    grad.setColorAt(Stop1, colorFrame1->palette().brush(QPalette::Window).color());
    grad.setColorAt(Stop2, colorFrame2->palette().brush(QPalette::Window).color());
    
    pal.setBrush(QPalette::Window, QBrush(grad));
    colorFrame->setPalette(pal);
}    

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
GradientColorFrame::Initialize(void)
{
    Direction = 0;
    SubWindowsCreate();
}

/*****************************************************************************!
 * Function : SubWindowsCreate
 *****************************************************************************/
void
GradientColorFrame::SubWindowsCreate(void)
{
    QPoint                              p;
    QSize                               s;
    QStringList                         strings;
    int					x1, x2;
    int					y, labelWidth;
    QLabel*				label;
    
    DirectionSelection = new QComboBox(this);
    p = lighterButton->pos();
    s = lighterButton->size();

    y = p.y();
    x1 = p.x() + s.width() + 20;
    x2 = x1 + 60;
    labelWidth = 60;
	
    label = new QLabel(this);
    label->setFont(labelFont);
    label->resize(labelWidth, 20);
    label->move(x1, y);
    label->setText("Direction");
    
    DirectionSelection->resize(s);
    DirectionSelection->move(x2, y);
    strings << "Horizontal" << "Vertical" << "Diagonal";
    DirectionSelection->addItems(strings);
    DirectionSelection->show();
    connect(DirectionSelection, SIGNAL(currentIndexChanged(int)),
	    this,		SLOT(SlotDirectionSelected(int)));

    strings = QStringList();
    strings << "0.0" << "0.1" << "0.2" << "0.3" << "0.4" << "0.5"
	    << "0.6" << "0.7" << "0.8" << "0.9" << "1.0";
    
    //!
    y += 25;
    label = new QLabel(this);
    label->setFont(labelFont);
    label->resize(labelWidth, 20);
    label->move(x1, y);
    label->setText("First Stop");
    
    Stop1Selection = new QComboBox(this);
    Stop1Selection->resize(s);
    Stop1Selection->move(x2, y);
    Stop1Selection->addItems(strings);
    Stop1Selection->show();
    connect(Stop1Selection, SIGNAL(currentTextChanged(QString)),
	    this,	    SLOT(SlotStop1Selected(QString)));
    Stop1Selection->setCurrentIndex(0);

    //!
    y += 25;
    label = new QLabel(this);
    label->setFont(labelFont);
    label->resize(labelWidth, 20);
    label->move(x1, y);
    label->setText("Last Stop");
    
    Stop2Selection = new QComboBox(this);
    Stop2Selection->resize(s);
    Stop2Selection->move(x2, y);
    Stop2Selection->addItems(strings);
    Stop2Selection->show();
    connect(Stop2Selection, SIGNAL(currentTextChanged(QString)),
	    this,	    SLOT(SlotStop2Selected(QString)));
    Stop2Selection->setCurrentIndex(10);
}

/*****************************************************************************!
 * Function : SlotDirectionSelected
 *****************************************************************************/
void
GradientColorFrame::SlotDirectionSelected
(
 int				InDirection
)
{
    Direction = InDirection;
    Stop1 = 0;
    Stop2 = 1;
    SetColorFrame();
}

/*****************************************************************************!
 * Function : SlotStop1Selected
 *****************************************************************************/
void
GradientColorFrame::SlotStop1Selected
(
 QString			InString
)
{
    Stop1 = InString.toFloat();
    SetColorFrame();
}

/*****************************************************************************!
 * Function : SlotStop2Selected
 *****************************************************************************/
void
GradientColorFrame::SlotStop2Selected
(
 QString			InString
)
{
    Stop2 = InString.toFloat();
    SetColorFrame();
}
