#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QFont>

#include <QVBoxLayout>
#include <QGridLayout>

class LCDRange : public QWidget
{
public:
    LCDRange( QWidget *parent=0);
};

LCDRange::LCDRange( QWidget *parent )
        : QWidget( parent)
{
    QLCDNumber *lcd  = new QLCDNumber( 2, this );
    QSlider * slider = new QSlider( Qt::Horizontal, this );
    slider->setRange( 0, 99 );
    slider->setValue( 0 );
    connect( slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)) );

    QVBoxLayout *box = new QVBoxLayout();
    box->addWidget(lcd);
    box->addWidget(slider);
    this->setLayout(box);
 }

class MyWidget : public QWidget
{
public:
    MyWidget( QWidget *parent=0);
};

MyWidget::MyWidget( QWidget *parent )
            : QWidget( parent)
    {
    QPushButton *quit = new QPushButton( "Quit", this );
    quit->setFont( QFont( "Times", 18, QFont::Bold ) );

    connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );

    QGridLayout *grid   = new QGridLayout();

    for( int r = 0 ; r < 4 ; r++ )
    {
        for( int c = 0 ; c < 4 ; c++ )
        {
             grid->addWidget( new LCDRange(),r,c );
        }
    }

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addItem(grid);
    this->setLayout(layout);
}

int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    MyWidget *w = new MyWidget;

    w->show();
    return a.exec();
}
