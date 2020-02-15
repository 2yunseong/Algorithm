#include <iostream>
#include <vector>
using namespace std;

bool isDesending(const vector<int>& vec, int length)    
{   
    if(length ==1 )//base case1 :1�� ������ �����Լ�
    return true;

    for(int i=0; i<length-1; i++)   //i+1���� ���Ϸ���...
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
    do          //������ ������ �𸦶�
    {
        cin>>temp;
        arr.push_back(temp);
    } while (getc(stdin)==' ');

    len = arr.size();   //������ ����

    if(isDesending(arr, len))
        cout<<"Good";
    else
    {
        cout<<"Bad";
    }

    return 0 ;
    
        

}
