#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int board[502][502] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1}};
bool vis[502][502];
int n = 7, m = 10;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void print_pair(pair<int, int> p)
{
    cout << '(' << p.X << ',' << p.Y << ")\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<pair<int, int>> Q;
    vis[0][0] = 1; //start
    Q.push({0, 0});
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            if(vis[x][y]==0 && board[x][y]==1)
            {
                cout<<'\n';
                vis[x][y]=1;
                Q.push({x,y});
            }
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                print_pair(cur);
                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (vis[nx][ny] || board[nx][ny] != 1)
                        continue;
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
}