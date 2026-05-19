#pragma once

#include <iostream>
#include <Windows.h>
#include "Monster.h"

using namespace std;

#define MAXMONS 20

class MonsterWorld
{
    private:
        int width, height;
        int** map;
        Monster* mons[MAXMONS];
        int nMonsters;

    public:
        MonsterWorld(int w, int h) : width(w), height(h), nMonsters(0)
        {
            map = new int*[height];

            for (int i = 0; i < height; i++)
            {
                map[i] = new int[width];

                for (int j = 0; j < width; j++)
                {
                    map[i][j] = rand() % 2;
                }
            }
        }

        ~MonsterWorld()
        {
            for (int i = 0; i < height; i++)
            {
                delete[] map[i];
            }
            delete[] map;

            for (int i = 0; i < nMonsters; i++)
            {
                delete mons[i];
            }
        }

        void add(Monster* m)
        {
            if (nMonsters < MAXMONS)
            {
                mons[nMonsters++] = m;
            }
        }

        void draw()
        {
            system("cls");

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    bool found = false;

                    for (int k = 0; k < nMonsters; k++)
                    {
                        if (mons[k]->getX() == x && mons[k]->getY() == y)
                        {
                            monsters[k]->draw();
                            found = true;
                            break;
                        }
                    }

                    if (!found)
                    {
                        if(map[y][x] == 1)
                            cout << "*";
                        else
                        cout << ".";
                    }
                }
                
            }

            cout << endl;

            
        }
        cout << endl;

        for (int i = 0; i < nMonsters; i++)
        {
            mons[i]->print();
        }
        void play (int delay, int count)
        {
            for (int i = 0; i < nTurns; i++)
            {
                draw();

                for (int k = 0; k < nMonsters; k++)
                {
                    monsters[k]->move(map, width, height);
                }

                Sleep(delay);
            }
        }
};