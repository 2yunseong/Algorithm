#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < v[i])
            max = v[i];
    }

    cout << max;

    return 0;
}