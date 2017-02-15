#include "paintScene.h"
#include "figure.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "rectangle.h"
#include "mainwindow.h"
#include "line.h"

#include <QGraphicsItem>
#include <QDebug>

paintScene::paintScene(QColor color, QObject *parent) : QGraphicsScene(parent)
{

    this->color = color;
    this->sizeP = 5;
    list_item = new QList<Figure*>();
    figureId = 0;

}

paintScene::~paintScene()
{}

int paintScene::typeFigure() const
{
    return m_typeFigure;
}
void paintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}
int paintScene::getId(){
    figureId++;
    return figureId;
}

/*void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    this->setPos(mapToScene(event->pos()));
}*/

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_typeFigure!=left && m_typeFigure!=right && m_typeFigure!=objdelete)
    switch(m_typeFigure){
    case Mousepen:
    {
        // Отрисовываем линии с использованием предыдущей координаты
     addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(this->color,this->sizeP,Qt::SolidLine,Qt::RoundCap));
        // Обновляем данные о предыдущей координате
        previousPoint = event->scenePos();
    }break;
    case erase:
    {
        // Отрисовываем линии с использованием предыдущей координаты

        addLine(previousPoint.x(),
                previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(Qt::white,this->sizeP,Qt::SolidLine,Qt::RoundCap));
        // Обновляем данные о предыдущей координате
        previousPoint = event->scenePos();
    } break;
    default:
    {
        /* Устанавливаем конечную координату положения мыши
         * в текущую отрисовываемую фигуру
         * */
        tempFigure->setEndPoint(event->scenePos());
        /* Обновляем содержимое сцены,
        * необходимо для устранения артефактов при отрисовке фигур
        * */
        this->update();
    }break;
  }
}
/* Как только нажали кнопку мыши, создаём фигуру одного из трёх типов
 * и помещаем её на сцену, сохранив указатель на неё в переменной
 * tempFigure
 * */
void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {

        Square *item = new Square(event->scenePos(),this->color, this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        list_item->push_front(dynamic_cast<Square*>(item));
        this->addItem(dynamic_cast<Figure*>(tempFigure));
        break;
    }
    case RectangleType: {

        Rectangle *item = new Rectangle(event->scenePos(),this->color, this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        list_item->push_front(dynamic_cast<Rectangle*>(tempFigure));
        this->addItem(dynamic_cast<Figure*>(tempFigure));
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos(), this->color,this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        list_item->push_front(dynamic_cast<Romb*>(tempFigure));
        this->addItem(item);
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos(),this->color,this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        list_item->push_front(dynamic_cast<Triangle*>(tempFigure));
        this->addItem(dynamic_cast<Figure*>(item));
        break;
    }
    case Mousepen:{
        paintScene::previousPoint = event->scenePos();//сохраняем координаты предыдущей точки
    }break;
    case erase:{
        // Сохраняем координаты точки нажатия
        paintScene::previousPoint = event->scenePos();
    }break;
    case EllipseType: {
        {
        Circle *item = new Circle(event->scenePos(),this->color,this->getId());
        item->setPos(event->pos());
        tempFigure = item;        
        list_item->push_front(dynamic_cast<Circle*>(tempFigure));
        this->addItem(dynamic_cast<Figure*>(item));
        }
        break;
    }
    case lineType: {
        if (event->button() == Qt::LeftButton,this->getId())
        {
        Line *item = new Line(event->scenePos(),this->color, this->sizeP, this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        list_item->push_front(dynamic_cast<Line*>(tempFigure));
        this->addItem(dynamic_cast<Figure*>(item));
        }
        break;
    }
    case right: {
        curItem = this->itemAt(event->scenePos(),QTransform());
        if(curItem) {
            curItem->setTransform(QTransform().translate(1,1)
                                  .rotate(90).
                                  translate(-1,-1), true);
        }}
        break;
    case left: {
        curItem = this->itemAt(event->scenePos(),QTransform());
        if(curItem) {
            curItem->setTransform(QTransform().translate(1,1)
                                  .rotate(-90).
                                  translate(-1,-1), true);
        }}
        break;
    case objdelete: {
       curItem = this->itemAt(event->scenePos(),QTransform());
        if(curItem) {
            int ind = list_item->indexOf(dynamic_cast<Figure*>(curItem));
            iter = list_item->begin();
            (iter[ind])->hide();
            list_item->push_front(iter[ind]);
            this->update();
        }
        break;

    }
    default:{
        Square *item = new Square(event->scenePos(),this->color,this->getId());
        item->setPos(event->pos());
        tempFigure = item;
        //tempFigure->setFlags(QGraphicsItem::ItemIsMovable);
        list_item->push_front(dynamic_cast<Square*>(tempFigure));
        this->addItem(dynamic_cast<Figure*>(item));
        break;
    }
    }

}

QColor paintScene::getColor(){
    if(this->color.isValid())
        return color;
    else return Qt::white;
}
void paintScene::SetColor(QColor color){
    this->color = color;
}
void paintScene::SetSizePen(int sizeP){
    this->sizeP = sizeP;
}
void paintScene::ctrl_z(){
    if (!list_item->empty()){
    Figure *temp = list_item->takeFirst();
    if(temp){
        if(temp->isVisible())
        delete temp;
        else {
            iter[list_item->indexOf(temp)]->setVisible(true);
        }
    }
    this->update();
}
}



