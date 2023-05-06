/*****************************************************************************
 FILE NAME      : GradientColorFrame.h
 DATE           : March 10 2017
 PROJECT        : HMIModel
 COPYRIGHT      : Copyright (C) 2017 by Utility Relay Company
******************************************************************************/
#ifndef _gradientcolorframe_h_
#define _gradientcolorframe_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QFrame>
#include <QComboBox>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SimpleColorFrame.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : GradientColorFrame
 *****************************************************************************/
class GradientColorFrame : public SimpleColorFrame
{
    Q_OBJECT;

 //! Constructors
 public :
    GradientColorFrame          ();

 //! Destructor
 public :
    ~GradientColorFrame         ();

 //! Protected Data
 protected :

 //! Public Data
 public :
    enum {
	Horizontal,
	Vertical,
	Diagonal
    };
    
 //! Public Methods
 public :

 //! Public Actions
 public :

 //! Public Slots
 public slots :
    void			SlotDirectionSelected	(int InDirection);
    void			SlotStop1Selected	(QString InStopString);
    void			SlotStop2Selected	(QString InStopString);
    
 //! Public Signals
 signals :

 //! Private Data
 private :
    int				Direction;
    QComboBox*			DirectionSelection;
    QComboBox*			Stop1Selection;
    QComboBox*			Stop2Selection;
    qreal			Stop1;
    qreal			Stop2;
    
 //! Private Methods
 private :
    void			SetColorFrame		(void)  override;
    void			Initialize		(void);
    void			SubWindowsCreate	(void);
};

#endif /* _gradientcolorframe_h_*/
