#include <iostream>
#include <iomanip>
#include "MyTime.h"

using namespace std;

MyTime::MyTime(int h, int m, int s, int ms)
    : hour(h), minute(m), second(s), msecond(ms)
{
}

MyTime::MyTime(double duration)
{
    convert(duration);
}

void MyTime::convert(double duration)
{
    int total_msecond = (int)(duration * 1000);

    hour = total_msecond / (1000 * 60 * 60);
    total_msecond %= (1000 * 60 * 60);

    minute = total_msecond / (1000 * 60);
    total_msecond %= (1000 * 60);

    second = total_msecond / 1000;
    msecond = total_msecond % 1000;
}

void MyTime::print()
{
    cout << setfill('0')
        << setw(2) << hour << ":"
        << setw(2) << minute << ":"
        << setw(2) << second << "."
        << setw(3) << msecond << endl;
}

MyTime MyTime::add(MyTime t)
{
    MyTime result;

    int total_msecond = 
        (hour * 3600000 + minute * 60000 + second * 1000 + msecond) +
        (t.hour * 3600000 + t.minute * 60000 + t.second * 1000 + t.msecond);

        result.convert(total_msecond / 1000.0);

        return result;
}

void MyTime::reset()
{
    hour = minute = second = msecond = 0;
}

void MyTime::read()
{
    cout << "Enter hour : ";
    cin >> hour;

    cout << "Enter minute : ";
    cin >> minute;

    cout << "Enter second : ";
    cin >> second;

    cout << "Enter millisecond : ";
    cin >> msecond;
}