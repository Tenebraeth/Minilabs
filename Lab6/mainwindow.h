#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "Rect.h"
#include <QVector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    int x,y;
    int color = 0;
    int count = 0;
    int size = 0;
    QVector<Rect> rect; //вектор содержащий все прямоугольники
    Rect rectClr;

};
#endif // MAINWINDOW_H
