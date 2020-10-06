#include <bits/stdc++.h>
#define BAD -1
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> d;
    int n;
    cin>>n;
    while(n)
    {
        string temp;
        cin>>temp;
        if(temp=="push_front")
        {
            int x;
            cin>>x;
            d.push_front(x);
        }
        else if(temp=="push_back")
        {
            int x;
            cin>>x;
            d.push_back(x);
        }
        else if(temp=="pop_front")
        {
            if(d.empty())
                cout<<BAD<<'\n';
            else
            {
                cout<<d.front()<<'\n';
                d.pop_front();
            }
        }
        else if(temp=="pop_back")
        {
            if(d.empty())
                cout<<BAD<<'\n';
            else
            {
                cout<<d.back()<<'\n';
                d.pop_back();
            }
        }
        else if(temp =="size")
        {
            cout<<d.size()<<'\n';
        }
        else if(temp == "empty")
        {
            if(d.empty())
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
        else if(temp == "front")
        {
            if(d.empty())
                cout<<BAD<<'\n';
            else
                cout<<d.front()<<'\n';
        }
        else if(temp == "back")
        {
            if(d.empty())
                cout<<BAD<<'\n';
            else
                cout<<d.back()<<'\n';
        }
        n--;
    }
    return 0;
}