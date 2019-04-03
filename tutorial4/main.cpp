#include <QApplication>
#include <QPushButton>
#include <QFont>

class MyWidget : public QWidget
{
public:
    MyWidget( QWidget *parent=0 );
};


MyWidget::MyWidget( QWidget *parent)
        : QWidget( parent)
{
    setMinimumSize( 200, 120 );
    setMaximumSize( 200, 120 );

    QPushButton *quit = new QPushButton( "Quit", this );
    quit->setGeometry( 62, 40, 75, 30 );
    quit->setFont( QFont( "Times", 18, QFont::Bold ) );

    connect( quit, SIGNAL(clicked()), qApp, SLOT(quit()) );
}


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    MyWidget *w = new MyWidget;
    w->setGeometry( 100, 100, 200, 120 );

    w->show();
    return a.exec();
}
