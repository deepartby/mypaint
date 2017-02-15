#include "circle.h"
#include <QPainter>

Circle::Circle(QPointF point,QColor color,int id, QObject *parent) :
    Figure(point,parent)
{
    this->color = color;
    this->id = id;
    Q_UNUSED(point)
}
Circle::Circle()
{
    this->color = Qt::white;
}

Circle::Circle(const Circle &elem)
{
    color = elem.color;
}
Circle Circle::operator =(Circle& elem){
    color = elem.color;
    return *this;
}
Circle::~Circle()
{

}

// Реализуем метод отрисовки
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, 2));
    painter->setBrush(QBrush(this->color));

    painter->drawEllipse( endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                          endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                          qAbs(endPoint().x() - startPoint().x()),
                          qAbs(endPoint().y() - startPoint().y()));
    //painter->setFlag(QGraphicsItem::ItemIsMovable,true);
    //painter->setFlag(QGraphicsItem::ItemIsSelectable,true);
    //painter->setAcceptDrops(true);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
