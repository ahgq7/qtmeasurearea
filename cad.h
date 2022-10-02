#ifndef CAD_H
#define CAD_H

#include <QWidget>
#include <QPainter>

class Cad : public QWidget
{
    Q_OBJECT
public:
    explicit Cad(QWidget *parent = nullptr, int wsize=1000, int hsize=1000);
    QPixmap *mPix;
    QPainter *painter;

signals:

protected:

};

#endif // CAD_H
