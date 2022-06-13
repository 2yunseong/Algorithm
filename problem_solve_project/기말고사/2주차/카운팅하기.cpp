#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, s;
    int cnt = 0;
    vector<int> v;
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] == m)
            cnt++;
        else if (v[i] == s)
            cnt++;
    }

    cout << cnt;

    return 0;
}