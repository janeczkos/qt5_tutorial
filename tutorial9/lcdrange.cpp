#include "lcdrange.h"

#include <QSlider>
#include <QLCDNumber>
#include <QVBoxLayout>

LCDRange::LCDRange( QWidget *parent )
        : QWidget( parent)
{
    QLCDNumber *lcd     = new QLCDNumber( 2, this );
    slider              = new QSlider( Qt::Horizontal, this );
    QVBoxLayout *box    = new QVBoxLayout();

    slider->setRange( 0, 99 );
    slider->setValue( 0 );

    box->addWidget(lcd);
    box->addWidget(slider);
    this->setLayout(box);

    connect( slider, SIGNAL(valueChanged(int)),lcd, SLOT(display(int)) );
    connect( slider, SIGNAL(valueChanged(int)), SIGNAL(valueChanged(int)) );
 }

void LCDRange::setRange( int minVal, int maxVal )
{
    if ( minVal < 0 || maxVal > 99 || minVal > maxVal ) {
      qWarning( "LCDRange::setRange(%d,%d)\n"
               "\tRange must be 0..99\n"
               "\tand minVal must not be greater than maxVal",
               minVal, maxVal );
      return;
    }
    slider->setRange( minVal, maxVal );
}

int LCDRange::value() const
{
    return slider->value();
}

void LCDRange::setValue( int value )
{
    slider->setValue( value );
}
