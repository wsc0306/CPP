#include <algorithm>
#include "3.hpp"

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    std::string s;
    std::cout << "Enter number : ";
    std::cin >> s;

    std::cout << "reverse : " ;
    std::cout << reverse(s) << std::endl;

}