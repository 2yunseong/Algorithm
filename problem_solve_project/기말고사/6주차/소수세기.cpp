#include <iostream>

using namespace std;
int isPrime[1000001]; // 0 이면 소수, 소수가 아니면 1

void findPrime()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (isPrime[i] == 0)
        {
            for (int j = i * 2; j < 1000001; j += i)
            {
                isPrime[j] = 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    findPrime();
    for (int i = 0; i < tc; i++)
    {
        int cnt = 0;
        int start, end;
        cin >> start >> end;
        cout << "Case #" << i + 1 << ":\n";
        for (int i = start; i <= end; i++)
        {
            if (isPrime[i] == 0)
                cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}