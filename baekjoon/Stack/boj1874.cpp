#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    stack<int> s;
    vector<int> remain;
    queue<int> arr;
    vector<char> answer;
    bool isRight = true;
    int n;
    int popOk = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        arr.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        remain.push_back(temp);
    }
    int rSize = remain.size();
    for (int i = 0; i < rSize; i++)
    {
        int current = remain[i];
        if (arr.empty())
        {
            if (current != s.top())
            {
                isRight = false;
                break;
            }
            else
            {
                answer.push_back('-');
                s.pop();
            }
        }
        else
        {
            while (arr.front() < current)
            {
                answer.push_back('+');
                s.push(arr.front());
                arr.pop();
            }
            if (arr.front() == current)
            {
                answer.push_back('+');
                s.push(arr.front());
                arr.pop();
                answer.push_back('-');
                s.pop();
            }
            else
            {
                if (s.top() != current)
                {
                    isRight = false;
                    break;
                }
                else
                {
                    answer.push_back('-');
                    s.pop();
                }
            }
        }
    }

    if (isRight)
    {
        int aSize = answer.size();
        for (int i = 0; i < aSize; i++)
        {
            cout << answer[i] << '\n';
        }
    }
    else
    {
        cout << "NO" << '\n';
    }
    return 0;
}