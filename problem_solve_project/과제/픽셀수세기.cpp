#include <iostream>

using namespace std;

// 픽셀이 문제의 조건에 따라 원 내부에 있는지 판단하는 함수
bool isInside(long long x, long long y, long long R)
{
    // x^2 + y^2 < R^2 가 성립하면, 좌표가 원의 내부에 있을 것이다.
    long long sqd = x * x + y * y; // 먼저 비교할 원의 방정식을 구해준다.
    if (sqd < R * R)               // 만약 맨 위의 주석의 식이 성립한다면, 픽셀이 원 안에 있는 것이다.
        return true;               // 따라서 true를 리턴해준다.
    return false;                  // 아니면 false 리턴.
}

// 각 테스트 케이스 시행하는 함수.
// 원의 원점을 0,0으로하고, 각 사분면으로 쪼개면, 각 사분면이 모두 대칭임을 알 수 있다.
// 따라서, 1사분면의 값만 비교한 뒤, 곱하기 4를 해준다.
void testcase(int caseIndex)
{
    long long R;       // 원의 반지름을 저장해주는 함수.
    cin >> R;          // 원의 반지름을 입력받는다.
    long long sum = 0; // 1 사분면의 픽셀의 갯수
    long long y = R;   // x=0 일때, y는 R이다. 이는 자명하다.
    // 각 픽셀이 어느정도 높이인지 구해준다.
    for (long x = 0; x <= R; x++)
    {
        long long height = 0; // x 값마다 height 는 초기화가 되어야 한다.
        // y=0 이 될때 까지, 1 사분면의 값만 비교하므로, 0 이하는 필요가 없다.
        // x에서 가장 y값이 큰 픽셀, 즉, 높이를 구하면 된다. 왜냐하면 그 점만 구하면, 아래 작은 값들은 다 원에 포함됨이 자명하기 때문이다.
        for (; y >= 0; y--)
        {
            // 가장 큰 높이를 가진 픽셀을 구했다면,
            if (isInside(x, y, R))
            {
                height = (y + 1); // 1을 더해준다. 그 이유는 픽셀이 걸쳐있기 때문이다.
                break;            // 반복문 종료후
            }
        }
        // 그리고 높이를 더해준다.
        sum += height;
    }
    // 결과값 출력
    cout << "#" << caseIndex << '\n';
    cout << sum * 4 << '\n'; // 1사분면만 구했으므로 4를 곱해준다.
}
int main()
{
    int caseSize; // testcase의 갯수
    cin >> caseSize;

    // 각 testcase를 돌려준다.
    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
    {
        testcase(caseIndex);
    }
    return 0;
}