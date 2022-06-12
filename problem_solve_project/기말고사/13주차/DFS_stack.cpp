#include <iostream>
#include <stack>

using namespace std;
int board[10][10];
int isVisited[10];

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        board[v1][v2] = board[v2][v1] = 1;
    }

    s.push(1);
    isVisited[1] = 1;
    while (!s.empty())
    {
        int current = s.top();
        s.pop();
        cout << current << '\n';
        
        for(int i=0; i<10; i++){
            if(board[current][i] == 1 && isVisited[i] == 0){
                isVisited[i] = 1;
                s.push(i);
            }
        }
        
    }

    return 0;
}