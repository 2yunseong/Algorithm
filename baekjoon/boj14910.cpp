#include <iostream>
#include <vector>
using namespace std;

bool isDesending(const vector<int>& vec, int length)    
{   
    if(length ==1 )//base case1 :1은 무조건 비선형함수
    return true;

    for(int i=0; i<length-1; i++)   //i+1까지 비교하려면...
    {                               //i<length-1
        if(vec[i]>vec[i+1])         
            return false ;
    }
    return true;
}

int main()
{
    vector<int> arr ;
    int temp; 
    int len ;
    do          //원소의 갯수를 모를때
    {
        cin>>temp;
        arr.push_back(temp);
    } while (getc(stdin)==' ');

    len = arr.size();   //원소의 갯수

    if(isDesending(arr, len))
        cout<<"Good";
    else
    {
        cout<<"Bad";
    }

    return 0 ;
    
        

}
