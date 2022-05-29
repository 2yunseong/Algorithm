#include <iostream>
#include <queue>

using namespace std;

int map[10][10] = {0}; // 인접행렬
int visited[10] = {0}; // 방문할 노드. 여기서는 앞선 코드와 다르게 0이면 방문을 해야되고, 1이면 이미 방문한 노드이다.
queue<int> q;
int num, edge_num;

void bfs(int v)
{
    cout << v << '\n'; // 처음 시작할 노드의 정점을 출력한다.
    q.push(v);         // queue에 밀어넣고,
    while (!q.empty())
    {
        int node = q.front(); // queue에서 node를 가져온다.
        q.pop();              // 가져왔으므로 pop해준다.
        for (int i = 0; i < num; i++)
        {
            // 각 정점들이 연결되어있고, 아직 방문한 노드가 아니면,
            if (map[node][i] == 1 && visited[i] == 0)
            {
                visited[node] = 1; // 방문했다는 표시를 남기고,
                cout << i << '\n'; // 지금 방문한 노드를 출력한다.
                q.push(i);         // 출력된 노드는 반복문에 의해서 다음 간선으로 탐색을 진행해야 하므로, 큐에 push 해준다.
            }
        }
    }
}
int main()
{
    // 입력받는 로직
    cin >> num >> edge_num;
    for (int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1;
    }
    bfs(1); // 처음 방문을 시작할 노드부터 넣어준다.
    return 0;
}