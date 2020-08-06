#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

//ASCII
/*
    0 : 48
    1 : 49
    ...
    9 : 57
*/

int count[10];

void show_array(const int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

int book(int n)
{
    if(n==1)       //base condition
    {
        count[1]++;
        return 0;        
    }
    else
    {
        string str;
        str=to_string(n);    //change int -> string
        for(int i=0; i<str.size(); i++)     //count 
        {
            int idx;
            idx = str[i]-48;    //char ->int change 
            count[idx]++;       
        }
        
        book(n-1);
    }  
}

int main()
{
    int n=11000;
    book(n);
    show_array(count, 10);
    return 0;
}

//메모리 초과뜸.. 아마 변수 할당에서 문제가 되는듯 함.
//동적할당으로 그때그때마다 해제해줄 것.
