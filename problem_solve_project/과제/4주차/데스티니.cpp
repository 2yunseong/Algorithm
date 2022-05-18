#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// 좌표 평면 클래스
class Point2D
{
    // x, y 값
private:
    int x;
    int y;

public:
    // 생성자로 초기화
    Point2D(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    // 두 좌표의 거리를 구하는 공식을 이요해, 거리의 제곱값을 구한다.(x1-x2)^2 + (y1-y2)^2
    double getSquaredDistanceTo(const Point2D &target) const
    {
        double dx = abs(this->x - target.x);
        double dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }
};

int main()
{
    int testCase;                                            // testcase 숫자
    Point2D *points;                                         // 각 점들을 저장할 Point2D 배열
    double minPointDistance = numeric_limits<double>::max(); // 거리의 최솟값을 저장하는 변수
    int minCount = 0;                                        // 최솟값의 갯수

    cin >> testCase;                // testCase 갯수
    points = new Point2D[testCase]; // 동적할당

    // 각 점 입력 받아오기
    for (int i = 0; i < testCase; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = Point2D(x, y); // points 에 저장
    }

    // 중첩 반복문을 통한 모든 점끼리의 거리 비교
    for (int i = 0; i < testCase; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double pointDistance = points[i].getSquaredDistanceTo(points[j]); // i 점과 j 점의 거리 계산
            // 최솟값일 경우
            if (pointDistance < minPointDistance)
            {
                minPointDistance = pointDistance; // 갱신 후
                minCount = 1;                     // 갱신 되었으므로 최솟값은 1개
            }
            else if (pointDistance == minPointDistance) // 최솟값이 같다면
            {
                minCount++; // 카운트 증가
            }
        }
    }
    double answer = sqrt(minPointDistance); //루트를 씌워 거리 계산
    printf("%.1f\n", answer);               // 소숫점 첫번째자리까지 출력
    printf("%d\n", minCount);               // 카운트 출력

    delete[] points;
    return 0;
}