#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "exception"
#include <QtMath>
#include <QScrollBar>
#include <QGraphicsItem>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    try{
        ui->setupUi(this);

        QPixmap pix(":/img/img/paint-palette.png");
        setWindowIcon(pix);

    QWidget  pal;
    indicator = new ColorIndicator(&pal);
    palette = new ColorPalette(&pal);
    this->scene = new paintScene(this->color);// Инициализируем графическую сцену

    ui->graphicsView->setScene(scene);// устанавливаем графическую сцену
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);                // Устанавливаем сглаживание
    ui->graphicsView->setAcceptDrops(true);
    ui->graphicsView->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    timer = new QTimer();

    connect(this,&MainWindow::Color,scene,&paintScene::SetColor);
    connect(this,&MainWindow::SizePen,scene,&paintScene::SetSizePen);
    }
    catch(MemoryException exep){
        exep.showMessage();
}
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
    * от размеров окoн
    * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width()-20, ui->graphicsView->height()-20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(10);
    QMainWindow::resizeEvent(event);
}

void MainWindow::SetColor(QColor color)
{
    this->color = color;
    emit Color(color);
    qDebug() << "color in mainwindow changed";
}

void MainWindow::SetSizePen(int sizeP)
{
    this->sizeP = sizeP;
    emit SizePen(sizeP);
    //qDebug() << "size pen is good";
}

void MainWindow::on_savefile_clicked()
{
    scene->update();
    QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
    image.fill(QColor(Qt::white).rgb());
    QPainter painter(&image);
    scene->render(&painter);
    QString format = "png";
    QString initialPath = QDir::currentPath() + tr("/untitled.") + format;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                   initialPath,
                                   tr("%1 Files (*.%2);;All Files (*)")
                                   .arg(format.toUpper())
                                   .arg(format));

    if (!fileName.isEmpty())
        image.save(fileName, "png");

}
void MainWindow::on_openfile_clicked(){
    QString picture_name(QFileDialog::getOpenFileName(0, "Open image", ".", "Images (*.png *.jpg)")); // окно открытия файла
    scene->clear();// Чистим сцену
    scene->setSceneRect(0,0,QPixmap(picture_name).width() ,QPixmap(picture_name).height());
    scene->addPixmap(QPixmap(picture_name));
}
void MainWindow::on_newfile_clicked(){

    scene->clear();// Чистим сцену

}
//ромб
void MainWindow::on_romb_clicked()
{
    scene->setTypeFigure(paintScene::RombType);
}

// Квадрат
void MainWindow::on_square_clicked()
{
    scene->setTypeFigure(paintScene::SquareType);
}
void MainWindow::on_rectangle_clicked()
{
    scene->setTypeFigure(paintScene::RectangleType);
}

// Треугольник
void MainWindow::on_threeangle_clicked()
{
    scene->setTypeFigure(paintScene::TriangleType);
}
void MainWindow::on_mousepen_clicked()
{
    scene->setTypeFigure(paintScene::Mousepen);
}
void MainWindow::on_ellipse_clicked()
{
    scene->setTypeFigure(paintScene::EllipseType);
}
void MainWindow::on_line_clicked()
{
    scene->setTypeFigure(paintScene::lineType);
}
void MainWindow::on_erase_clicked()
{
    scene->setTypeFigure(paintScene::erase);
}
void MainWindow::on_scalePlus_clicked(){
    qDebug() << sizeWind << "\n";
    qreal kZoom =fabs(fabs(-1)/-1-0.05f);
    QTransform transform = ui->graphicsView->transform();
        ui->graphicsView->setTransform(transform.scale(kZoom,kZoom));
}
void MainWindow::on_scaleMin_clicked(){
    qDebug() << sizeWind << "\n";
    qreal kZoom =fabs(fabs(1)/1-0.05f);
    QTransform transform = ui->graphicsView->transform();
        ui->graphicsView->setTransform(transform.scale(kZoom,kZoom));
}

void MainWindow::on_ctrl_z_clicked()
{
    scene->ctrl_z();
}
void MainWindow::on_right_clicked()
{
    scene->setTypeFigure(paintScene::right);
    scene->update();
}
void MainWindow::on_left_clicked()
{
    scene->setTypeFigure(paintScene::left);
    scene->update();
}
void MainWindow::on_objdelete_clicked()
{
    scene->setTypeFigure(paintScene::objdelete);
    scene->update();
}






