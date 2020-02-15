#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    int sum = 0;
    cin>>a;
    cin>>b;
    cin>>c;
    sum = a+b+c;

    if(sum==180)
    {
        if(a==b && c==60) // Equilateral
        {
            cout<<"Equilateral";
            return 0;
        }
        if(a==b || b==c || c==a)
        {
            cout<<"Isosceles";
        }
        else
            cout<<"Scalene";
    }
    else //sum > 180 or sum < 180
    {
        cout<<"Error";
    }

    return 0 ;
}
