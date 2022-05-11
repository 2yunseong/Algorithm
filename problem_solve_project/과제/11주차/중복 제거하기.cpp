#include <iostream>
#include <set>

#define NO_DUPLICATE "OK"
#define DUPLICATE "DUPLICATED"

using namespace std;

int main(){
    set<int> numSet;    // 집합을 저장할 배열
    set<int>::iterator iter; // 반복자. 
    int n;
    cin >> n; // 입력의 갯수

    for(int i=0; i<n; i++){
        int temp ; // 체크할 숫자
        cin >> temp;
        iter = numSet.find(temp); // 중복인지 체크하기 위한 find 메소드 사용
        // 중복인 경우
        if(iter != numSet.end()){
            cout<< DUPLICATE << endl; // 중복임을 출력
        }
        else{
            cout << NO_DUPLICATE << endl; // OK를 출력
            numSet.insert(temp); // 집합에 포함시킨다.
        }
    }

    return 0;
}