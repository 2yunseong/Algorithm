#include <iostream>

using namespace std;

// 픽셀이 문제의 조건에 따라 원 내부에 있는지 판단하는 함수
bool isInside(long long x, long long y, long long R)
{
    // x^2 + y^2 < R^2 가 성립하면, 좌표가 원의 내부에 있을 것이다.
    long long sqd = x * x + y * y; // 먼저 비교할 원의 방정식을 구해준다.
    if (sqd < R * R)               // 만약 맨 위의 주석의 식이 성립한다면, 픽셀이 원 안에 있는 것이다.
        return true;               // 따라서 true를 리턴해준다.
    return false;
}

void testcase(int caseIndex)
{
    long long R;
    cin >> R;
    long long sum = 0; // 1 사분면의 픽셀의 갯수
    long long y = R;
    for (long x = 0; x <= R; x++)
    {
        long long height = 0;
        for (; y >= 0; y--)
        {
            if (isInside(x, y, R))
            {

                height = (y + 1);
                break;
            }
        }

        sum += height;
    }
    cout << "#" << caseIndex << '\n';
    cout << sum * 4 << '\n';
}
int main()
{
    int caseSize;
    cin >> caseSize;

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
    {
        testcase(caseIndex);
    }
    return 0;
}