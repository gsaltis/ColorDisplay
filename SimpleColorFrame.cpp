/*****************************************************************************
 FILE NAME      : SimpleColorFrame.cpp
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
#include <QSplitter>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SimpleColorFrame.h"

/*****************************************************************************!
 * Function : SimpleColorFrame
 *****************************************************************************/
SimpleColorFrame::SimpleColorFrame
() : QFrame()
{
    Initialize();
}

/*****************************************************************************!
 * Function : ~SimpleColorFrame
 *****************************************************************************/
SimpleColorFrame::~SimpleColorFrame
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
SimpleColorFrame::Initialize(void)
{
    labelFont = QFont("Arial", 9, QFont::Bold);
    selectedFrame = 1;
    setFrameStyle(QFrame::Box | QFrame::Sunken);
    SubWindowsCreate();
}

/*****************************************************************************!
 * Function : SubWindowsCreate
 *****************************************************************************/
void
SimpleColorFrame::SubWindowsCreate(void)
{
    QLabel*                             label;
    int					x0, x1, x2, x3, x4, y, sliderWidth;
    int					topMargin;
    int					buttonWidth;

    splitter = new QSplitter(this);
    splitter->setOrientation(Qt::Vertical);

    controlsFrame = new ControlsFrame();
    displayFrame = new DisplayFrame();

    splitter->addWidget(controlsFrame);
    splitter->addWidget(displayFrame);
    
    topMargin = 20;
    x0 = 10;
    x1 = x0 + 50;
    y = topMargin;
    sliderWidth = 256;
    buttonWidth = 80;
    x2 = x1 + sliderWidth + 10;
    x3 = x2 + 70;
    x4 = x0;

    //!
    label = new QLabel(controlsFrame);
    label->setFont(labelFont);
    label->move(x0, y);
    label->setAlignment(Qt::AlignRight);
    label->setText("Red");
    
    redSlider = new QSlider(controlsFrame);
    redSlider->move(x1, y);
    redSlider->resize(sliderWidth, 20);
    redSlider->setMinimum(0);
    redSlider->setMaximum(255);
    redSlider->setValue(0);
    redSlider->setOrientation(Qt::Horizontal);
    connect(redSlider, SIGNAL(sliderMoved(int)), this, SLOT(SlotRedChanged(int)));
    
    redEdit = new QLineEdit(controlsFrame);
    redEdit->move(x2, y);
    redEdit->resize(40, 20);
    redEdit->setText("0");

    lighterButton = new QPushButton(controlsFrame);
    lighterButton->move(x3, y);
    lighterButton->resize(buttonWidth, 20);
    lighterButton->setText("LIGHTER");
    connect(lighterButton, SIGNAL(pressed()), this, SLOT(SlotLighter()));

    //!
    y += 25;
    label = new QLabel(controlsFrame);
    label->setFont(labelFont);
    label->move(x0, y);
    label->setText("Green");
    label->setAlignment(Qt::AlignRight);

    greenSlider = new QSlider(controlsFrame);
    greenSlider->move(x1, y);
    greenSlider->resize(sliderWidth, 20);
    greenSlider->setMinimum(0);
    greenSlider->setMaximum(255);
    greenSlider->setOrientation(Qt::Horizontal);
    connect(greenSlider, SIGNAL(sliderMoved(int)), this, SLOT(SlotGreenChanged(int)));

    greenEdit = new QLineEdit(controlsFrame);
    greenEdit->move(x2, y);
    greenEdit->resize(40, 20);
    greenEdit->setText("0");

    darkerButton = new QPushButton(controlsFrame);
    darkerButton->move(x3, y);
    darkerButton->resize(buttonWidth, 20);
    darkerButton->setText("DARKER");
    connect(darkerButton, SIGNAL(pressed()), this, SLOT(SlotDarker()));
    
    //!
    y += 25;
    label = new QLabel(controlsFrame);
    label->setFont(labelFont);
    label->move(x0, y);
    label->setText("Blue");
    label->setAlignment(Qt::AlignRight);

    blueSlider = new QSlider(controlsFrame);
    blueSlider->move(x1, y);
    blueSlider->resize(sliderWidth, 20);
    blueSlider->setMinimum(0);
    blueSlider->setMaximum(255);
    blueSlider->setOrientation(Qt::Horizontal);
    connect(blueSlider, SIGNAL(sliderMoved(int)), this, SLOT(SlotBlueChanged(int)));

    blueEdit = new QLineEdit(controlsFrame);
    blueEdit->move(x2, y);
    blueEdit->resize(40, 20);
    blueEdit->setText("0");

    copyButton = new QPushButton(controlsFrame);
    copyButton->move(x3, y);
    copyButton->resize(buttonWidth, 20);
    copyButton->setText("COPY DOWN");
    connect(copyButton, SIGNAL(pressed()), this, SLOT(SlotCopy()));

    y += 30;
    label = new QLabel(controlsFrame);
    label->setFont(labelFont);
    label->move(x0, y);
    label->setText("Colors");
    label->setAlignment(Qt::AlignRight);

    colorHexEdit = new QLineEdit(controlsFrame);
    colorHexEdit->move(x2, y);
    colorHexEdit->resize(60, 20);
    colorHexEdit->setText("0");

    ColorNamesCombo = new QComboBox(this);
    ColorNamesCombo->move(x1, y);
    ColorNamesCombo->resize(sliderWidth, 20);
    ColorNamesCombo->addItems(QColor::colorNames());
    connect(ColorNamesCombo, SIGNAL(currentTextChanged(QString)),
	    this,            SLOT(SlotColorNameChanged(QString)));
    
    //!
    y += 30;
    colorFrame = new QFrame(controlsFrame);
    colorFrame->move(x4, y);
    colorFrame->resize(sliderWidth, 40);
    colorFrame->setFrameStyle(QFrame::Box | QFrame::Sunken);
    colorFrame->setAutoFillBackground(true);
    controlsFrame->SetColorFrame(colorFrame);
    
    //!
    y += 50;
    blockFrame = new QFrame(displayFrame);
    blockFrame->move(x0, 10);
    blockFrame->resize(100, 100);
    blockFrame->setFrameStyle(QFrame::Box | QFrame::Sunken);
    blockFrame->setAutoFillBackground(true);
    displayFrame->SetBlockFrame(blockFrame);
    
    colorFrame1 = new QFrame(blockFrame);
    colorFrame1->move(20, 0);
    colorFrame1->resize(100, (y-topMargin)/2);
    colorFrame1->setFrameStyle(QFrame::Box | QFrame::Sunken);
    colorFrame1->setAutoFillBackground(true);
    displayFrame->SetColorFrame1(colorFrame1);
    
    colorFrameSelect1 = new QRadioButton(blockFrame);
    colorFrameSelect1->move(5, 5);
    colorFrameSelect1->resize(14, 14);
    colorFrameSelect1->setChecked(true);
    colorFrameSelect1->setAutoFillBackground(true);
    displayFrame->SetColorFrameSelect1(colorFrameSelect1);
    connect(colorFrameSelect1, SIGNAL(pressed()), this, SLOT(SlotColorFrame1Selected()));

    //!
    colorFrame2 = new QFrame(blockFrame);
    colorFrame2->move(20, (y-topMargin)/2);
    colorFrame2->resize(100, (y-topMargin)/2);
    colorFrame2->setFrameStyle(QFrame::Box | QFrame::Sunken);
    colorFrame2->setAutoFillBackground(true);
    displayFrame->SetColorFrame2(colorFrame2);

    colorFrameSelect2 = new QRadioButton(blockFrame);
    colorFrameSelect2->move(5, 5);
    colorFrameSelect2->resize(14, 14);
    displayFrame->SetColorFrameSelect2(colorFrameSelect2);
    connect(colorFrameSelect2, SIGNAL(pressed()), this, SLOT(SlotColorFrame2Selected()));
    
    //!
    resetColor();
}

