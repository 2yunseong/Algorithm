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

int yunseong[10];

void show_array(const int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}

int book(int n)
{

}

int main()
{
    int n=11000;
    book(n);
    show_array(yunseong, 10);
    return 0;
}

//입력 값이 10억이므로 하나하나 다 조사하면 메모리 초과, 런타임 오류가 날 수 밖에 없음.
//다른 알고리즘 고안.


/*

각각의 숫자가 나온 횟수를 저장하는 배열을 arr라 하자.

또 변수가 t라고 하고, 각각의 자리n의 숫자의 수열을 a_n 이라고 하면,

t = a\_(n-1) * 10^(n-1)+a\_(n-2)*10^(n-2) + ... + a\_0*10^0 
점화식을 구해, 재귀적으로 풀어보자.

n=1 일때, f(1) 의 내용은 다음과 같다.

i=0부터 a_0까지 arr[i]+=(10^0);
n=2 일때,

f(1)호출
i=0부터 a_1까지 arr[i]+=(a_0)

*/
