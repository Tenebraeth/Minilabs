#include "point.h"
#include "QPainter"

Point::Point(int x, int y)
    :x(x),y(y),size(3),width(1)
{
}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

int Point::getWidth() const
{
    return width;
}

void Point::setWidth(int newWidth)
{
    width = newWidth;
}

void Point::draw(QPainter *painter)
{

    painter->drawLine(x-size,y,x+size,y);
    painter->drawLine(x,y-size,x,y+size);
}