/*****************************************************************************!
 * Function : SlotRedChanged
 *****************************************************************************/
void
SimpleColorFrame::SlotRedChanged
(
 int                                    InValue
)
{
    redEdit->setText(QString("%1").arg(InValue));
    resetColor();
}

/*****************************************************************************!
 * Function : SlotGreenChanged
 *****************************************************************************/
void
SimpleColorFrame::SlotGreenChanged
(
 int                                    InValue
)
{
    greenEdit->setText(QString("%1").arg(InValue));
    resetColor();
}

/*****************************************************************************!
 * Function : SlotBlueChanged
 *****************************************************************************/
void
SimpleColorFrame::SlotBlueChanged
(
 int                                    InValue
)
{
    blueEdit->setText(QString("%1").arg(InValue));
    resetColor();
}

/*****************************************************************************!
 * Function : resetColor
 *****************************************************************************/
void
SimpleColorFrame::resetColor(void)
{
    QPalette				pal, pal2;
    int					r, g, b, r1, g1, b1;
    QString				s;
    
    r = redSlider->value();
    g = greenSlider->value();
    b = blueSlider->value();

    r1 = redEdit->text().toInt();
    g1 = greenEdit->text().toInt();
    b1 = blueEdit->text().toInt();

    s = QString("#%1%2%3").
	arg((short)r1, 2, 16, QChar('0')).
	arg((short)g1, 2, 16, QChar('0')).
	arg((short)b1, 2, 16, QChar('0'));

    colorHexEdit->setText(s.toUpper());
    SetColorFrame();

    if ( selectedFrame == 1 ) {
	pal2 = colorFrame1->palette();
    } else {
	pal2 = colorFrame2->palette();
    }
    pal2.setBrush(QPalette::Window, QBrush(QColor(r, g, b)));
    if ( selectedFrame == 1 ) {
	colorFrame1->setPalette(pal2);
    } else {
	colorFrame2->setPalette(pal2);
    }
    SendColorChange();
}

