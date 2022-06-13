#include <iostream>
#include <queue>

using namespace std;
void solve()
{
    queue<int> q;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        q.push(i + 1);
    }
    long long cnt = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        if (cnt % m == 0)
        {
            cout << f << ' ';
        }
        else
        {
            q.push(f);
        }
        cnt++;
    }
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}