#include <iostream>
#include <cmath>

using namespace std;
void solve(int tc, int r)
{
    cout << "#" << tc << '\n';
    long long total = 0;
    for (int i = 0; i < r + 1; i++)
    {
        double y = sqrt(r * r - i * i);
        int cnt = ceil(y);
        total += cnt;
    }

    cout << total * 4 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int r;
        cin >> r;
        solve(tc + 1, r);
    }

    return 0;
}