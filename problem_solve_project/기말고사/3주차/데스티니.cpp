#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

#define POINT pair<int, int>
using namespace std;

double getPointDistance(POINT p1, POINT p2)
{
    double x = (p1.first - p2.first) * (p1.first - p2.first);
    double y = (p1.second - p2.second) * (p1.second - p2.second);
    return sqrt(x + y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<POINT> points;
    vector<double> distances;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        POINT p = make_pair(x, y);
        points.push_back(p);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            POINT p1 = points[i];
            POINT p2 = points[j];
            double distance = getPointDistance(p1, p2);
            distances.push_back(distance);
        }
    }
    int dSize = distances.size();
    double min = distances[0];
    int cnt = 0;
    for (int i = 1; i < dSize; i++)
    {
        if (abs(min - distances[i]) < 0.01)
        {
            cnt++;
            continue;
        }
        if (min > distances[i])
        {
            cnt = 1;
            min = distances[i];
        }
    }

    printf("%.1f\n", min);
    printf("%d", cnt);

    return 0;
}