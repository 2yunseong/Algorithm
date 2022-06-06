#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define T int, vector<int>, greater<int>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    priority_queue<T> pq;
    cin >> n;
    for (int i = 0; i < n * n; i++)
    {
        int temp;
        cin >> temp;
        if (pq.size() < n)
        {
            pq.push(temp);
        }
        else
        {
            if (pq.top() < temp)
            {
                pq.pop();
                pq.push(temp);
            }
        }
    }

    cout << pq.top();
    return 0;
}