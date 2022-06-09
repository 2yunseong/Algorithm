#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    int zero_count = 0;
    stack<int> fives;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 5 == 0)
            fives.push(i);
    }

    while (!fives.empty())
    {
        int temp = fives.top();
        fives.pop();

        while (temp % 5 == 0)
        {
            zero_count++;
            temp = temp / 5;
        }
    }

    cout << zero_count;
    return 0;
}