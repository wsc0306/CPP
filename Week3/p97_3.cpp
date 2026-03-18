#include <iostream> 
int main()
{
int a;
std::cin >> a;
std::cout << "정수 입력 : " << a << 4 << "\n";

double sum = 0.0;

for (int i = 0; i < a; ++i)
{
    double term = 1.0 / (2 * i + 1);

    if (i % 2 == 0) 
    {
        sum += term;
    } 
    else 
    {
        sum -= term;
    }
}

double pi = 4 * sum;

std :: cout << "pi 근사값 : " << pi;

}