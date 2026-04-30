#pragma once
#include <iostream>
#include <string>

using namespace std;

class Canvas
{
    int width, height;
    string** map;

    public:
    Canvas(int w, int h) : width(w), height(h)
    {
        map = new string*[height];
        for (int y = 0; y < height; y++)
        {
            map[y] = new string[width];
        }
        clear(" ");
    }

    ~Canvas()
    {
        for (int y = 0; y < height; y++)
        {
            delete[] map[y];
        }
        delete[] map;
    }

    void clear(string val = " ")
    {
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                map[y][x] = val;
            }
        }
    }

    void draw(int x, int y, string val)
    {
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
           map[y][x] = val;
        }
    }

    

    void print()
    {
        system("cls");
        for (int y = 0; y < height; y++)
        {
            for(int x = 0; x < width; x++)
            {
                cout << map[y][x];
            }
            cout << endl;
        }
    }
};