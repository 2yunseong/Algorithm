#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<int> &arr)
{
    int count = arr.size();

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}
void solve(int start, int pick, int toPick, vector<int> &inputSrc, vector<int> &results)
{
    if (toPick == 0)
    {
        printVector(results);
        return;
    }
    for (int i = start; i < pick; i++)
    {
        results.push_back(inputSrc[i]);
        solve(i + 1, pick, toPick - 1, inputSrc, results);
        results.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    vector<int> v;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    vector<int> t;
    solve(0, n, m, v, t);

    return 0;
}