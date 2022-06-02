#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <point.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{

    for (int i=0;i<n;i++){
        QPainter painter(this);
        QPen pen;
        if (n<5)
            points[i]->setWidth(1);
        else
            points[i]->setWidth(2);
        qDebug("%d",points[i]->getWidth());
        points[i]->setSize(i+3);
        pen.setWidth(points[i]->getWidth());
        painter.setPen(pen);
        points[i]->draw(&painter);


    }




}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *point = nullptr;
    if (n>=10) return;

    point = new Point(event->x(),event->y());
    if(point)
        points[n++] = point;

    repaint();
}

