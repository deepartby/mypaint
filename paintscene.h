#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QList>

#include "figure.h"
#include "romb.h"
#include "triangle.h"
#include "exception.h"


class paintScene : public QGraphicsScene
{
    // Свойство текущего типа используемой фигуры
    Q_OBJECT
    Q_PROPERTY(  int typeFigure
                       READ typeFigure
                       WRITE setTypeFigure
                       NOTIFY typeFigureChanged )

public:

    QList<Figure*> *list_item;
    QList<Figure*>::iterator iter;

    explicit paintScene(QColor color,QObject *parent = 0);
    ~paintScene();
    int typeFigure() const;                 // Возвращение текущего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    QColor getColor();
    void ctrl_z();
    // Перечисление типов используемых фигур
    enum FigureTypes {
           RectangleType,
           SquareType,
           RombType,
           TriangleType,
           Mousepen,
           EllipseType,
           right,
           left,
           lineType,
           objdelete,
           erase
       };
signals:
    void typeFigureChanged();               // Сигнал об изменении типа текущей ф
private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    QGraphicsItem *curItem;
    QColor color;
    int sizeP;
    int figureId;
private:
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    int m_typeFigure;   // текущий тип фигуры
private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
public:
    Figure *tempFigure;
    int getId();
public slots:
    void SetColor(QColor);
    void SetSizePen(int);
};

#endif // PAINTSCENE_H
