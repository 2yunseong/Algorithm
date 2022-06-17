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
}

void solve(int start, int toPick, int pick, vector<int> &v)
{
    if (toPick == 0)
    {
        printArr(v);
        return;
    }
    for (int i = start; i <= pick; i++)
    {
        v.push_back(i);
        solve(i, toPick - 1, pick, v);
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
    solve(1, m, n, v);

    return 0;
}