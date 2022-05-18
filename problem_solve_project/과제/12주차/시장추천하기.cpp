#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n; // 참여 선거인 수
    cin >> n; // 입력 받아오기
    map<string,int> m; // 투표 수를 저장할 매핑 테이블
    map<string,int>::iterator iter; // 순회하기 위해 사용할 반복자
    int maxVote = -1; // 최다 득표자
    
    for(int i=0; i<n; i++){
        string vote;
        cin >> vote;
            m[vote]++; // 투표수를 늘린다.
    }

    // 최다 득표 수 찾기
    for(iter = m.begin(); iter != m.end(); iter++){
        if(iter->second > maxVote){
            maxVote = iter->second;
        }
    }
    cout << maxVote << endl; // 최다 득표수 출력

    // 최다 득표자들 찾기
    for(iter = m.begin(); iter != m.end(); iter++){
        // 최다 득표자의 득표수가 최다 득표수와 같다면
        if(iter->second == maxVote){
            // 출력하기
            cout << iter->first << ' ';
        }
    }
    cout << endl;
    // 최다 득표자 이름 출력

    return 0;
}