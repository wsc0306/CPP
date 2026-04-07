#include <iostream>
using namespace std;

struct MyTime
{
    int hour;
    int minute;
    int second;
};

MyTime secToTime(int totalSeconds)
{
    MyTime t;

    t.hour = totalSeconds / 3600;

    t.minute = (totalSeconds / 60) % 60;

    t.second = totalSeconds % 60;

    return t;
    
}

//==================================================1

MyTime addTime1 (MyTime t1, MyTime t2)
{
   MyTime result;

   result.second = t1.second + t2.second;
    result.minute = t1.minute + t2.minute + result.second / 60;
    result.second %= 60;
    

    result.hour = t1.hour + t2.hour + result.minute / 60;
    result.minute %= 60;

    return result;
}

//==================================================2

void addTime2(MyTime t1, MyTime t2, MyTime& t3)
{
    t3.second = t1.second + t2.second;
    t3.minute = t1.minute + t2.minute + t3.second / 60;
    t3.second %= 60;
    

    t3.hour = t1.hour + t2.hour + t3.minute / 60;
    t3.minute %= 60;
}

//==================================================3

void addTime3(MyTime t1, MyTime t2, MyTime* pt)
{
    pt->second = t1.second + t2.second;
    pt->minute = t1.minute + t2.minute + pt->second / 60;
    pt->second %= 60;
    

    pt->hour = t1.hour + t2.hour + pt->minute / 60;
    pt->minute %= 60;
}

//==================================================

void printTime(MyTime t)
{
    cout << t.hour << "hour " << t.minute << "minute " << t.second << "second " << endl;
}

int main()
{
    int sec1, sec2;
    MyTime t1, t2, t3;

    cout << "Enter the first time in seconds: ";
    cin >> sec1;

    cout << "Enter the second time in seconds: ";
    cin >> sec2;

    t1 = secToTime(sec1);
    t2 = secToTime(sec2);


    //1 return
    t3 = addTime1(t1, t2);
    cout << "\n[return] ";
    printTime(t3);

    //2 reference
    addTime2(t1, t2, t3);
    cout << "\n[reference] ";
    printTime(t3);

    //3 pointer
    addTime3(t1, t2, &t3);
    cout << "\n[pointer] ";
    printTime(t3);

    return 0;
}