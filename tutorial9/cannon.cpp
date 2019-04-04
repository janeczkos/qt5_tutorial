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
    QPainter p( this );
    p.setBrush( Qt::blue );
    p.setPen( Qt::NoPen );

    p.translate( 0, rect().bottom() );
    p.drawPie( QRect(-35, -35, 70, 70), 0, 90*16 );
    p.rotate( -ang );
    p.drawRect( QRect(33, -4, 15, 8) );
}


QSizePolicy CannonField::sizePolicy() const
{
    return QSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
}
