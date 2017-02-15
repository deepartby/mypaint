#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include <QGraphicsScene>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QEvent>
#include <QApplication>
#include <QtPlugin>
#include <QLibrary>
#include <iostream>

#include "paintscene.h"
#include "colorpalette.h"
#include "colorindicator.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    ColorIndicator *indicator;
    ColorPalette* palette;
    Ui::MainWindow *ui;
    QTimer *timer;
    paintScene *scene;
    QColor color;
    int sizeP;
    int sizeWind;
signals:
    Color(QColor);
    SizePen(int);
private:
    /* Переопределяем событие изменения размера окна
    * для пересчёта размеров графической сцены
    * */
    void resizeEvent(QResizeEvent *event);
private slots:
    void slotTimer();
    void on_savefile_clicked(); //
    void on_openfile_clicked();
    void on_newfile_clicked();
    void on_romb_clicked();          // Включаем отрисовку Ромба
    void on_square_clicked();
    void on_rectangle_clicked();// Включаем отрисовку Квадрата
    void on_threeangle_clicked();    // Включаем отрисовку Треугольника
    void on_mousepen_clicked();      //Отрисовка кистью
    void on_ellipse_clicked();
    void on_left_clicked();          // Поворот влево
    void on_right_clicked();         // Поворот вправо
    void on_objdelete_clicked();     // Удаление объектов
    void on_line_clicked();          //Отрисовка линии
    void on_erase_clicked();
    void on_ctrl_z_clicked();
    void SetColor(QColor color);
    void SetSizePen(int sizeP);
    void on_scalePlus_clicked();
    void on_scaleMin_clicked();

};

#endif // MAINWINDOW_H
