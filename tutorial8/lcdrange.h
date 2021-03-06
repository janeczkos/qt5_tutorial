#ifndef LCDRANGE_H
#define LCDRANGE_H

#include <QWidget>

class QSlider;

class LCDRange : public QWidget
{
    Q_OBJECT
public:
    LCDRange( QWidget *parent=0);

    int value() const;

public slots:
    void setValue( int );
    void setRange( int minVal, int maxVal );

signals:
    void valueChanged( int );

private:
    QSlider *slider;

};


#endif ///LCDRANGE_H
