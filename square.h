#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Square : public Figure
{
    Q_OBJECT

public:
    Square();
    Square(const Square& elem);
    Square operator=(Square& elem);
    explicit Square(QPointF point,QColor color,int id, QObject *parent = 0);
    ~Square();
   /*bool operator==(const Square& obj){
        return dynamic_cast<Figure*>(this) == dynamic_cast<Figure*>(obj);
    }*/
private:
    QColor color;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H


