#include "cad.h"
#include "qlabel.h"

Cad::Cad(QWidget *parent, int wsize, int hsize)
    : QWidget{parent}
{
    QLabel *label = new QLabel(this);
    int i;

    mPix = new QPixmap(wsize,hsize);
    mPix->fill(Qt::white);

    painter = new QPainter(mPix);
    QFont font = painter->font() ;
    font.setPointSize(font.pointSize()*1.4);
    painter->setFont(font);

    QPen pen;
    pen.setWidth(2);
    pen.setColor(Qt::black);

    painter->setPen(pen);
    painter->drawLine(50, hsize - 50, wsize - 50 , hsize - 50);

    painter->drawLine(75, hsize - 25, 100 , hsize - 25);
    painter->drawLine(90, hsize - 37, 100, hsize - 25);
    painter->drawLine(90, hsize - 13, 100, hsize - 25);
    painter->drawText(60, hsize - 22, tr("x"));

    painter->drawLine(wsize - 60, hsize - 63, wsize - 50, hsize - 50);
    painter->drawLine(wsize - 60, hsize - 37, wsize - 50, hsize - 50);
    /* */
    painter->drawLine(50, hsize-50, 50, 50);

    painter->drawLine(25, hsize - 75, 25 , hsize - 100);
    painter->drawLine(13, hsize - 87, 25, hsize-100);
    painter->drawLine(37, hsize - 87, 25, hsize-100);
    painter->drawText(22, hsize - 60, tr("y"));

    painter->drawLine(63, 60, 50, 50);
    painter->drawLine(37, 60, 50, 50);

    font.setPointSize(font.pointSize()*0.9);
    painter->setFont(font);

    for(i=100;i<wsize-50;i=i+50){
        if((i/50)%2 == 0)
            painter->drawLine(i, hsize - 50, i, hsize - 55);
        else
            painter->drawLine(i, hsize - 50, i, hsize - 60);
        painter->drawText(i-15, hsize - 38, QString::number(i-50));
    }

    for(i=100;i<hsize-50;i=i+50){
        if((i/50)%2 == 0)
            painter->drawLine(50, hsize - i, 55, hsize - i);
        else
            painter->drawLine(50, hsize - i, 60, hsize - i);
        if(i==100){}
        else
            painter->drawText(20, hsize-i+5, QString::number(i-50));
    }


    label->setPixmap(*mPix);
}

