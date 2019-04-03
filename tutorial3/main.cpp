#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QBoxLayout>


int main( int argc, char **argv )
{
    QApplication a( argc, argv );

    QWidget *window = new QWidget;
    window->resize( 200, 120);
    QHBoxLayout *box = new QHBoxLayout;

    QPushButton *quit = new QPushButton( "Quit", window );

    box->addWidget(quit);

    quit->setFont( QFont( "Times", 18, QFont::Bold ) );

    QObject::connect( quit, SIGNAL(clicked()), &a, SLOT(quit()) );

    window->setLayout(box);
    window->show();

    return a.exec();
}
