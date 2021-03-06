/****************************************************************
**
** Definition of CannonField class, Qt tutorial 8
**
****************************************************************/

#ifndef CANNON_H
#define CANNON_H

#include <QWidget>


class CannonField : public QWidget
{
    Q_OBJECT
public:
    CannonField( QWidget *parent=nullptr );
    ~CannonField();

    int angle() const { return ang; }
    QSizePolicy sizePolicy() const;

public slots:
    void setAngle( int degrees );

signals:
    void angleChanged( int );

protected:
    void paintEvent( QPaintEvent * );

private:
    int ang;
};


#endif // CANNON_H

