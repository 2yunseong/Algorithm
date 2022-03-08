#include <stdio.h>
#include <iostream>

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d", getMax(a, b));

    return 0;
}