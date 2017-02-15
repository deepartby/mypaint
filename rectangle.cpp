#include "rectangle.h"
#include <QPainter>

Rectangle::Rectangle(QPointF point,QColor color,int id, QObject *parent) :
    Figure(point,parent)
{
    this->color = color;
    this->id = id;
    Q_UNUSED(point)
}
Rectangle::Rectangle()
{
    this->color = Qt::white;
}

Rectangle::Rectangle(const Rectangle &elem)
{
    color = elem.color;
}
Rectangle Rectangle::operator =(Rectangle& elem){
    color = elem.color;
    return *this;
}
Rectangle::~Rectangle()
{

}

// Реализуем метод отрисовки
void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, 2));
    painter->setBrush(QBrush(this->color));

   QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

   painter->drawRect(rect);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

