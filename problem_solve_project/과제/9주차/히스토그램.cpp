#include <iostream>
#include <vector>
#include <stack>
#include <cmath>


using namespace std;

// 히스토그램 클래스 선언
class Histogram{
    public:
    int height; // 높이 
    int leftX; // 왼쪽 인덱스
    int rightX; // 오른쪽 인덱스
    Histogram(){

    }

    // 히스토그램 초기화
    Histogram(int index, int height){
        this->leftX = index;
        this->rightX = this->leftX + 1;
        this->height = height;
    }
}; 

// 가장 큰 직사각형을 구하는 로직
long long getLargestRectangleArea(const vector<Histogram>& histograms){
    long long answer = 0;   // 답
    stack<Histogram> stk;   // 히스토그램의 길이를 구할 스택

    stk.push(Histogram(-1, 0)); // 먼저 왼쪽에 가상의 히스토그램(높이 : 0)을 삽입해준다.
    // 히스토그램 사이즈 만큼 반복
    for(int i=0; i < histograms.size() + 1; i++){
        Histogram h;
        if(i < histograms.size()){
            h = histograms[i];
        } else {
            h = Histogram(histograms.size(), 0);
        }
        
        // 넓이를 구하는 로직
        // 스택에 저장된 사이즈가 1보다 크고 스택에 저장된 height 가 지금 height 보다 큰 경우
        while(stk.size() > 1 && stk.top().height > h.height){
            Histogram lh = stk.top(); // 왼쪽 히스토그램
            stk.pop();          // 왼쪽 제거

            Histogram bh = stk.top(); // 오른쪽 히스토그램 

            long long width = abs(h.leftX - bh.rightX); // 직사각형의 너비 구하기
            long long height = lh.height; // 높이는 기준을 잡은 lh 히스토그램
            long long area = width * height;  // 넓이 구하기

            answer = max(answer, area); // 최댓값이면 갱신
        }
        
        stk.push(h);   // 스택에 push
    }
    
    return answer;
}  
void process(int caseIndex){
    // bar 갯수 받아오기
    int n;
    cin >> n;

    vector<Histogram> histograms; // 히스토그램 각각의 bar를 저장할 변수 사용
    // 바의 갯수만큼 히스토 그램 생성
    for(int i=0; i<n; i++){
        int height;
        cin >> height;
        histograms.push_back(Histogram(i, height));
    }

    // 답이 될 answer 호출
    long long answer = getLargestRectangleArea(histograms);
    cout << answer << endl;
}

int main(){ 
    // caseSize 입력
    int caseSize;
    cin >> caseSize;

    
    // 답을 구하는 반복문 출력
    for(int caseIndex = 1; caseIndex <= caseSize; caseIndex +=1){
        process(caseIndex);
    }
    
    return 0;
}