#include <iostream>
using namespace std ;
//Kn+Pn^2
//K*((sigma t)+P(sigma t^2)
//=K*((n*(n+1))/2)+P((n*(n+1)*(2n+1))/6)
int main()
{
    int lovely ; //K
    int addiction;//P
    int year; 
    cin>>year>>lovely>>addiction;

    int sigma_t = (year * (year+1)) / 2;
    int sigma_doublet = (year*(year+1)*(2*year+1))/6;

    int answer = lovely*sigma_t + addiction*sigma_doublet;

    cout<<answer;

    return 0 ;

}