/*****************************************************************************!
 * Function : SlotLighter
 *****************************************************************************/
void
SimpleColorFrame::SlotLighter(void)
{
    QPalette				pal;
    int					r, g, b;
    QColor				c, c1;
    r = redSlider->value();
    g = greenSlider->value();
    b = blueSlider->value();

    c = QColor(r, g, b);
    c1 = c.lighter(110);
    r = c1.red();
    b = c1.blue();
    g = c1.green();

    redSlider->setValue(r);
    greenSlider->setValue(g);
    blueSlider->setValue(b);

    redEdit->setText(QString("%1").arg(r));
    greenEdit->setText(QString("%1").arg(g));
    blueEdit->setText(QString("%1").arg(b));

    SetColorFrame();
    resetColor();
    SendColorChange();
}

/*****************************************************************************!
 * Function : SlotDarker
 *****************************************************************************/
void
SimpleColorFrame::SlotDarker(void)
{
    QPalette				pal;
    int					r, g, b;
    QColor				c, c1;
    r = redSlider->value();
    g = greenSlider->value();
    b = blueSlider->value();

    c = QColor(r, g, b);
    c1 = c.darker(110);
    r = c1.red();
    b = c1.blue();
    g = c1.green();

    redSlider->setValue(r);
    greenSlider->setValue(g);
    blueSlider->setValue(b);

    redEdit->setText(QString("%1").arg(r));
    greenEdit->setText(QString("%1").arg(g));
    blueEdit->setText(QString("%1").arg(b));

    SetColorFrame();
    resetColor();
    SendColorChange();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SimpleColorFrame::resizeEvent
(
 QResizeEvent*                          in_event
)
{

    QSize                               size;    
    int                                 width, height;
    
    size   = in_event->size();
    width  = size.width();
    height = size.height();
    (void)height;

    splitter->resize(width, height);
    SetColorFrame();
}

/*****************************************************************************!
 * Function : SlotColorFrame1Selected
 *****************************************************************************/
void
SimpleColorFrame::SlotColorFrame1Selected(void)
{
    ColorFrame1SelectionChange();
    emit SignalColorFrame1Selected();
}

/*****************************************************************************!
 * Function : SlotColorFrame1SelectionChange
 *****************************************************************************/
void
SimpleColorFrame::SlotColorFrame1ForceSelect(void)
{
    colorFrameSelect1->setChecked(true);
    ColorFrame1SelectionChange();
}

/*****************************************************************************!
 * Function : ColorFrame1SelectionChange
 *****************************************************************************/
void
SimpleColorFrame::ColorFrame1SelectionChange(void)
{
    colorFrameSelect1->setChecked(false);
    selectedFrame = 1;
    ColorSelected(colorFrame1);
    copyButton->setText("COPY DOWN");
    SetColorFrame();
}

/*****************************************************************************!
 * Function : SlotColorFrame2Selected
 *****************************************************************************/
void
SimpleColorFrame::SlotColorFrame2Selected(void)
{
    ColorFrame2SelectionChange();
    emit SignalColorFrame2Selected();
}

/*****************************************************************************!
 * Function : SlotColorFrame2SelectionChange
 *****************************************************************************/
void
SimpleColorFrame::SlotColorFrame2ForceSelect(void)
{
    colorFrameSelect2->setChecked(true);
    ColorFrame2SelectionChange();
}

/*****************************************************************************!
 * Function : ColorFrame2SelectionChange
 *****************************************************************************/
void
SimpleColorFrame::ColorFrame2SelectionChange(void)
{
    colorFrameSelect1->setChecked(false);
    selectedFrame = 2;
    ColorSelected(colorFrame2);
    copyButton->setText("COPY UP");
    SetColorFrame();
}

/*****************************************************************************!
 * Function : ColorSelected
 *****************************************************************************/
void
SimpleColorFrame::ColorSelected
(
 QFrame*			InFrame
)
{
    QPalette			pal;
    QBrush			brush;
    QColor			color;
    QString			s;
    int				r, g, b;
    pal = InFrame->palette();
    brush = pal.brush(QPalette::Window);
    color = brush.color();
    r = color.red();
    b = color.blue();
    g = color.green();

    redSlider->setValue(r);
    greenSlider->setValue(g);
    blueSlider->setValue(b);
    redEdit->setText(QString("%1").arg(r));
    greenEdit->setText(QString("%1").arg(g));
    blueEdit->setText(QString("%1").arg(b));

    s = QString("#%1%2%3").
	arg(r, 2, 16, QChar('0')).
	arg(g, 2, 16, QChar('0')).
	arg(b, 2, 16, QChar('0'));
    colorHexEdit->setText(s.toUpper());
    pal = colorFrame->palette();
    pal.setBrush(QPalette::Window, QBrush(QColor(r, g, b)));
    colorFrame->setPalette(pal);
}

/*****************************************************************************!
 * Funtion : SlotCopy
 *****************************************************************************/
void
SimpleColorFrame::SlotCopy(void)
{
    if ( selectedFrame == 1 ) {
	CopyTo(colorFrame1, colorFrame2);
	colorFrameSelect2->setChecked(true);
	SlotColorFrame2Selected();
	
    } else {
	CopyTo(colorFrame2, colorFrame1);
	colorFrameSelect1->setChecked(true);
	SlotColorFrame1Selected();
    }
    SetColorFrame();
    SendColorChange();
}

/*****************************************************************************!
 * Function : CopyTo
 *****************************************************************************/
void
SimpleColorFrame::CopyTo
(
 QFrame*                                InFrame1, 
 QFrame*                                InFrame2
)
{
    QPalette				pal;
    QBrush				brush;
    
    pal = InFrame1->palette();
    brush = pal.brush(QPalette::Window);

    pal = InFrame2->palette();
    pal.setBrush(QPalette::Window, brush);
    InFrame2->setPalette(pal);
}

/*****************************************************************************!
 * Function : SetColorFrame
 *****************************************************************************/
void
SimpleColorFrame::SetColorFrame(void)
{
    int					r, g, b;
    QPalette				pal;
    
    r = redSlider->value();
    g = greenSlider->value();
    b = blueSlider->value();

    pal = colorFrame->palette();
    pal.setBrush(QPalette::Window, QBrush(QColor(r, g, b)));
    colorFrame->setPalette(pal);
}    

/*****************************************************************************!
 * Function : SlotColorChanged
 *****************************************************************************/
void
SimpleColorFrame::SlotColorChanged
(
 QColor                                 Color1, 
 QColor                                 Color2
)
{
    ResetFrameColor(colorFrame1, Color1);
    ResetFrameColor(colorFrame2, Color2);
    SetColorFrame();
    if ( selectedFrame == 1 ) {
	ResetControls(Color1);
    } else {
	ResetControls(Color2);
    }
}

/*****************************************************************************!
 * Function : SendColorChange
 *****************************************************************************/
void
SimpleColorFrame::SendColorChange(void)
{
    QColor				c1, c2;

    c1 = colorFrame1->palette().brush(QPalette::Window).color();
    c2 = colorFrame2->palette().brush(QPalette::Window).color();

    emit SignalColorsChanged(c1, c2);
}

/*****************************************************************************!
 * Function : ResetFrameColor 
 *****************************************************************************/
void
SimpleColorFrame::ResetFrameColor
(
 QFrame*				InFrame,
 QColor					InColor
)
{
    QPalette				pal = InFrame->palette();
    pal.setBrush(QPalette::Window, QBrush(InColor));
    InFrame->setPalette(pal);
}

/*****************************************************************************!
 * Function : ResetControls
 *****************************************************************************/
void
SimpleColorFrame::ResetControls
(
 QColor                                 InColor
)
{
    int					r, g, b;

    r = InColor.red();
    g = InColor.green();
    b = InColor.blue();

    redSlider->setValue(r);
    blueSlider->setValue(b);
    greenSlider->setValue(g);
}

/*****************************************************************************!
 * Function : SlotColorNameChanged
 *****************************************************************************/
void
SimpleColorFrame::SlotColorNameChanged
(
 QString                                InColorName
)
{
    QColor				c(InColorName);
	
    redSlider->setValue(c.red());
    blueSlider->setValue(c.blue());
    greenSlider->setValue(c.green());
    resetColor();
}
