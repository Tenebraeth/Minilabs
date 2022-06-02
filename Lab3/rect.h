#ifndef RECT_H
#define RECT_H


class Rect
{
public:
    Rect(int x1, int y1, int x2, int y2);


    int getX1() const;
    void setX1(int newX1);
    int getY1() const;
    void setY1(int newY1);
    int getX2() const;
    void setX2(int newX2);
    int getY2() const;
    void setY2(int newY2);
    bool inRect(int x0, int y0);

private:
    int x1, y1, x2, y2;
};

#endif // RECT_H
