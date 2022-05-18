#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int LEVEL[4] = {1, 86, 172, 256};             // 각 레벨
const char* CODE[4] = {"00", "01", "10", "11"};     // 2 bit code 들
string minCodeResult; // 최소 변환 비용의 코드
int totalErrorMin = 99999999; // 최소 변환 비용

// target과 같은 레벨의 index를 찾는다.
int findSameLevelIdx(int target){
    for(int i=0; i<4; i++){
        if(target == LEVEL[i])
            return i;
    }
}

// 문제 조건에 따라 코드를 변환해 string으로 반환하는 함수
string changeCode(vector<int>& changeCode){
    string result = "";
    int changeCodeSize = changeCode.size(); 
    
    for(int i=0; i<changeCodeSize; i++){
        int idx = findSameLevelIdx(changeCode[i]); // change code 레벨 값의 인덱스를 찾는다.
        if(i==0){
            result += CODE[idx];
        } else{
            // 이전 코드와 같다면
            if(changeCode[i-1] == changeCode[i]){
                result +="0"; // 0만 붙임
            // 다르면
            } else { // 1 붙이고 코드 붙이기
                result +="1";
                result += CODE[idx];
            }
        }
    }
    // 결과 string으로 전달
    return result;
}

void dfs(int depth, int n, vector<int>& changeLevels, int w, vector<int>& imagePixels){
    // 기저 조건 : 깊이 까지 다 탐색했다면, 종료한다.
    if(depth == n){
        string codeResult = changeCode(changeLevels); // 만들어진 레벨 값으로 넣은 결과
        int imgPixSize = imagePixels.size(); // size 값
        int codeError = 0; // 레벨차
        int totalError = 0; // 레벨차 + 가중치 * 코드 길이
        
        // 레벨 차 구하기
        for(int i=0; i< imagePixels.size(); i++){
            codeError += abs(imagePixels[i] - changeLevels[i]);
        }

        // 총 에러 구하기
        totalError = codeError + w * int(codeResult.size());
        // 지금까지 최솟값보다 작으면 갱신해준다. 
        if(totalErrorMin > totalError){
            totalErrorMin = totalError;
            minCodeResult = codeResult;
        }
        return;
    }
    // 코드 변환을 DFS 로 전부 탐색 (백트래킹)
    // 1, 86, 172, 256 
    for(int i=0; i<4; i++){
        // 스택에 넣어주고,
        changeLevels.push_back(LEVEL[i]);
        // 다음 깊이 탐색
        dfs(depth+1, n, changeLevels, w, imagePixels);
        // 다음 깊이 탐색 완료시, pop
        changeLevels.pop_back();
    }
}

int main(){
    int n; // 이미지 수열의 길이
    int w; // 가중치
    vector<int> imagePixels ; // 이미지 픽셀들
    vector<int> changes; // dfs 함수에 넘겨줄 벡터
    cin >> n >> w; // 입력 받아오기

    // 이미지 픽셀 입력 받아오기
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        imagePixels.push_back(temp);
    }
    clock_t start = clock(); // 시간 측정
    
    dfs(0, n, changes, w, imagePixels); // dfs 실행

    // 답 출력
    cout << totalErrorMin << endl; 
    cout << minCodeResult << endl;

    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC); // 소요 시간 출력
    return 0;
}