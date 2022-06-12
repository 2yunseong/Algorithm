#include <iostream>

using namespace std;
int board[10][10]; // 인접행렬
int isVisited[10]; // 방문한 노드 번호

void dfs(int num)
{
    if (isVisited[num] == 1)
        return;
    cout << num << '\n';
    isVisited[num] = 1;
    for (int i = 0; i < 10; i++)
    {
        // 방문할 곳이 존재하고, 아직 방문하지 않은 점이라면
        if (board[num][i] == 1 && isVisited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int n; // 받을 갯수
    cin >> n;
    // 보드 초기화
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        board[v1][v2] = board[v2][v1] = 1;
    }
    // dfs 실행
    dfs(1);
    return 0;
}