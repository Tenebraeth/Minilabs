#ifndef POINT_H
#define POINT_H


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

private:
    int x, y, size;

};

#endif // POINT_H
