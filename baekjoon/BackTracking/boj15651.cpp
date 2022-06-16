#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> &v)
{
    int vSize = v.size();
    for (int i = 0; i < vSize; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return;
}
void solve(int pick, int toPick, vector<int> &v)
{
    if (toPick == 0)
    {
        printArr(v);
        return;
    }
    for (int i = 1; i <= pick; i++)
    {
        v.push_back(i);
        solve(pick, toPick - 1, v);
        v.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    solve(n, m, v);
    return 0;
}