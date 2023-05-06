/*****************************************************************************
 FILE NAME      : SimpleColorFrame.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _simplecolorframe_h_
#define _simplecolorframe_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QSlider>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QSplitter>
#include <QComboBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ControlsFrame.h"
#include "DisplayFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : SimpleColorFrame
 *****************************************************************************/
class SimpleColorFrame : public QFrame
{
    Q_OBJECT;

 //! Constructors
 public :
    SimpleColorFrame            ();

 //! Destructor
 public :
    ~SimpleColorFrame           ();

 //! Protected Data
 protected :
    QSlider*                    redSlider;
    QSlider*                    greenSlider;
    QSlider*                    blueSlider;
    QLineEdit*                  redEdit;
    QLineEdit*                  greenEdit;
    QLineEdit*                  blueEdit;
    QLineEdit*                  colorHexEdit;
    QFrame*                     colorFrame;
    QPushButton*                lighterButton;
    QPushButton*                darkerButton;
    QPushButton*                copyButton;
    QFrame*                     blockFrame;
    QFrame*			colorFrame1;
    QFrame*			colorFrame2;
    QRadioButton*		colorFrameSelect1;
    QRadioButton*		colorFrameSelect2;
    int				selectedFrame;
    QFont                       labelFont;
    ControlsFrame*		controlsFrame;
    DisplayFrame*		displayFrame;
    QSplitter*			splitter;
    QComboBox*			ColorNamesCombo;
    
 //! Protected Methods
 protected :
    void                        SubWindowsCreate        (void);
    void                        resetColor              (void);
    void                        resizeEvent             (QResizeEvent* event);
    void			ColorSelected		(QFrame* InFrame);
    void                        CopyTo                  (QFrame* InFrame1, QFrame* InFrame2);
    virtual void		SetColorFrame		(void);
    void			ResetFrameColor		(QFrame* InFrame, QColor InColor);
    void			SendColorChange		(void);
    
 //! Public Data
 public :

 //! Public Methods
 public :
    void                        Initialize              (void);

 //! Public Actions
 public :

 //! Public Slots
 public slots :
    void                        SlotRedChanged          (int InValue);
    void                        SlotGreenChanged        (int InValue);
    void                        SlotBlueChanged         (int InValue);
    void                        SlotLighter             (void);
    void                        SlotDarker              (void);
    void			SlotCopy		(void);
    void			SlotColorFrame2Selected	(void);
    void			SlotColorFrame1Selected	(void);
    void			SlotColorFrame1ForceSelect(void);
    void			SlotColorFrame2ForceSelect(void);
    void                        SlotColorChanged        (QColor Color1, QColor Color2);
    void                        SlotColorNameChanged    (QString InColorName);
    
 //! Public Signals
 signals :
    void                        SignalColorsChanged     (QColor Color1, QColor Color2);
    void			SignalColorFrame1Selected(void);
    void			SignalColorFrame2Selected(void);

 //! Private Data
 private :
    
 //! Private Methods
 private :
    void                        ResetControls           (QColor InColor);
    void			ColorFrame1SelectionChange(void);
    void			ColorFrame2SelectionChange(void);
};

#endif /* _simplecolorframe_h_*/
