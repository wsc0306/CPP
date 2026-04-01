#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 5
#define HISTORY 1000

struct Gamestate
{
    int size;
    char board[MAX][MAX];

    int blank_x;
    int blank_y;

    char histry[HISTORY];
    int movecount;

    time_t StartTime;
    time_t EndTime;
};

struct Rank
{
    int move;
    int time;
};

//puzzle board
void printBoard(Gamestate &g)
{
    cout << "\n";
    for(int i = 0; i < g.size; i++)
    {
        for(int j = 0; j < g.size; j++)
        {
            cout << g.board[i][j] << "\t";
        }
        cout << endl;
    }
}

//reset 
void initGame(Gamestate &g, int size)
{
    g.size = size;
    g.movecount = 0;

    char ch = 'A';
    for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
    {
        g.board[i][j] = ch++;
    }

    g.board[size-1][size-1] = ' ';
    g.blank_x = size-1;
    g.blank_y = size-1;

    g.StartTime = time(0);
}

//move
void moveblock(Gamestate &g, char cmd)
{
    int x = g.blank_x;
    int y = g.blank_y;

    if(cmd=='w' && x > 0)
    {
        swap(g.board[x][y], g.board[x-1][y]);
        g.blank_x--;
    }
    else if(cmd=='s' && x < g.size-1)
    {
        swap(g.board[x][y], g.board[x+1][y]);
        g.blank_x++;
    }
    else if(cmd=='a' && y > 0)
    {
        swap(g.board[x][y], g.board[x][y-1]);
        g.blank_y--;
    }
    else if(cmd=='d' && y < g.size-1)
    {
        swap(g.board[x][y], g.board[x][y+1]);
        g.blank_y++;
    }
    else
    {
        return;
    }
    g.histry[g.movecount++] = cmd;
}

//game finish check
bool iscomplete(Gamestate &g)
{
    char ch = 'A';
    for(int i = 0; i < g.size; i++)
    {
        for(int j = 0; j < g.size; j++)
        {
            if(i==g.size-1 && j==g.size-1)
            {
                return true;
            }
            if(g.board[i][j] != ch++)
            {
                return false;
            }
        }
    return true;
    }
}

//replay
void replay(Gamestate original, Gamestate g)
{
   cout << "\n === replay === \n";


   printBoard(original);

   for(int i = 0; i < g.movecount; i++)
   {
       moveblock(original, g.histry[i]);

       cout << "\n";
       printBoard(original);

       system("pause");
   }
}

//save

void saveGame(Gamestate &g)
{
    FILE *fp = fopen("save.dat", "wb");

    g.EndTime = time(0);

    fwrite(&g, sizeof(Gamestate), 1, fp);
    fclose(fp);
    cout << "Game saved.\n";
}

//load
bool loadGame(Gamestate &g)
{
    FILE *fp = fopen("save.dat", "rb");
    if(!fp)
    {
        return false;
    }

    fread(&g, sizeof(Gamestate), 1, fp);
    fclose(fp);
    return true;
}

//ranking save
void saveRank(int movecount, int time)
{
    Rank r[11];
    FILE *fp = fopen("rank.dat","rb");

    int count = 0;

    if(fp)
    {
        count = fread(r,sizeof(Rank), 10, fp);
        fclose(fp);
    }

    r[count].move = movecount;
    r[count].time = time;
    count++;

    sort(r,r+count, [](Rank a, Rank b)
    {
        return a.move < b.move;
    });

    if(count > 10) count = 10;

    fp = fopen("rank.dat","wb");
    fwrite(r,sizeof(Rank), count, fp);
    fclose(fp);
}

//ranking load
void showrank()
{
    Rank r[10];
    FILE *fp = fopen("rank.dat","rb");

    if(!fp) return;

    int count = fread(r,sizeof(Rank), 10, fp);
    fclose(fp);

    cout << "\n=== Rank ===\n";
    for(int i = 0; i < count; i++)
    {
        cout << i+1 << "up "
        <<"move : "<<r[i].move
        <<" time : "<<r[i].time<<"s\n";
    }
}

int main()
{
    Gamestate game, original;

    int menu;

    cout << "1. first game\n";
    cout << "2. load game\n";
    cout << "3. choose\n";
    cin >> menu;

    if(menu == 2)
    {
        if(!loadGame(game))
        {
            cout << "No saved game.\n";
            return 0;
        }
        original = game;
    }

    else
    {
        int size;
        cout << "Enter board size (3 ~ 5): ";
        cin >> size;

        

        initGame(game, size);
        original = game;
    }
    
    while(1)
    {
        printBoard(game);

        if(iscomplete(game))
        {
            cout << "\n puzzle complete! \n";

            int t = time(0) - game.StartTime;

            cout << "Time : " << t << "s\n";
            cout << "Move count : " << game.movecount << endl;

            saveRank(game.movecount, t);
            replay(original, game);
            showrank();
            break;
        }
        char cmd;

          cout<<"\nmove w/a/s/d\n";
          cout<<"save q\n";
           cout<<"input : ";
           cin>> cmd;

         if(cmd=='q')
         {
            saveGame(game);
            break;
         }
         moveblock(game, cmd);
     }

    
}