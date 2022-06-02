#include "rect.h"
#include <QPainter>

Rect::Rect()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    clr = Qt::transparent;
}

Rect::Rect(int x1, int y1, int x2, int y2, QColor clr)
{
    x = x1 < x2 ? (w=x2-x1,x1) : (w=x1-x2,x2);
    y = y1 < y2 ? (h=y2-y1, y1) : (h=y1-y2, y2);
    this->clr = clr;
}

Rect::Rect(int x1, int y1, int x2, int y2)
{
    x = x1 < x2 ? (w=x2-x1,x1) : (w=x1-x2,x2);
    y = y1 < y2 ? (h=y2-y1, y1) : (h=y1-y2, y2);
    clr = Qt::transparent;
}

bool Rect::contains(int x, int y)
{
    return(x >= this->x && x <= (this->x+w) && y >= this->y && y <= (this->y+h));
}

void Rect::draw(QPainter *painter)
{
    painter->drawRect(x,y,w,h);
    painter->fillRect(x,y,w,h,clr);
}

Rect Rect::intersect(Rect &r)
{
    Rect rx(x,y,(x+w),(y+h));
    if (this->x<r.getX()) {
        rx.setX(r.getX());
        rx.setW(this->x+this->w-rx.getX());
    }
    if ((this->x+this->w)>(r.getX()+r.getW())) rx.setW(r.getX()+r.getW()-rx.getX());
    if (this->y<r.getY()) {
        rx.setY(r.getY());
        rx.setH(this->y+this->h-rx.getY());
    }
    if ((this->y+this->h)>(r.getY()+r.getH())) rx.setH(r.getY()+r.getH()-rx.getY());


    return rx;
}

int Rect::getX() const
{
    return x;
}

void Rect::setX(int newX)
{
    x = newX;
}

int Rect::getY() const
{
    return y;
}

void Rect::setY(int newY)
{
    y = newY;
}

int Rect::getW() const
{
    return w;
}

void Rect::setW(int newW)
{
    w = newW;
}

int Rect::getH() const
{
    return h;
}

void Rect::setH(int newH)
{
    h = newH;
}

const QColor &Rect::getClr() const
{
    return clr;
}

void Rect::setClr(const QColor &newClr)
{
    clr = newClr;
}


