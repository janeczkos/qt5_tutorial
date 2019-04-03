/****************************************************************
**
** Implementation CannonField class, Qt tutorial 8
**
****************************************************************/

#include "cannon.h"
#include <qpainter.h>


CannonField::CannonField( QWidget *parent )
        : QWidget( parent )
{
    ang = 45;
    setAutoFillBackground(true);
    setPalette( QPalette( QColor( 250, 250, 200) ) );
}

CannonField::~CannonField()
{

}

void CannonField::setAngle( int degrees )
{
    if ( degrees < 5 )
        degrees = 5;
    if ( degrees > 70 )
        degrees = 70;
    if ( ang == degrees )
        return;
    ang = degrees;
    repaint();
    emit angleChanged( ang );
}


void CannonField::paintEvent( QPaintEvent * )
{
    QString s = "Angle = " + QString::number( ang );
    QPainter p( this );
    p.drawText( 200, 200, s );
}


QSizePolicy CannonField::sizePolicy() const
{
    return QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
}
