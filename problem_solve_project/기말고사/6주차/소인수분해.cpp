#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(int n)
{
    int m = 2;
    vector<int> v;
    while (m <= sqrt(n))
    {
        if (n % m == 0)
        {
            v.push_back(m);
            n /= m;
        }
        else
        {
            m++;
        }
    }
    v.push_back(n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}