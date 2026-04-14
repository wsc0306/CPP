#include <iostream>
#include "MyTime.h"

using namespace std;

int main()
{
    MyTime t1, t2, t3;

    cout << "Enter time 1 : \n";
    t1.read();

    cout << "Enter time 2 : \n";
    t2.read();

   t3 = t1.add(t2);

   cout << "result :";
    t3.print();

    return 0;
}