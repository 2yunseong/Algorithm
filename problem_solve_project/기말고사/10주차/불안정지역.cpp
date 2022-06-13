#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n, k;
    vector<int> citys;
    int max = -1;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        citys.push_back(temp);
    }

    for (int i = 0; i < n - k + 1; i++)
    {
        vector<int> area;
        int temp;
        for (int j = i; j < i + k; j++)
        {
            area.push_back(citys[j]);
        }
        sort(area.begin(), area.end());
        temp = area[area.size() - 1] - area[0];
        if (temp > max)
        {
            max = temp;
        }
    }
    cout << max << '\n';
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