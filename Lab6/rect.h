#ifndef RECT_H
#define RECT_H
#include <QColor>

class QPainter;

class Rect
{
public:

    Rect();
    Rect(int x1, int y1, int x2, int y2, QColor clr);
    Rect(int x1, int y1, int x2, int y2);

    bool contains(int x, int y);
    void draw(QPainter * painter);
    Rect intersect(Rect &r);

    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getW() const;
    void setW(int newW);

    int getH() const;
    void setH(int newH);

    const QColor &getClr() const;
    void setClr(const QColor &newClr);

private:
    int x,y,w,h; // координаты левого верхнего угла, ширина и высота
    QColor clr;
};

#endif // RECT_H
