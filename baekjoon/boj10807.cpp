#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int N;
    int ans_count=0;
    int v;
    cin>>N;
    int* x = new int[N];
    for(int i=0; i<N; i++)
        cin>>x[i];
    cin>>v;
    for(int i=0; i<N; i++)
        if(v==x[i])ans_count++;
    cout<<ans_count;
    
    delete[] x;
    return 0;
}
