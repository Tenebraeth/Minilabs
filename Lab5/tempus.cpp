#include "tempus.h"

Tempus::Tempus()
    :h(0), m(0) {}

Tempus::Tempus(int a, int b)
    :h(a), m(b) {}

Tempus::Tempus(std::string time)
{
    h = (time[0]-'0')*10 + (time[1]-'0');
    m = (time[3]-'0')*10 + (time[4]-'0');

}

int Tempus::operator -(Tempus &t)
{
    int gh = this->h*100+this->m;
    int gth = t.h*100+t.m;
    if (gh>=gth){
        if (t.m>this->m) return (gh-gth) / 100 * 60 + (gh-gth) % 100 - 40;
        return (gh-gth) / 100 * 60 + (gh-gth) % 100;
    }
    else {
        if (this->m>t.m) return (gth-gh) / 100 * 60 + (gth-gh) % 100 - 40;
        return (gth-gh) / 100 * 60 + (gth-gh) % 100;
    }
}

Tempus Tempus::operator +(int res)
{
    res += h * 60 + m;
    if (res>=1440) res-=1440;
    Tempus t(res/60, res%60);
    return t;
}

void Tempus::print()
{
    if (h<10 && m<10) std::cout<<'0'<<h<<":"<<'0'<<m<<std::endl;
    else if (h<10) std::cout<<'0'<<h<<":"<<m<<std::endl;
    else if (m<10) std::cout<<h<<":"<<'0'<<m<<std::endl;
    std::cout<<h<<":"<<m<<std::endl;
}

