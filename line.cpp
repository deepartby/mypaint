#include "Line.h"
#include <QPainter>

Line::Line(QPointF point,QColor color,int sizeP,int id, QObject *parent) :
    Figure(point,parent)
{
    this->id = id;
    this->color = color;
    this->sizeP = sizeP;
    Q_UNUSED(point)
}
Line::Line()
{
    this->color = Qt::white;
}

Line::Line(const Line &elem)
{
    color = elem.color;
}
Line Line::operator =(Line& elem){
    color = elem.color;
    return *this;
}
Line::~Line()
{

}

// Реализуем метод отрисовки
void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, sizeP));
    painter->setBrush(QBrush(this->color));
    painter->drawLine( startPoint(), endPoint());
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
