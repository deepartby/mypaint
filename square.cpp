#include "square.h"
#include <QPainter>

Square::Square(QPointF point,QColor color,int id, QObject *parent) :
    Figure(point,parent)
{
    this->color = color;
    this->id = id;
    Q_UNUSED(point)
}
Square::Square()
{
    this->color = Qt::white;
}

Square::Square(const Square &elem)
{
    color = elem.color;
}
Square Square::operator =(Square& elem){
    color = elem.color;
    return *this;
}
Square::~Square()
{

}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(this->color, 2));
    painter->setBrush(QBrush(this->color));

    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                    endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                    qAbs(endPoint().y() - startPoint().y()),
                    qAbs(endPoint().y() - startPoint().y()));
    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

