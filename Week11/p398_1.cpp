#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

int count = 0;
double printCount = 0.0;

class Sample 
{
    char *name;
    double* arr = 0;
    int arrSize = 0;

     //(1)=============================================
    public:
     Sample()
     {
         count++;
         printCount = count;
         cout << "Constructor called " 
         << printCount << " times" << endl;
     }

     //(2)=============================================
     Sample(const char * name)
     {
         this->name = (char *)malloc(strlen(name) + 1);
         strcpy(this->name, name);
     }
     Sample(int size)
     {
         arr = new double[size];
         arrSize = size;
     }

     //(3)=============================================
     ~Sample(){ delete[] arr;}
     void setRand(int max = 100)
     {
        for(int i = 0; i < arrSize; i++)
        {
            arr[i] = rand() % (max * 10) / 10.0;
        }
     }







    //(4)=============================================
     void clone(const Sample &other)
    {
        if(this != &other)
        {
            delete[] arr;
            arrSize = other.arrSize;
            arr = new double[arrSize];
            for(int i = 0; i < arrSize; i++)
            {
                arr[i] = other.arr[i];
            }
        }
    }
     //=============================================
};
