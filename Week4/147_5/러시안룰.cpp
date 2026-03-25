#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() 
{
    int n;
    int people;
    int bullets;

    std::cout << "사람 수 입력 : ";
    std::cin >> people;

    std::cout << "총알 수 입력 : ";
    std::cin >> bullets;    

    std::cout << "실린더 칼 수 입력 (n연발) : ";
    std::cin >> n;

    std::vector<int> gun(n,0);

    srand(time(0));

    int count = 0;
    while(count < bullets)
    {
        int  pos = rand() % n;
        if(gun[pos] == 0)
        {
            gun[pos] = 1;
            count++;
        }
    }

    std::cout << "\n 러시안 룰렛 시작\n";

    int current = 0;
    int person = 1;
    int hit = 0;

    while (hit < bullets)
    {
        std::cout << "사람 " << person << "이 방아쇠를 당깁니다... ";
        if (gun[current] == 1) 
        {
            std::cout << "빵! 사람 " << person << "이 죽었습니다.\n";
            hit++;
        } 
        else 
        {
            std::cout << "철컥... 사람 " << person << "이 살아남았습니다.\n";
        }

        person++;
        if (person > people)
            person = 1;

            current++;
        if (current >= n)
            current = 0;
    }

    std::cout << "\n게임 종료 총알 " << bullets << "발 모두 발사됨.\n";

    return 0;




}