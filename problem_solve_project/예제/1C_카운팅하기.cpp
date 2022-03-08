#include <stdio.h>
#include <iostream>

using namespace std;

int findFriends(int data[], int m, int s, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (data[i] == m || data[i] == s)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int n;
    int m, s;
    int *data;
    int answer;
    data = new int[n];
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    answer = findFriends(data, m, s, n);
    printf("%d", answer);
    delete[] data;

    return 0;
}