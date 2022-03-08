#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    int n;
    int sum = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        sum += temp;
    }
    printf("%d", sum);
    return 0;
}