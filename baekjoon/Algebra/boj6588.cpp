#include <iostream>
#include <vector>
#include <ctime>
#define MAX 1000000

using namespace std;

// 1이면 소수가 아님 0이면 소수.
int sieve[1000005] = {0};
vector<int> primeList;
void init()
{
    clock_t start = clock();
    for (int i = 2; i <= MAX; i++)
    {
        if (sieve[i] == 0)
        {
            primeList.push_back(i);
            for (int j = i + i; j <= MAX; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    clock_t end = clock();
}

int main()
{
    ios::sync_with_stdio(false);
    init();
    int pSize = primeList.size();

    while (1)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int j = 0; j < pSize; j++)
        {
            if (n - primeList[j] < 0)
                continue;
            if (sieve[n - primeList[j]] == 0)
            {
                printf("%d = %d + %d\n", n, primeList[j], n - primeList[j]);
                break;
            }
        }
    }

    return 0;
}