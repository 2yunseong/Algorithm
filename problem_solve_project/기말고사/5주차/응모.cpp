#include <iostream>
#include <vector>

using namespace std;
int serialNums[100001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        serialNums[temp]++;
    }
    for (int i = 1; i < 100001; i++)
    {
        if (serialNums[i] == 1)
        {
            v.push_back(i);
        }
    }
    int vSize = v.size();
    for (int i = 0; i < vSize; i++)
    {
        cout << v[i] << ' ';
    }

    return 0;
}