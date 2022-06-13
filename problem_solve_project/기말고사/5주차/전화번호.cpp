#include <iostream>

using namespace std;
int cnts[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int phoneNumber;
        scanf("%d", &phoneNumber);
        cnts[phoneNumber]++;
    }
    int max = -1;
    int maxIdx = -1;
    for (int i = 0; i < 10000; i++)
    {
        if (max < cnts[i])
        {
            maxIdx = i;
            max = cnts[i];
        }
    }

    printf("%04d", maxIdx);

    return 0;
}