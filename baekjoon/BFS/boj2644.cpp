#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#define PAIR pair<int, int>

using namespace std;
int board[101][101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int answer = -1;
    cin >> n;
    vector<int> isVisited(n + 1);
    int start, end;
    cin >> start >> end;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        board[v1][v2] = board[v2][v1] = 1;
    }

    // first = node second = level
    queue<PAIR> q;
    pair<int, int> f = make_pair(start, 0);
    q.push(f);
    isVisited[f.first] = 1;

    while (!q.empty())
    {
        PAIR current = q.front();
        q.pop();
        for (int i = 1; i < n + 1; i++)
        {
            if (board[current.first][i] == 1 && isVisited[i] == 0)
            {
                PAIR p = make_pair(i, current.second + 1);
                isVisited[i] = 1;
                if (p.first == end)
                {
                    answer = p.second;
                    break;
                }
                q.push(p);
            }
        }
    }

    cout << answer;
    return 0;
}