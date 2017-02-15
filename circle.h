#ifndef CIRCLE_H
#define CIRCLE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Circle : public Figure
{
    Q_OBJECT

public:
    Circle();
    Circle(const Circle& elem);
    Circle operator=(Circle& elem);
    explicit Circle(QPointF point,QColor color,int id, QObject *parent = 0);
    ~Circle();

private:
    // Для Круга реализуем только саму отрисовку
    QColor color;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CIRCLE_H
