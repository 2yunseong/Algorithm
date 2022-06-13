#include <iostream>

using namespace std;
int groupTable[4][4] = {{0, 0, 0, 0}, {0, 1, 2, 3}, {0, 4, 5, 6}, {0, 7, 8, 9}};

void solve(int tc, int n)
{
    cout << "Case #" << tc + 1 << ':' << '\n';
    int col = ((n - 1) % 9) + 1;
    int row = ((n - 1) / 9) + 1;
    int group_row = (row - 1) / 3 + 1;
    int group_col = (col - 1) / 3 + 1;
    int group = groupTable[group_row][group_col];
    cout << row << ' ' << col << ' ' << group << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int temp;
        cin >> temp;
        solve(i, temp);
    }

    return 0;
}