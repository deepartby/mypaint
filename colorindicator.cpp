#include "colorindicator.h"
#include <QDebug>

ColorIndicator::ColorIndicator(QWidget *parent) :
    QWidget(parent)
{
    setAutoFillBackground(true);
    SetColor(Qt::black);
}

void ColorIndicator::SetColor(QColor color)
{
    QPalette pal;
    pal.setColor(backgroundRole(), color);
    setPalette(pal);
    emit Color(color);
}
