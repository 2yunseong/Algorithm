#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin>>testcase;
    while(testcase)
    {
        stack<int> stk;
        bool check = true;
        string temp;
        cin>>temp;
        int ps_size = (int)temp.size();
        for(int i=0; i<ps_size; i++)
        {
            if(temp[i]==')')
            {
                if(stk.empty())
                {
                    check =false;
                    break;
                }
                else
                   stk.pop();
            }
            else if(temp[i]=='(')
                stk.push(1);
        }
        if(!stk.empty())
            check = false;
        if(check)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        testcase--;
    }
    return 0;
}