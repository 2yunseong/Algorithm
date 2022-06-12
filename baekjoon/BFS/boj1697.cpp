#include <iostream>
#include <queue>
#include <utility>
#define PAIRS pair<int, int>
#define MAXIUM 100000
using namespace std;
int isVisited[MAXIUM + 1];

int main()
{
    int start, find;
    queue<PAIRS> q;
    cin >> start >> find;
    PAIRS p = make_pair(start, 0);
    q.push(p);

    while (!q.empty())
    {
        PAIRS now = q.front();
        int current = now.first;
        q.pop();
        if (isVisited[current] == 1)
            continue;
        isVisited[current] = 1;
        if (current == find)
        {
            cout << now.second;
            break;
        }
        int plusOne = current + 1;
        int minusOne = current - 1;
        int teleport = 2 * current;
        if (!(plusOne > MAXIUM))
        {
            q.push(make_pair(plusOne, now.second + 1));
        }
        if (!(minusOne < 0))
        {
            q.push(make_pair(minusOne, now.second + 1));
        }
        if (!(teleport > MAXIUM))
        {
            q.push(make_pair(teleport, now.second + 1));
        }
    }

    return 0;
}