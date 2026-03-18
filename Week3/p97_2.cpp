#include <iostream> 
int main()
{
int num;
std::cin >> num;

int a = num/10000;
int b = (num%10000) / 1000;
int c = (num%1000) / 100;
int d = (num%100) / 10;
int e = num % 10;

if (a != 0)
{
    if(a!= 1)
    {
        std::cout << a;
    }
    std:: cout << "만";
}

if (b != 0)
{
    if(b!= 1)
    {
        std::cout << b;
    }
    std:: cout << "천";

}

if (c != 0)
{
    if(c!= 1)
    {
        std::cout << c;
    }
    std:: cout << "백";

}

if (d != 0)
{
    if(d!= 1)
    {
        std::cout << d;
    }
    std:: cout << "십";
}

if (e != 0)
{
    if(e!= 1)
    {
        std::cout << e;
    }
    std:: cout << "일";
}

}