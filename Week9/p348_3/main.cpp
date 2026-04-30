#include <iostream>
#include <ctime>
#include "Monster.h"

using namespace std;

#define WIDTH 20
#define HEIGHT 10
#define NMONSTER 4

int map[DIM][DIM];

int main()
{
    srand((unsigned int)time(NULL));

    Canvas canvas(WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            map[y][x] = 1;
        }
    }

    Monster m[NMONSTER] = {
        Monster("몬스터", "M", rand() % WIDTH, rand() % HEIGHT),
        Monster("도깨비", "D", rand() % WIDTH, rand() % HEIGHT),
        Monster("별그대", "S", rand() % WIDTH, rand() % HEIGHT),
        Monster("고스트", "G", rand() % WIDTH, rand() % HEIGHT)
    };

    int step = 0;

    while  (true)
    {
        step++;

        canvas.clear(" ");

        for (int i = 0; i < NMONSTER; i++)
        {
            m[i].move(map, WIDTH, HEIGHT);
        }

        for (int y = 0; y < HEIGHT; y++)
        {
            for(int x = 0; x < WIDTH; x++)
            {
                if (map[y][x] == 1)
                {
                    canvas.draw(x, y, ".");
                }
            }
        }

        for (int i = 0; i < NMONSTER; i++)
        {
            m[i].draw(canvas);
        }

        canvas.print();

        cout << "[ Monster World] " << endl;
        cout << "전체 이동 횟수 = " << step << endl;

        int remain = 0;
        for (int y = 0; y < HEIGHT; y++)
        {
            for(int x = 0; x < WIDTH; x++)
            {
                if (map[y][x] == 1) 
                remain++;
            }
        }
        cout << "남은 아이템 수 = " << remain << endl;

        for (int i = 0; i <NMONSTER; i++)
        {
            m[i].print();
        }

        if (remain == 0 || step >= 300)
        {
            cout << "게임 종료" << endl;
            break;
        }
        //system("pause");

        cout << "Enter를 누르면 다음 이동" << endl;
        cin.ignore();
        cin.get();
        

    }

    return 0;
}