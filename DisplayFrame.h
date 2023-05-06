/*****************************************************************************
 FILE NAME      : DisplayFrame.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _displayframe_h_
#define _displayframe_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QRadioButton>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : DisplayFrame
 *****************************************************************************/
class DisplayFrame : public QFrame
{
    Q_OBJECT;

 //! Constructors
 public :
    DisplayFrame                ();

 //! Destructor
 public :
    ~DisplayFrame               ();

 //! Protected Data
 protected :

 //! Public Data
 public :

 //! Public Methods
 public :
    void                        Initialize              (void);
    QFrame*                     GetBlockFrame           (void);
    void                        SetBlockFrame           (QFrame* InBlockFrame);
    QFrame*                     GetColorFrame1          (void);
    void                        SetColorFrame1          (QFrame* InColorFrame1);
    QFrame*                     GetColorFrame2          (void);
    void                        SetColorFrame2          (QFrame* InColorFrame2);
    QRadioButton*               GetColorFrameSelect1    (void);
    void                        SetColorFrameSelect1    (QRadioButton* InColorFrameSelect1);
    QRadioButton*               GetColorFrameSelect2    (void);
    void                        SetColorFrameSelect2    (QRadioButton* InColorFrameSelect2);

 //! Public Actions
 public :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Private Data
 private :
    QFrame*                     BlockFrame;
    QFrame*                     colorFrame1;
    QFrame*                     colorFrame2;
    QRadioButton*               colorFrameSelect1;
    QRadioButton*               colorFrameSelect2;

 //! Private Methods
 private :
    void                        resizeEvent             (QResizeEvent* event);

};

#endif /* _displayframe_h_*/
