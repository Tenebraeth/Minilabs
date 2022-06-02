#include "rect.h"

Rect::Rect(int x1, int y1, int x2, int y2) : x1(x1),
    y1(y1),
    x2(x2),
    y2(y2)
{}

int Rect::getX1() const
{
    return x1;
}

void Rect::setX1(int newX1)
{
    x1 = newX1;
}

int Rect::getY1() const
{
    return y1;
}

void Rect::setY1(int newY1)
{
    y1 = newY1;
}

int Rect::getX2() const
{
    return x2;
}

void Rect::setX2(int newX2)
{
    x2 = newX2;
}

int Rect::getY2() const
{
    return y2;
}

void Rect::setY2(int newY2)
{
    y2 = newY2;
}

bool Rect::inRect(int x0, int y0) {
    if (((x0>x1) && (x0<x2)) &&((y0>y1) && (y0<y2)))
        return true;
    else
        return false;
}
