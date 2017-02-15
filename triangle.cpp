#include "triangle.h"
#include <QPainter>

Triangle::Triangle(QPointF point,QColor color,int id, QObject *parent) :
    Figure(point,parent)
{
    this->color = color;
    this->id = id;
    Q_UNUSED(point)
}
Triangle::Triangle()
{
    this->color = Qt::white;
}

Triangle::Triangle(const Triangle &elem)
{
    color = elem.color;
}
Triangle Triangle::operator =(Triangle& elem){
    color = elem.color;
    return *this;
}
Triangle::~Triangle()
{

}

// Реализуем метод отрисовки
void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, 2));
    painter->setBrush(QBrush(this->color));

    QPolygonF polygon;

    polygon << QPointF(startPoint().x() + (endPoint().x() > startPoint().x() ? + 1 : - 1)*
                           abs((endPoint().x() - startPoint().x())/2), startPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? endPoint().x() : startPoint().x(),
                           endPoint().y())
                << QPointF((endPoint().x() > startPoint().x()) ? startPoint().x() : endPoint().x(),
                           endPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
