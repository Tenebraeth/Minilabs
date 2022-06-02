#ifndef TEMPUS_H
#define TEMPUS_H
#include <string>
#include <iostream>

class Tempus
{
public:
    Tempus();
    Tempus(int a, int b);
    Tempus(std::string time);

    int operator-(Tempus &t);
    Tempus operator +(int res);
    void print();

private:
    int h,m;
};

#endif // TEMPUS_H
