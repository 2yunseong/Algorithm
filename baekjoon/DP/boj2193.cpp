#include <iostream>

using namespace std;

long long d[2][100];
// 0 : 이친수 인수
// 1 : 1로 시작하지 않는 이친수

int main()
{
    long long n;
    cin >> n;
    d[0][1] = 1;
    d[1][1] = 1;

    d[0][2] = 1;
    d[1][2] = 2;

    for (int i = 3; i <= n; i++)
    {
        d[0][i] = d[0][i - 2] + d[1][i - 2];
        d[1][i] = d[0][i - 1] + d[1][i - 1];
    }

    cout << d[0][n];

    return 0;
}