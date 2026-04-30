#include <iostream>
#include "MyTime.h"

using namespace std;

int main()
{
    MyTime t1(1, 20, 30, 500);
    MyTime t2;

    cout << "t1 : ";
    t1.print();

    cout << "t2 : ";
    t2.print();

    return 0;
}