#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>


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
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier) {
        count++;
        if(count == 1) {
            x = event->x();
            y = event->y();
        }
        else if(count == 2) {
            rect.append(Rect(x,y,event->x(), event->y()));
            repaint();
        }
    }
    else {

        for (int i = 0; i<rect.size(); i++) {
            if (rect[i].contains(event->x(),event->y()) && rect[i].getClr()==Qt::transparent) {
                rectClr = rect[i];
                color++;
                for (int j = (i+1); j<rect.size(); j++) {
                    if (rect[j].contains(event->x(),event->y()) && rect[j].getClr()==Qt::transparent) {
                        rectClr = rectClr.intersect(rect[j]);
                        color++;
                    }
                }
                break;
            }
        }

        qDebug("%d", color);

        if(color!=0) {
            if (color==2) rectClr.setClr(Qt::red);
            else if (color==3) rectClr.setClr(Qt::yellow);
            else if (color==4) rectClr.setClr(Qt::green);
            else if (color==5) rectClr.setClr(Qt::blue);
            else if (color>=6) rectClr.setClr(Qt::black);
            if (color>1) rect.append(rectClr);
            repaint();
        }
}
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (count==2 || color!=0) {
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::red) rect[i].draw(&painter);
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::yellow) rect[i].draw(&painter);
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::green) rect[i].draw(&painter);
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::blue) rect[i].draw(&painter);
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::black) rect[i].draw(&painter);
    for (int i = 0; i<rect.size();i++)
        if (rect[i].getClr()==Qt::transparent) rect[i].draw(&painter);
    count = 0;
    color = 0;
}
}
