#include <iostream>

using namespace std;

int map[10][10];       // 인접행렬을 저장할 2차원 리스트
int visited[10] = {0}; // 방문해야할 노드를 표기. 1이면 방문해야함. 0이면 방문했거나, 방문해도 되지 않을 점임.
int num;               // 이어지는 간선의 갯수

// 초기화 로직. map(인접행렬) 을 0 으로 초기화 해준다.
void init()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = 0;
        }
    }
}

void dfs(int v)
{
    cout << v << endl; // 방문한 노드를 출력하고,
    visited[v] = 0;    // 방문했다는 노드를 표시
    //인접행렬을 탐색한다.
    for (int i = 0; i <= num; i++)
    {
        // 노드가 이어져 있거나, 방문해야할 점이면 다음으로 방문한다.
        if (map[v][i] && visited[i])
            dfs(i); // 재귀적으로 호출해 다음 방문을 구현.
    }
}
int main()
{
    init();     // 인접행렬 초기화
    int v1, v2; // 간선을 표기하기 위해 임시 vertex들을 저장
    cin >> num; // 간선의 숫자
    for (int i = 0; i < num; i++)
    {
        cin >> v1 >> v2;
        map[v1][v2] = map[v2][v1] = 1; // 인접행렬을 표기한다.
        visited[v1] = visited[v2] = 1; // 방문하지 않음을 표시.
    }
    dfs(1); // 시작할 노드를 넣어준다.
    return 0;
}