#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

class Point2D{
    public:
        int x;
        int y;
        int index;
        // 생성자
        Point2D(int index, int x, int y){
            this->index = index;
            this->x = x;
            this->y = y;
        }
        // 생성자
        Point2D(int x, int y){
            this->index = 1;
            this->x = x;
            this->y = y;
        }
        // 두 점 사이의 거리 구하기.
        long long getSquaredDistanceTo(Point2D target){
            long long dx = abs(this->x - target.x);
            long long dy = abs(this->y - target.y);

            return dx * dx + dy * dy;            
        }
        // set 컨테이너가 사용할 비교 연산.
        bool operator < (const Point2D& other) const {
            if(this->x != other.x){
                return this->x < other.x;
            }
            return this->y < other.y;
        }
};

long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0; // 답 : 정사각형의 넓이

    set<Point2D> pSet; // 점들을 넣을 집합.
    // 점들을 집합에 삽입.
    for(int i=0; i < n; i++){
        pSet.insert(points[i]);
    }

    // 임의의 두 점을 잡는다.
    for(int i=0; i< n; i++){
        Point2D pa = points[i];
        for(int j=0; j < n; j++){
            Point2D pb = points[j];
            
            if(i==j) continue; // 같은 점은 제외하고 생각한다.

            long long area = pa.getSquaredDistanceTo(pb); // 정사각형 : 한 변의 제곱.

            if(area < answer) continue; // area가 answer 값보다 작다면, 이후 과정을 할 필요가 없다.
            
            // 정사각형인지 아닌지 판단을 해야한다.
            // 그러기 위해서 그림을 그려보면, 두점의 거리 차인 dx, dy 만큼 다른 점들이 일정하게 차이가 남을 알 수 있다.
            long long dx = pb.x - pa.x; // 수업에서 한 것 처럼 다른 점을 구하기
            long long dy = pb.y - pa.y; // 수업에서 한 것 처럼 다른 점을 구하기

            // 점을 생성
            Point2D pd(pa.x - dy, pa.y + dx); 
            Point2D pc(pb.x - dy, pb.y + dx);
            
            // 해당 점이 집합에 존재한다면, answer를 갱신한다.
            if(pSet.count(pc) > 0 && pSet.count(pd) > 0){
                answer = max(area, answer);
            }
        }
    }

    return answer; // 최종 답 리턴

}

void process(int caseIndex){
    int n;
    cin >> n; // 점의 갯수 입력 받기 
    vector<Point2D> points; // 점을 담을 배열
    
    // 점 입력 받기
    for(int i=0; i < n; i++){
        int x,y;
        cin >> x >> y;
        points.push_back(Point2D(i, x, y));
    }

    double answer = getMaximumSquareArea(n, points); // 답 구하기

    printf("%.2f\n", answer); // 답 출력하기
    return ;
}
int main(){
    int testCase;   // testcase
    cin >> testCase;

    // testcase 당 프로세스 실행
    for(int i=0; i<testCase; i++){
        process(i);
    }
    return 0;
}