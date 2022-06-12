#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define INTS pair<int, int>

using namespace std;

int board[30][30];
int isVisited[30][30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    vector<int> counts;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            if (temp[j] == '1')
            {
                board[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                continue;
            if (isVisited[i][j] == 1)
                continue;
            int cnt = 1;
            queue<INTS> q;
            INTS dot = make_pair(i, j);
            q.push(dot);
            isVisited[i][j] = 1;
            while (!q.empty())
            {
                INTS current = q.front();
                q.pop();
                int x = current.first;
                int y = current.second;

                for (int i = 0; i < 4; i++)
                {
                    int nextX = x + dx[i];
                    int nextY = y + dy[i];
                    if (nextX >= n || nextX < 0 || nextY >= n || nextY < 0)
                        continue;
                    if (board[nextX][nextY] == 1 && isVisited[nextX][nextY] == 0)
                    {
                        isVisited[nextX][nextY] = 1;
                        cnt++;
                        q.push(make_pair(nextX, nextY));
                    }
                }
            }
            counts.push_back(cnt);
        }
    }
    sort(counts.begin(), counts.end());
    cout << counts.size() << '\n';
    int cs = counts.size();
    for (int i = 0; i < cs; i++)
    {
        cout << counts[i] << '\n';
    }

    return 0;
}