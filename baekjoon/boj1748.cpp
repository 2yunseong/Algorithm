#include <iostream>

using namespace std;

int main()
{
    int n ;
    int answer = 0;
    cin>>n;
    
    for(int i=1; i<n+1; i++) //[1,n]
    {
        int temp = i;
        int check_digit = 0;
        do
        {
            temp /=10;
            check_digit++;
        } while(temp!=0);
    answer+=check_digit;
    }
    cout<<answer;

    //시간 복잡도 O(n)보다 조금! 큼
    //단 n의 최대가 1억이므로 수행시간 안에 들어온다.
    //간당간당하긴함.
    return 0;
}
