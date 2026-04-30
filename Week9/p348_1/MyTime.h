#ifndef MYTIME_H
#define MYTIME_H

class MyTime
{
    private :
        int hour, minute, second, msecond;

    public :
        MyTime(int h = 0, int m = 0, int s = 0, int ms = 0);

    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void reset();
    void read();

};

#endif