#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inputs;

void printArr(vector<int> &v)
{
    int vSize = v.size();
    for (int i = 0; i < vSize; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}

void solve(int toPick, int pick, vector<int> &v, vector<int> &isVisited)
{
    if (toPick == 0)
    {
        printArr(v);
        return;
    }
    for (int i = 0; i < pick; i++)
    {
        if (isVisited[i] == 0)
        {
            isVisited[i] = 1;
            v.push_back(inputs[i]);
            solve(toPick - 1, pick, v, isVisited);
            isVisited[i] = 0;
            v.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> isVisited(n + 1);
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        inputs.push_back(temp);
    }

    sort(inputs.begin(), inputs.end());

    solve(m, n, v, isVisited);

    return 0;
}