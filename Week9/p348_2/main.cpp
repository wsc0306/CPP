#include <iostream>
#include "MyTime.h"

using namespace std;

int main()
{
    MyTime t1(1, 30, 45, 500);
    MyTime t2(3661.789);

    cout << "Time 1: ";
    t1.print();

    cout << "Time 2: ";
    t2.print();

    return 0;
}