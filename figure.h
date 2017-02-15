#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF startPoint
                  READ startPoint WRITE setStartPoint
                  NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
                   READ endPoint WRITE
                   setEndPoint
                   NOTIFY pointChanged)
public:
    Figure();
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QColor color;
    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
    bool operator==(const Figure& obj);

    void setStartPoint(const QPointF point); // Установка стартовой точки
    void setEndPoint(const QPointF point); // Установка конечной точки

signals:
    void pointChanged();    // Сигнал об изменении точки

private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
protected:
    int id;
    QRectF boundingRect() const;    // Область, в которой содержится фигура

public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
    void SetColor(QColor color);
};

#endif // FIGURE_H

