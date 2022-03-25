#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class Point2D
{
private:
    int x;
    int y;

public:
    Point2D(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }

    double getSquaredDistanceTo(const Point2D &target) const
    {
        double dx = abs(this->x - target.x);
        double dy = abs(this->y - target.y);
        return dx * dx + dy * dy;
    }
};

int main()
{
    int testCase;
    Point2D *points;
    double minPointDistance = numeric_limits<double>::max();
    int minCount = 0;

    cin >> testCase;                // testCase 갯수
    points = new Point2D[testCase]; // 동적할당

    // 각 점 입력 받아오기
    for (int i = 0; i < testCase; i++)
    {
        int x, y;
        cin >> x >> y;
        points[i] = Point2D(x, y);
    }

    // 각 점들의 거리 비교
    for (int i = 0; i < testCase; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double pointDistance = points[i].getSquaredDistanceTo(points[j]);
            if (pointDistance < minPointDistance)
            {
                minPointDistance = pointDistance;
                minCount = 1;
            }
            else if (pointDistance == minPointDistance)
            {
                minCount++;
            }
        }
    }
    double answer = sqrt(minPointDistance);
    printf("%.1f\n", answer);
    printf("%d\n", minCount);

    delete[] points;
    return 0;
}