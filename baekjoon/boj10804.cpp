#include <iostream>

using namespace std;

void reverse(int arr[], int a, int b)
{
    int temp;
    int n = (b-a+1)/2;
    for(int i=0; i<n; i++)
    {
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        a++;
        b--;
    }
}
int main()
{
    int arr[21];
    int count = 10;
    int a,b;
    for(int i=0; i<21; i++)
        arr[i] = i ;
    
    while(count)
    {
        cin>>a>>b;
        reverse(arr,a,b);
        count--;
    }

    for(int i=1; i<21; i++)
        cout<<arr[i]<<' ';

    return 0;
}