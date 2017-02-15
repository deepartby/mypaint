#ifndef COLORINDICATOR_H
#define COLORINDICATOR_H

#include <QWidget>

class ColorIndicator : public QWidget
{
    Q_OBJECT
public:
    explicit ColorIndicator(QWidget *parent = 0);

signals:
    void Color(QColor color);
public slots:
    void SetColor(QColor color);

};

#endif // COLORINDICATOR_H
