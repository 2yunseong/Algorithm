#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main()
{
    int n;
    char variable = 'A';
    stack<double> s;
    string inputs;
    map<char, int> m;

    cin >> n;
    cin >> inputs;
    for (int i = 0; i < n; i++)
    {
        double temp;
        cin >> temp;
        m[variable] = temp;
        variable++;
    }
    int inpSize = inputs.size();
    for (int i = 0; i < inpSize; i++)
    {
        if (m.count(inputs[i]) > 0)
        {
            s.push(m[inputs[i]]);
        }
        else
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            switch (inputs[i])
            {
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '+':
                s.push(a + b);
                break;
            default:
                break;
            }
        }
    }

    printf("%.2f", s.top());
    return 0;
}