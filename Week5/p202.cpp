#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void randomMap (int map[5][5]) {
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            map[i][j] = rand() % 2; 
        }
    }
}
void printMap (int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void checkMap (int map[5][5]) 
{
    for (int i = 0; i < 5; i++) 
    {
       int sum = 0;
        for (int j = 0; j < 5; j++) 
        {
            sum += map[i][j];
        }
        if (sum == 0 || sum == 5) 
        {
            cout << "가로" << i << " OK\n";
        }
    }

    for (int j = 0; j < 5; j++) 
    {
        int sum = 0;
        for (int i = 0; i < 5; i++) 
        {
            sum += map[i][j];
        }
        if (sum == 0 || sum == 5) 
        {
            cout << "세로" << j << " OK\n";
        }
    }

    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < 5; i++) 
    {
        sum1 += map[i][i];
        sum2 += map[i][4 - i];
    }
    if (sum1 == 0 || sum1 == 5) cout << "대각선1 OK\n";
    if (sum2 == 0 || sum2 == 5) cout << "대각선2 OK\n";
}


int main() 
{
    srand(time(0)); 
    int map[5][5];

    randomMap(map);
    printMap(map);
    checkMap(map);
    return 0;
}