#include <stdio.h>
int add(int a, int b)
{
    int sum;
    sum = a + b;
    return sum;
}

int main() // void error
{
int x = 3, y = 4, z;
z = add(x, y);
printf("z=%d", z);

}

