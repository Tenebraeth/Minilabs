#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <point.h>
#include <rect.h>
#include <QMessageBox>

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
    if (n>1) {
    for (int i =0;i<n;i++){
    painter.drawLine(points[0]->getX(),points[0]->getY(),points[0]->getX(),points[1]->getY());
    painter.drawLine(points[0]->getX(),points[0]->getY(),points[1]->getX(),points[0]->getY());
    painter.drawLine(points[1]->getX(),points[1]->getY(),points[1]->getX(),points[0]->getY());
    painter.drawLine(points[1]->getX(),points[1]->getY(),points[0]->getX(),points[1]->getY());
    }
    }


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *point = nullptr;
    if (n>1) {
        rect = new Rect(points[0]->getX(),points[0]->getY(), points[1]->getX(),points[1]->getY());
        if (rect->inRect(event->x(), event->y())){
            QMessageBox msgBox;
            msgBox.setText("Попали");
            msgBox.exec();
            return;
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Не попали");
            msgBox.exec();
            return;
        }


    }

    point = new Point(event->x(),event->y());
    if(point)
        points[n++] = point;

    repaint();
}

