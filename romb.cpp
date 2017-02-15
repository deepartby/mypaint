#include "romb.h"
#include <QPainter>

Romb::Romb(QPointF point, QColor color, int id, QObject *parent) :
    Figure(point,parent)
{
    this->color = color;
    this->id = id;
    Q_UNUSED(point)
}
Romb::Romb()
{
    this->color = Qt::white;
}

Romb::Romb(const Romb &elem)
{
    color = elem.color;
}
Romb Romb::operator =(Romb& elem){
    color = elem.color;
    return *this;
}

Romb::~Romb()
{

}
// Реализуем метод отрисовки
void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, 2));
    painter->setBrush(QBrush(this->color));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF(endPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2))
                << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), endPoint().y())
                << QPointF(startPoint().x(), startPoint().y() + (endPoint().y() > startPoint().y() ? + 1 : - 1)*
                           abs((endPoint().y() - startPoint().y())/2));

    painter->drawPolygon(polygon);


    Q_UNUSED(option)
    Q_UNUSED(widget)
}
