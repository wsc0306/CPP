#pragma once

#include "Monster.h"

//Zombie
class Zombie : public Monster
{
    public:
        Zombie(string n = "허접좀비", string i = "#", int x = 0, int y = 0) : Monster(n, i, x, y) { }
        ~Zombie()
        {
            cout << "Zombie";
        }
};

//Vampire
class Vampire : public Monster
{
    Vampire(string n = "뱀파이어짱", string i = "@", int x = 0, int y = 0) : Monster(n, i, x, y) { }
    ~Vampire()
    {       
         cout << "Vampire";
    }

    void move(int** map, int maxx, int maxy)
    {
        int dir = rand() % 4;

        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        elsey++;

        clip(maxx, maxy);

        eat(map);
    }
};

//KGhost
class KGhost : public Monster
{
    KGhost(string n = "어쩌다귀신", string i = "&", int x = 0, int y = 0) : Monster(n, i, x, y) { }
    ~KGhost()
    {      
         cout << "KGhost";
    }
    void move(int** map, int maxx, int maxy)
    {
        x = rand() % maxx;
        y = rand() % maxy;

        clip(maxx, maxy);

        eat(map);
    }
};

//Jiangshi
class Jiangshi : public Monster
{
    protected:
        bool bHori;


    public:
        Jiangshi(string n = "못먹어도가로", string i = "!", int x = 0, int y = 0, bool bHori = true) : Monster(n, i, x, y), bHori(bHori) { }
        ~Jiangshi()
        {      
             cout << "Jiangshi";
        }
        void move(int** map, int maxx, int maxy)
        {
            int dir = rand() % 2;

            int jump = rand() % 2 + 1;

            if (bHori)
            {
                x += ((dir == 0) ? - jump : jump);
            }
            else
            {
                y += ((dir == 0) ? - jump : jump);
            }
            clip(maxx, maxy);

            eat(map);
        }
};

//Smombi
class Smombi : public Monster
{
    public:
        Smombi(string n = "스몸비", string i = "S", int x = 0, int y = 0) : Monster(n, i, x, y) { }
        ~Smombi()
        {      
             cout << "Smombi";
        }
        void move(int** map, int maxx, int maxy)
        {
            int dir = rand() % 4;

            if (dir == 0)
            {
                x--;
                y--;
            }
            else if (dir == 1)
            {
                x++;
                y--;
            }
            else if (dir == 2)
            {
                x--;
                y++;
            }
            else
            {
                x++;
                y++;
            }
            

            clip(maxx, maxy);

            eat(map);
        }
};

//Siangshi
class Siangshi : public Monster
{
    private:
        int count;

    public:
        Siangshi(string n = "수퍼강시", string i = "X", int x = 0, int y = 0, bool bH = true) : Jiangshi(n, i, x, y, bH), count(0) { }
        ~Siangshi()
        {
                cout << "Siangshi";
            }

        void move(int** map, int maxx, int maxy)
        {
            count++;

            if(count % 5 == 0)
            {
                bHori = !bHori;
            }
            Jiangshi::move(map, maxx, maxy);
        }
};

//Mymonster
class Mymonster : public Vampire 
{
    public:
        Mymonster(string n = "내몬스터", string i = "M", int x = 0, int y = 0) : Vampire(n, i, x, y) { }
        ~Mymonster()
        {
                cout << "Mymonster";
            }
        void move(int** map, int maxx, int maxy)
        {
            int dir = rand() % 8;

            if (dir == 0) x--;

            else if (dir == 1) x++;
            else if (dir == 2) y--;
            else if (dir == 3) y++;
            else if (dir == 4)
            {
                x--;
                y--;
            }
            else if (dir == 5)
            {
                x++;
                y--;
            }
            else if (dir == 6)
            {
                x--;
                y++;
            }
            else
            {
                x++;
                y++;
            }
            clip(maxx, maxy);
            eat(map);
        }
};