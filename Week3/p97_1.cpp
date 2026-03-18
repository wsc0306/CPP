#include <iostream> // input output stream
int main() 
// num 1
{
    for(int i = 1; i <= 5; ++i) 
     {
        // std::cout << i << "\n"; 


         for(int j = 1; j <= i; ++j)
         {
             std::cout << j;
         }
         std::cout << "\n";
     }
    std::cout << "\n";

//==============================
// num 2


    for(int i = 5; i >= 1; --i) 
     { std::cout << "\n";
       for(int j = 5; j >= 5 - (i - 1); --j)
       {
              std::cout << j;
             
       }
       
     }
     std::cout << "\n";

//==============================
// num 3

for(int i =1; i<= 5; ++i)
{ std::cout << "\n";
    for(int j = 1; j <=5 -i; ++j)
    {
        std::cout << " ";
    }

    for(int j = i; j >= i; --j)
    {
        for(j = i; j>0; --j)
        {
        std::cout << j;
        }
    }

}
std::cout << "\n";

//==============================
// num 4

for(int i = 1; i<=5; ++i)
{
    std::cout << "\n";
    for(int j = 5 - i; j >= 1; --j)
    {
        std::cout << " ";
    }
    
    for(int j = i; j >= 1; --j)
    {
        std::cout << j;
    }

    for(int j = 2; j <= i; ++j)
    {
        std::cout << j;
    }
}


    }