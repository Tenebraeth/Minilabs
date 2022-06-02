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
    QPainter painter(this);
    for (int i=0;i<n;i++){
        points[i]->setSize(i+3);
        QPen pen;
        pen.setWidth(1);
        painter.setPen(pen);
        painter.drawLine(points[i]->getX()-points[i]->getSize(),points[i]->getY(),points[i]->getX()+points[i]->getSize(),points[i]->getY());
        painter.drawLine(points[i]->getX(),points[i]->getY()-points[i]->getSize(),points[i]->getX(),points[i]->getY()+points[i]->getSize());

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

