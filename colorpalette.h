#ifndef COLORPALLETE_H
#define COLORPALLETE_H

#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class ColorPalette : public QLabel
{
    Q_OBJECT
public:
    explicit ColorPalette(QWidget *parent = 0);

signals:

    void Color(QColor color);
protected:
    virtual void mousePressEvent(QMouseEvent *e);

};

#endif // COLORPALLETE_H
