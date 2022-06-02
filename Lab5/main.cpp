#include <iostream>
#include <tempus.h>


using namespace std;

Tempus para1(15,20);
Tempus para2("12:30");


int main()
{
    para2.print();
    std::cout<<para1-para2<<std::endl;
    (para1+178).print();


    return 0;
}
