#ifndef POINT_H
#define POINT_H

class QPainter;
class Point
{
public:
    Point(int x, int y);
    int getX() const;
    void setX(int newX);

    int getY() const;
    void setY(int newY);

    int getSize() const;
    void setSize(int newSize);

    int getWidth() const;
    void setWidth(int newWidth);

    void draw(QPainter *);

private:
    int x, y, size, width;

};

#endif // POINT_H
