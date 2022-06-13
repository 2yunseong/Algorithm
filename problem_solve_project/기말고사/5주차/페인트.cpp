#include <iostream>
#include <vector>

using namespace std;

int clrcnt[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1); // 0번 index 사용안함

    for (int i = 0; i < m; i++)
    {
        int start, end, color;
        cin >> start >> end >> color;
        for (int j = start; j <= end; j++)
        {
            v[j] = color;
        }
    }
    int vSize = v.size();
    for (int i = 1; i < vSize; i++)
    {
        clrcnt[v[i]]++;
    }
    int min = 999999;
    int minIdx = -1;
    int max = -1;
    int maxIdx = -1;

    for (int i = 0; i < 100; i++)
    {
        if (clrcnt[i] == 0)
            continue;
        if (min > clrcnt[i])
        {
            min = clrcnt[i];
            minIdx = i;
        }
        if (max < clrcnt[i])
        {
            max = clrcnt[i];
            maxIdx = i;
        }
    }

    cout << maxIdx << '\n';
    cout << minIdx << '\n';

    return 0;
}