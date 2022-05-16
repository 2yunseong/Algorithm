#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    stack<long long> s;
    long long count = 0;

    cin >> n;
    
    for(int i=0; i<n; i++){
        long long temp ;
        cin >> temp;
        if(i==0){
            s.push(temp);
            continue;
        }
        if(s.top() > temp){
            count += s.size();
            s.push(temp);
        } else{
            while(!s.empty()){
                if(temp >= s.top()){
                    s.pop();
                } else {
                    count += s.size();
                    break;
                }   
            }
            s.push(temp);
        } 
    }

    cout << count << endl;

    return 0;
}