#include <iostream>
#include <vector>
#include <set>
#include <ctime>

using namespace std;
bool isVisited[10] = {false}; // 인덱스가 아닌, 숫자로 접근한다.

// 각 꼭짓점의 연결상태를 확인하는 함수
// 해당 함수를 통해서 각 꼭짓점 끼리 연결될 수 있는지 확인한다.
bool isVertexConnect(int start, int end){
    int calc = start + end;
    bool canConnect = false;
    if(calc == 4){
        canConnect = isVisited[2];
    } else if(calc == 8){
        canConnect = isVisited[4];
    } else if(calc == 10){
        canConnect = isVisited[5];
    } else if(calc == 12){
        canConnect = isVisited[6];
    } else if(calc == 16){
        canConnect = isVisited[8];
    }
    return canConnect;
}

// 마주보는 변인지를 검사하는 함수
// 마주보는 변끼리는 서로 더하면 10이 나오는 특성이 있다.
bool isSideConnect(int start, int end){
    int calc = start + end ;
    if(calc == 10){
        return true;
    }
    return false;
}

int main(){
    int patternLength; // 패턴의 길이
    cin >> patternLength;
    vector<int> patterns; // 패턴을 저장할 배열

    // 각각의 패턴 번호가 속해 있는 특징에 따라 분류
    set<int> vertex ; // 꼭짓점인 점들 (정사각형에서)
    set<int> side; // 변인 점들
    int mid = 5; // 중간 점들
    bool isPatternRight = true; // 패턴이 올바른지 판단

    for(int i=0; i<patternLength; i++){
        int temp ;
        cin >> temp;
        patterns.push_back(temp);
    }
    clock_t start = clock(); // 실행시간 측정
    //패턴의 길이가 3 아래이면, 패턴이 아니다.
    if(patternLength < 3){
        cout << "NO" << '\n';
        return 0;
    }

    // 각 점들을 특징으로 분류
    for(int i=1; i<=9; i++){
        if(i==5) continue;
        else if(i%2 ==0){
            side.insert(i);
        } else{
            vertex.insert(i);
        }
    }

    // 패턴 순회 시작
    for(int i=0; i<patternLength; i++){
        // 방문 하지 않은 점이라면
        if(!isVisited[patterns[i]]){
            isVisited[patterns[i]] = true; // 방문했다는 표시를 남기고
            // 마지막 점이라면 종료.
            if(i == patternLength-1){
                break;
            }
            // 해당 점이 어떤 특징을 가지는지 본다.

            // 꼭지점이라면
            if(vertex.count(patterns[i]) > 0){
                // 다른 꼭짓점을 지날 때는, 지나는 선이 이미 isVisited 가 true인지 확인해야 한다.
                if(vertex.count(patterns[i+1]) > 0){
                    if(isVertexConnect(patterns[i], patterns[i+1])){
                        continue;
                    } else {
                        isPatternRight = false;
                    }
                }   
                // 꼭짓점이 아닌 점은 바로 다음 점으로 방문 가능하다. 
                else{
                    continue;
                }
                
            }
            // 변 이라면 
            else if (side.count(patterns[i]) > 0){
                // 마주 보는 변을 지나려면 반드시 mid 를 거쳐야 한다.
                // 따라서, isVisited[5]가 false이면, 잘못된 패턴
                if(side.count(patterns[i+1]) > 0){
                    if(isSideConnect(patterns[i], patterns[i+1])){
                        if(!isVisited[mid]){
                            isPatternRight = false; // 표시
                            break;
                        }
                    }
                }
            }
            // 중앙점이라면 무조건 방문 가능하다. 따라서 로직을 적지 않고 다음으로 지난다.
        } else { // 이미 방문 했던 점이라면 
            isPatternRight = false; // 표시
            break;
        }
    }

    if(isPatternRight){
        cout << "YES" << endl;
    } else {
         cout << "NO" << endl;
    }
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC); // 소요 시간 출력
    return 0;
}