#include <iostream> // input output stream
int main() 
// 1-1
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
    
//==============================
// 1-2


    
    for(int i = 5; i >= 1; --i) 
     {
        std::cout << i;
       for(int j = 5; j >= i; --j)
       {}
     }
     std::cout << "\n";
}