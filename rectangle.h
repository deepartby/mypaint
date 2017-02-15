#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Rectangle : public Figure
{
    Q_OBJECT

public:
    Rectangle();
    Rectangle(const Rectangle& elem);
    Rectangle operator=(Rectangle& elem);
    explicit Rectangle(QPointF point,QColor color,int id, QObject *parent = 0);
    ~Rectangle();

private:
    QColor color;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // Rectangle_H


