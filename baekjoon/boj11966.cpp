#include <iostream>
using namespace std;

bool isTwoSquarenum(int num)
{
    //base case1: num == 2
    if(num == 2)
        return true;
    else
    {
    if(num%2==0)
        {
            num /=2 ;
            return isTwoSquarenum(num);
        }
    else //base case 2: it's not 2's square number n%2 == 1 
    {
        return false; 
    }
    
    }
}
int main()
{
    int num ; // 1<=N<=2^30 max int size = 2^31 (ignore msb)

	cin >>num; 
    if(num == 1 )
    {
        cout<<num;
        return 0 ;
    }
    else
    {
    if(isTwoSquarenum(num))
        cout<<1;
    else
        cout<<0;
    
    }

        return 0 ;
}
