/*****************************************************************************
 FILE NAME      : ControlsFrame.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _controlsframe_h_
#define _controlsframe_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : ControlsFrame
 *****************************************************************************/
class ControlsFrame : public QFrame
{
    Q_OBJECT;

 //! Constructors
 public :
    ControlsFrame               ();

 //! Destructor
 public :
    ~ControlsFrame              ();

 //! Protected Data
 protected :

 //! Public Data
 public :

 //! Public Methods
 public :
    void                        Initialize              (void);
    QFrame*                     GetColorFrame           (void);
    void                        SetColorFrame           (QFrame* InColorFrame);

 //! Public Actions
 public :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Private Data
 private :
    QFrame*                     colorFrame;

 //! Private Methods
 private :
    void                        resizeEvent             (QResizeEvent* event);

};

#endif /* _controlsframe_h_*/
