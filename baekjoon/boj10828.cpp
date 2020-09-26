#include <iostream>
#include <string>
#include <stack>
#define IS_TRUE 1
#define IS_FALSE 0
#define NEGATIVE -1

using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    
    stack<int> stk;
    for(int i=0; i<testcase; i++)
    {
        string str;
        cin>>str;
        if(str=="push")
        {
            int n;
            cin>>n;
            stk.push(n);
        }
        else if(str=="pop")
        {
            if(stk.empty())
                cout<<NEGATIVE<<endl;
            else
            {
            cout<<stk.top()<<endl;
            stk.pop();
            }
        }
        else if(str=="size")
        {
            cout<<stk.size()<<endl;
        }
        else if(str=="empty")
        {
            if(stk.empty())
                cout<<IS_TRUE<<endl;
            else
            {
                cout<<IS_FALSE<<endl;
            }      
        }
        else if(str=="top")
        {
            if(stk.empty())
                cout<<NEGATIVE<<endl;
            else
            {
                cout<<stk.top()<<endl;
            }
        }
        else
        {
            continue;
        }
        
    }
    return 0;
}

/* 연산자 오버로딩의 강력함을 느꼈다... str =="string"을 왜 생각못했을까
이걸 생각 못해서 반복자 가져오고 find 가져와서 삽질했다.
삽질을 했으므로 또 실력이 향상되는 것이라고 생각하자.
cin 은 입력을 받을 때, 공백과 개행으로 구분 된다는 사실을 인지하자. 꼭
*/
