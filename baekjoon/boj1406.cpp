#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<char> editor;
    list<char>::iterator cursor;
    int count;  //명령의 개수. M
    char temp;  //P 명령을 받아올 임시 변수
    char tempo; //초기 문자열을 받아올 임시 변수

    //list 초기화
    while(1)
    {
        tempo=getchar();
        if(tempo=='\n')
            break;
        else
            editor.push_back(tempo);
    }
   
    //cursor 위치 초기화(문장의 맨 뒤)
    cursor = editor.end();    

    cin>>count;
    
    while(count!=0)
    {
        cin>>temp;
        if(temp=='L')
        {
            if(cursor==editor.begin());
            else cursor--;
            /* 이 코드도 굳이 이렇게 두개로 나누지 말고
                if(cursor!=editor.begin()) cursor--;
                처럼 하나로 줄일 수 있다.   */
        }
        else if(temp=='D')
        {
            if(cursor==editor.end());
            else cursor++;
        }
        else if(temp=='B')
        {
            if(cursor==editor.begin());
            else
            {
                cursor--;
                cursor=editor.erase(cursor);
            }
        }
        else if(temp=='P')
        {
            char t ;
            cin>>t;
            editor.insert(cursor, t);
        }
        count--;
    }
    for(auto i : editor)
        cout<<i;
}

/* stl list를 연습해볼 수 있는 아주 좋은 예제. */