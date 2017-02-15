#ifndef ROMB_H
#define ROMB_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Romb : public Figure
{
    Q_OBJECT

public:
    Romb();
    Romb(const Romb& elem);
    Romb operator=(Romb& elem);
    explicit Romb(QPointF point, QColor color, int id, QObject *parent = 0);
    ~Romb();
private:
    QColor color;
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
