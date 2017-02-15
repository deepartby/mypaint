#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Line : public Figure
{
    Q_OBJECT

public:
    Line();
    Line(const Line& elem);
    Line operator=(Line& elem);
    explicit Line(QPointF point,QColor color, int sizeP,int id, QObject *parent = 0);
    /*bool operator==(const Line& obj){
        return dynamic_cast<Figure*>(this) == dynamic_cast<Figure*>(obj);
    }*/
    void setSize(int sizeP);
    ~Line();

private:
    QColor color;
    int sizeP;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINE_H
