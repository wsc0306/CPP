#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define max_row 10
#define max_col 10

static int MineMapMask[max_row][max_col];
static int MineMapLabel[max_row][max_col];

int row, col;
int mineCount;

void initMap()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    }
}

void placeMine()
{
    int count = 0;
    while(count < mineCount)
    {
        int r = rand() % row;
        int c = rand() % col;

        if(MineMapLabel[r][c] == 0)
        {
            MineMapLabel[r][c] = 9;
            count++;
        }
    }
}

int countMine(int r, int c)
{
    int cnt = 0;

    for(int i=-1; i<=1; i++)
    {
        for(int j=-1; j<=1; j++)
        {
            int nr = r + i;
            int nc = c + j;

            if(nr >= 0 && nr < row && nc >= 0 && nc < col)
            {
                if(MineMapLabel[nr][nc] == 9)
                {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void printMap()
{
    cout << "   ";
    for(int j=0; j<col; j++)
    {
        cout << j%10 << " ";
    }
    cout << endl;

    for(int i=0; i<row; i++)
    {
        cout << i%10 << "  ";
        for(int j=0; j<col; j++)
        {
            if(MineMapMask[i][j] == 0)
            {
                cout << ". ";
            }
            else if(MineMapLabel[i][j] == 2)
            {
                cout << "p ";
            }
            else
            {
                if(MineMapLabel[i][j] == 9)
                {
                    cout << "* ";
                }
                else
                {
                    cout << countMine(i, j) << " ";
                }
            }
        }
        cout << endl;
    }
}

void dig(int r, int c)
{
    if(MineMapLabel[r][c] == 9)
    {
        cout << "Game Over!\n";
        exit(0);
    }

    MineMapMask[r][c] = 1;
}

void flag(int r, int c)
{
    MineMapMask[r][c] = 2;
}

int main()
{
    srand((unsigned)time(NULL));

    cout << "map size (row col): ";
    cin >> row >> col;

    cout << "mine count: ";
    cin >> mineCount;

    initMap();
    placeMine();

    while(true)
    {
        printMap();
        
        cout << "input";
        char ch;

        cin >> ch;

        if(ch == 'p' || ch == 'P')
        {
            int r,c;
            cin >> r >> c;
            flag(r, c);
        }
        else
        {
            int r,c;
            cin.putback(ch);
            cin >> r >> c;
            dig(r, c);
        }
    }
    return 0;
}