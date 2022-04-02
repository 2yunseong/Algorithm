#include <iostream>

using namespace std;

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

// Paint 이벤트를 정의할 클래스
class Painting
{
    // 저장할 변수 선언
public:
    int left;
    int right;
    int color;

    // 생성자들
    Painting() {}

    Painting(int left, int right, int color)
    {
        this->left = left;
        this->right = right;
        this->color = color;
    }
};

// 문제 해결 함수
void solve(int n, int m, const Painting *paintings)
{
    int *seats = new int[n]; // 좌석의 배열 동적할당
    // 처음 좌석들은 모두 0번으로 칠해져 있다.
    for (int i = 0; i < n; i++)
    {
        seats[i] = 0;
    }

    // 색칠 정보를 바탕으로, 각 좌석을 색칠함.
    for (int i = 0; i < m; i++)
    {
        const Painting &p = paintings[i]; // 방법을 차례대로 하나씩 불러온 후에,
        // 좌석에 색칠해준다. 범위 : [left, right]
        for (int j = p.left; j <= p.right; j++)
        {
            seats[j] = p.color;
        }
    }

    // 각 색상이 몇번 나왔는지 담는 테이블
    int *table = new int[MAX_COLOR_NUMBER];

    // 모두 0으로 초기화 해준다음,
    for (int i = 0; i < MAX_COLOR_NUMBER; i++)
    {
        table[i] = 0;
    }

    // 좌석의 색상을 카운트 한다.
    for (int i = 0; i < n; i++)
    {
        table[seats[i]]++;
    }

    int minColor = seats[0]; // 가장 적게 나온 색상
    int maxColor = seats[0]; // 가장 빈번하게 나온 색상

    // table을 돌면서 색상을 센다.
    for (int color = 0; color < MAX_COLOR_NUMBER; color++)
    {
        // 한번도 안 나온 색상일 경우, 넘어간다.
        if (table[color] == 0)
        {
            continue;
        }

        // 최솟값 갱신
        if (table[minColor] > table[color])
        {
            minColor = color;
        }

        // 최댓값 갱신
        if (table[maxColor] < table[color])
        {
            maxColor = color;
        }
    }

    // 정답 출력
    cout << maxColor << '\n'
         << minColor << '\n';

    // 동적할당 해제
    delete[] table;
    delete[] seats;
}
int main()
{
    int n; // 좌석의 수
    int m; // 색칠할 방법
    cin >> n >> m;

    Painting *paintings = new Painting[n];
    // 방법 입력으로 받아오기
    for (int i = 0; i < m; i++)
    {
        cin >> paintings[i].left >> paintings[i].right >> paintings[i].color;
        // 좌석의 인덱스와 배열의 인덱스를 맞추어주는 과정
        paintings[i].left -= 1;
        paintings[i].right -= 1;
    }

    solve(n, m, paintings);
    delete[] paintings;
    return 0;
}