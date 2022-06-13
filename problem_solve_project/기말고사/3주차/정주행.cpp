#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    int min = v[0];
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (min > v[i])
        {
            min = v[i];
        }
        if (max < v[i])
        {
            max = v[i];
        }
    }

    if ((max - min + 1) == v.size())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}