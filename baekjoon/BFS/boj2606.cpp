#include <iostream>
#include <queue>

using namespace std;

int connect[101][101];
int isVisited[101];

int main()
{
    int n, nodeNum;
    int answer = 0;
    queue<int> q;
    cin >> n;
    cin >> nodeNum;

    for (int i = 0; i < nodeNum; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        connect[v1][v2] = connect[v2][v1] = 1;
    }

    q.push(1);
    isVisited[1] = 1;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        for (int i = 1; i < n + 1; i++)
        {
            if (connect[current][i] == 1 && isVisited[i] == 0)
            {
                isVisited[i] = 1;
                answer++;
                q.push(i);
            }
        }
    }

    cout << answer;
    return 0;
}