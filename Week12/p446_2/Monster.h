#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
class Monster
{
    protected:
        string name;
        string icon;
        int x, y;
        int nItem;

    public:
        Monster(string n = "몬스터", string i = "M", int px = 0, int py = 0) : name(n), icon(i), x(px), y(py), nItem(0) { }
        virtual ~Monster()
        {
            cout << "Monster";
        }

        virtual void move(int** map, int maxx, int maxy)
        {
            int dir = rand() % 4;

            if (dir == 0) x--;
            else if (dir == 1) x++;
            else if (dir == 2) y--;
            else y++;

            clip(maxx, maxy);

            eat(map);
        }

        void clip(int maxx, int maxy)
        {
            if (x < 0) x = 0;
            else if (x >= maxx) x = maxx - 1;

            if (y < 0) y = 0;
            else if (y >= maxy) y = maxy - 1;
        }

        void eat(int** map)
        {
            if (map[y][x] == 1)
            {
                map[y][x] = 0;
                nItem++;
            }
        }

        void draw()
        {
            cout << icon;
        }

        void print()
        {
            cout << "\t" <<name << " " << icon << " " << nItem << "개\n";
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }
};