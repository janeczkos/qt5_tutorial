#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QFont>

#include <QVBoxLayout>
#include <QGridLayout>

#include "lcdrange.h"
#include "cannon.h"

class MyWidget : public QWidget
{
public:
    MyWidget( QWidget *parent=nullptr);
    ~MyWidget();
};

MyWidget::~MyWidget()
{

}

MyWidget::MyWidget( QWidget *parent )
            : QWidget( parent)
    {
    QPushButton *quit = new QPushButton( "Quit", this );
    quit->setFont( QFont( "Times", 18, QFont::Bold ) );

    connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );



    LCDRange *angle = new LCDRange();
    angle->setRange(5, 70);

    CannonField *cannonField= new CannonField( this );

    connect( angle, SIGNAL(valueChanged(int)),
                cannonField, SLOT(setAngle(int)) );
       connect( cannonField, SIGNAL(angleChanged(int)),
                angle, SLOT(setValue(int)) );

    QGridLayout *grid   = new QGridLayout();

    grid->addWidget( quit, 0, 0);
    grid->addWidget( angle, 1, 0, Qt::AlignTop);
    grid->addWidget( cannonField, 1, 1);
    grid->setColumnStretch( 1, 10 );
    this->setLayout(grid);

    angle->setValue( 60 );
    angle->setFocus();
}

int main( int argc, char **argv )
{
    //QApplication::setColorSpec( QApplication::CustomColor );
    QApplication a( argc, argv );

    MyWidget *w = new MyWidget;
    w->setGeometry( 100, 100, 500, 355 );

    w->show();
    return a.exec();
}
