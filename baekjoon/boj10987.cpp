#include <iostream>
#include <cstring>
using namespace std; 


bool Checkvowel(char x) 
{
    if(x=='a')
        return true;
     if(x=='e')
        return true;
     if(x=='i')
        return true;
     if(x=='o')
        return true;
     if(x=='u')
        return true;
    return false;
}
int main()
{
    char arr[101] ;
    cin>>arr;
    int len = strlen(arr);
    int vowelcount = 0 ;

    for(int i=0; i<len; i++)
    {
        if(Checkvowel(arr[i])==true)
            vowelcount++;
    }

    cout<<vowelcount;

    return 0 ;
}