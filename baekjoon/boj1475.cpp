#include <iostream>
#include <string>

using namespace std;

/*
1.세트당 0~9번까지 있다
2.6은 9를 뒤집어서, 9는 6을 뒤집어서 사용가능
ex)23678 1 1 1 1 1 이므로 1개 사용가능
ex) 6 or 9 1개 -> 1 set
2p -> 1set
3p-> 2set
4p-> 2set
5p = 2*3-1

np = 2*x-1
n+1 = 2x
x = (n+1)/2
*/

int main()
{
    int set_table[10]={0};
    int six_nine = 0;
    int max = -1;
    string str;
    cin>>str;
    for(int i=0; i<(int)str.size(); i++)
    {
        string temp;
        temp = str[i];
        set_table[str[i]-48]++;
    }

    //9,6 처리 하기(세트 구하기)
    six_nine = set_table[6]+set_table[9];
    if(six_nine%2==0)   //짝수이면
        set_table[6] = (six_nine/2);
    else    //홀수면
        set_table[6]=(six_nine+1)/2;
    
    //set-table을 효율적으로 사용하기 위해 set_table[9] 무시
    for(int i=0; i<9; i++)
    {
        if(max<set_table[i])
            max = set_table[i];
    }
    cout<<max;
    
    return 0;
}