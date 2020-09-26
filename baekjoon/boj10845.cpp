#include <iostream>
#include <queue>
#include <string>
#define EMPTY_TRUE 1
#define EMPTY_FALSE 0
#define BAD_ACCESS -1

using namespace std;

int main()
{
    queue<int> q;
    int testcase;
    cin>>testcase;

    for(int i=0;i<testcase; i++)
    {
        string str;
        cin>>str;
        if(str=="push")
        {
            int n;
            cin>>n;
            q.push(n);
        }
        else if(str=="pop")
        {
            if(q.empty())
                cout<<BAD_ACCESS<<endl;
            else
            {
                cout<<q.front()<<endl;
                q.pop();
            } 
        }
        else if(str=="size")
        {
            cout<<q.size()<<endl;
        }
        else if(str=="empty")
        {
            if(q.empty())
                cout<<EMPTY_TRUE<<endl;
            else
            {
                cout<<EMPTY_FALSE<<endl;
            }
        } 
        else if(str=="front")
        {
            if(q.empty())
                cout<<BAD_ACCESS<<endl;
            else
            {
                cout<<q.front()<<endl;
            }
        }
        else if(str=="back")
        {
            if(q.empty())
                cout<<BAD_ACCESS<<endl;
            else
            {
                cout<<q.back()<<endl;
            }
        }
        else
        {
            continue;
        }
        
    }  
    return 0;
}
