#include <iostream>

using namespace std ;

int main()
{
    int Gan[11]={0,0,1,2,3,4,5,6,7,8,9};//0:trash
    char Zi[14]="ZABCDEFGHIJKL";    //0:trash(bad value) 13:null

    int count = 0;
    int gan_idx = 7 ;
    int zi_idx = 9;
    int year ;

    cin>>year;  //input 

    while(count!=year)
    {
        gan_idx++;
        zi_idx++;
        if(gan_idx>10)
            gan_idx = 1 ;
        if(zi_idx>12)
            zi_idx = 1 ;

        count++;
    }

    cout<<Zi[zi_idx]<<Gan[gan_idx]<<endl;

    return 0 ;
    
}
