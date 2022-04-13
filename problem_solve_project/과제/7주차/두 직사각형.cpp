#include <iostream>

using namespace std;

int getArea(
    int la,
    int ra,
    int ta,
    int ba,
    int lb,
    int rb,
    int tb,
    int bb)
{
    int l = max(la, lb); // 두 좌표 중 제일 큰 값이 왼쪽 x값이 되어야 한다.
    int r = min(ra, rb); // 두 좌표 중 제일 작은 값이 오른쪽 x값이 되어야 함.
    int t = min(ta, tb); // 두 좌표 중 제일 작은 값이 위쪽 y값이 되어야 함.
    int b = max(ba, bb); // 두 좌표중 제일 큰 값이 아래쪽 y값이 되어야 함.

    // 이대로 구한다면, 서로 겹치지 않는 부분에서는 모순이 발생한다.
    // r은 l보다 커야 하며, t는 b보다 커야한다.
    if (l <= r && b <= t)
        return ((r - l) * (t - b)); // 조건에 만족하면 답을 구함.
    return 0;
}
void solve()
{
    int ax, ay, bx, by, px, py, qx, qy;
    // 필요한 좌표 입력 받기
    cin >> ax >> ay >> bx >> by >> px >> py >> qx >> qy;

    int la = min(ax, bx); // a 직사각형의 왼쪽 x 값
    int ra = max(ax, bx); // a 직사각형의 오른쪽 x 값
    int ta = max(ay, by); // a 직사각형의 위쪽 y 값
    int ba = min(ay, ay); // a 직사각형의 아래쪽 y 값

    int lb = min(px, qx); // b 직사각형의 왼쪽 x 값
    int rb = max(px, qx); // b 직사각형의 오른쪽 x 값
    int tb = max(py, qy); // b 직사각형의 위쪽 y 값
    int bb = min(py, qy); // b 직사각형의 아래쪽 y 값

    int answer = getArea(la, ra, ta, ba, lb, rb, tb, bb);

    cout << answer << '\n';
    return;
}

int main()
{

    int testCase; // testCase 입력받기
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        solve(); // 문제 해결을 위한 함수 호출
    }
    return 0;
}