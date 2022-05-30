#include <iostream>
#include <vector>

using namespace std;

int printArr(vector<int> &v)
{
    int vSize = v.size();
    for (int i = 0; i < vSize - 1; i++)
    {
        printf("%d ", v[i]);
    }
    printf("%d\n", v[vSize - 1]);
    return 0;
}
int bt(int start, int end, int m, vector<int> &v, int visited[])
{
    if (m == 0)
    {
        printArr(v);
        return 0;
    }
    for (int i = start; i <= end; i++)
    {
        if (visited[i] == 0)
        {
            v.push_back(i);
            visited[i] = 1;
            bt(start, end, m - 1, v, visited);
            v.pop_back();
            visited[i] = 0;
        }
    }
    return 1;
}

int main()
{
    vector<int> v;
    int n, m;
    scanf("%d %d", &n, &m);
    int *visited = new int[n + 1];

    for (int i = 0; i < n + 1; i++)
    {
        visited[i] = 0;
    }

    bt(1, n, m, v, visited);
    return 0;
}