#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    stack<int> inputs;
    stack<int> ocs;
    stack<int> answers;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        inputs.push(temp);
    }

    while (!inputs.empty())
    {
        int currentItem = inputs.top();
        inputs.pop();
        if (ocs.empty())
        {
            ocs.push(currentItem);
            answers.push(-1);
            continue;
        }
        if (ocs.top() > currentItem)
        {
            answers.push(ocs.top());
            ocs.push(currentItem);
        }
        else
        {
            while (1)
            {
                if (ocs.empty())
                {
                    ocs.push(currentItem);
                    answers.push(-1);
                    break;
                }
                if (ocs.top() > currentItem)
                {
                    answers.push(ocs.top());
                    ocs.push(currentItem);
                    break;
                }
                else
                {
                    ocs.pop();
                }
            }
        }
    }

    while (!answers.empty())
    {
        if (answers.size() == 1)
            cout << answers.top();
        else
            cout << answers.top() << ' ';
        answers.pop();
    }

    return 0;
}