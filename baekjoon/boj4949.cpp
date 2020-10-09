#include <bits/stdc++.h>

using namespace std;
//1. 마지막에 stack 에 원소가 남아 있을 때
//2. 원소가 없는데 POP 하려 할 때
bool isPair(string str, stack<int> &stk, char left, char right)
{
    bool ref = false;
    for (int i = 0; i < (int)str.size(); i++)
    {
        if (str[i] == left)
            stk.push(1);
        else if (str[i] == right)
        {
            if (stk.empty())
                return ref;
            else
                stk.pop();
        }
    }
    if (!stk.empty())
        return ref;

    ref = true;
    return ref;    
}
int main()
{
    ios::sync_with_stdio(false);
    bool dot = true;
    while (dot)
    {
        stack<int> small;
        stack<int> large;
        string temp;
        /* 온점이 나오기 전까지, 개행문자가 오던, 공백이 오던
        한문장으로 처리해야한다. */
        getline(cin,temp,'.');
        if(temp.empty())
            dot = false;
        else
        {
            if(isPair(temp, small,'(', ')') && true && isPair(temp, large, '[', ']'))
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
    }
    return 0;
}

/* 문제에서 주어진 규칙을 좀 더 엄격하게 적용 시켜야 한다. */