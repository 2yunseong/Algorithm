#include <iostream>

using namespace std;

int arr[7];
int main()
{
    int min = 987654321;
    int sum = 0;
    
    for(int i=0; i<7; i++)
        cin>>arr[i];
    
    for(int i=0; i<7; i++)
    {
        if(arr[i]%2==0)
            continue;
        else
        {
            sum+=arr[i];
            if(min>arr[i])
                min = arr[i];
        }        
    }
    if(sum==0)
        cout<<-1;
    else
        cout<<sum<<'\n'<<min;
    
    return 0;
}