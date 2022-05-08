#include <iostream>
#include <vector>

#define INCOME_MAX 1100000000 // 가질수 있는 수익의 최댓값의 이상치
using namespace std;


void testCase(int testIndex){
    int n, k;
    int answerMax ; // 답이 될 소득차의 최댓값

    cin >> n >> k;
    vector<int> citys;  // 도시들의 소득을 받아올 배열
    
    // 도시들의 소득 받아오기
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        citys.push_back(temp);
    }
    
    // 소득 구간을 돌 반복문. i는 소득구간의 각 첫 요소의 인덱스를 나타낸다.
    for(int i=0; i<n-k+1; i++){
        // 지금 구간의 최대소득, 최소소득 값을 임시로 저장할 변수
        int incomeMax = -1;
        int incomeMin = INCOME_OVERMAX;
        // 지금 구간의 도시들의 소득을 검사
        for(int j=0; j<k; j++){
            // 최대값 갱신
            if(citys[j] > incomeMax){
                incomeMax = citys[j];
                continue;
            }
            // 최소값 갱신
            if(citys[j] < incomeMin){
                incomeMin = citys[j];
                continue;
            }
        }
        // 받아온 구간의 최대, 최솟값으로 격차 계산
        int intervalDiffer = incomeMax - incomeMin;
        // 격차가 최대일 경우 답 갱신 
        if(intervalDiffer > answerMax){
            answerMax = intervalDiffer;
        }
    }
    
    cout << answerMax << '\n'; // 답 출력
}
int main(){
    // test Case 받아오기
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        testCase(i);
    }

    return 0;
}