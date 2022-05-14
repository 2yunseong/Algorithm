#include <iostream>
#include <vector>
#define UP -3
#define DOWN 3
#define LEFT -1
#define RIGHT 1
#define LEFT_UP -4
#define LEFT_RIGHT 2
#define RIGHT_UP -2
#define RIGHT_DOWN 4

using namespace std;

int directions[8] = {UP, DOWN, LEFT, RIGHT, LEFT_UP, LEFT_RIGHT, RIGHT_UP, RIGHT_DOWN};

bool isOutRange(int target, int direction){
    int next = target;
    if(target + direction < 1 && target + direction > 9) return true;
    return false;
}

int main(){
    int patternLength; // 패턴의 길이
    cin >> patternLength;
    vector<int> patterns; // 패턴을 저장할 배열
    bool isVisited[10] = {false};
    // 패턴 입력 받기
    for(int i=0; i<patternLength; i++){
        int temp ;
        cin >> temp;
        patterns.push_back(patterns);
    }

    //패턴의 길이가 3 아래이면, 패턴이 아니다.
    if(patternLength < 3){
        cout << "NO" << '\n';
        return 0;
    }

    

    return 0;
}