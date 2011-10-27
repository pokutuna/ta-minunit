#include <stdio.h>

int cubic(int x)
{
    return x * x + x; // INCORRECTLY!
}

int main(void)
{
    printf("hoge%d\n",cubic(5));
    return 0;
}
