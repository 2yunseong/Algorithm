#include <iostream>

using namespace std;

int main()
{
    int n;                      // 도토리의 숫자
    int *heights = new int[n];  // i번째 도토리들의 키를 담는 배열
    int *birthArr = new int[n]; // i번째 도토리들의 생일을 저장하는 배열
    int targetMonth;            // 현재 월을 의미
    int answer = -1;            // 답의 기본값은 -1. 결과가 없을 시, -1을 출력하므로.

    // 문제의 정의에 맞는 입력 받아오기
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    for (int i = 0; i < n; i++)
        cin >> birthArr[i];
    cin >> targetMonth;

    // n-1 부터 0 까지 탐색하는 반복문(반개구간 사용.)
    for (int i = n - 1; i > -1; i--)
    {
        // 만약 생일 월이 현재 달과 같으면, 답을 저장하고 종료한다.
        if (birthArr[i] == targetMonth)
        {
            answer = heights[i];
            break;
        }
    }

    // 답을 출력한다.
    cout << answer << '\n';

    delete[] birthArr;
    delete[] heights;
    return 0;
}