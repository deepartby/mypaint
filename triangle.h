
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Triangle : public Figure
{
    Q_OBJECT

public:
    Triangle();
    Triangle(const Triangle& elem);
    Triangle operator=(Triangle& elem);
    explicit Triangle(QPointF point,QColor color,int id, QObject *parent = 0);
    /*bool operator==(const Triangle& obj){
        return dynamic_cast<Figure*>(this) == dynamic_cast<Figure*>(obj);
    }*/
    ~Triangle();

private:
    QColor color;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRIANGLE_H
