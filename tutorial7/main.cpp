#include <QApplication>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QFont>

#include <QVBoxLayout>
#include <QGridLayout>

#include "lcdrange.h"

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

    QGridLayout *grid   = new QGridLayout();

    LCDRange *previous = nullptr;
    for( int r = 0 ; r < 4 ; r++ )
    {
        for( int c = 0 ; c < 4 ; c++ )
        {
            LCDRange *lr = new LCDRange();
            grid->addWidget( lr,r,c );
            if ( previous )
            {
                connect( lr, SIGNAL(valueChanged(int)), previous, SLOT(setValue(int)) );
            }
            previous = lr;
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
