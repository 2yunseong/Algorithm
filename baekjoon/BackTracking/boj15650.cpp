#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &v){
    int vSize = v.size();
    for(int i=0; i<vSize; i++){
        cout << v[i] << ' ';
    }
    cout << '\n';
}
void pick(int start, int m, int n, vector<int>& v){
    if(m == 0 ){
        printVector(v);
        return ;
    }
    for(int i = start; i <= n; i++){
        v.push_back(i);
        pick(i+1, m-1, n, v);
        v.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    vector<int> v;
    cin >> n >> m;
    
    pick(1, m, n, v);
    
    return 0;
}