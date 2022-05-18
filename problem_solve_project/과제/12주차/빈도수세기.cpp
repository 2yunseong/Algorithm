#include <iostream>
#include <map>

using namespace std;

int main(){
    map<int,int> m ; // map 생성
    int n;  // 숫자 받아오기
    cin >> n; // n 입력 받기 

    for(int i=0; i<n; i++){
        int temp;   // 입력받기 위한 변수
        cin >> temp; // 숫자 입력 받기
        m[temp]++; // 카운트 해주기
        // 조건에 맞게 출력
        cout << m.size() << ' ' << m[temp] << '\n';
    }
    
    return 0;
}