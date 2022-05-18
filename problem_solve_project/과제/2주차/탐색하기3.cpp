#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void solve(int data[], int n)
{
    int sum = 0;            // 1번부터 n번까지(번호) 시그마 한 값
    int *dist = new int[n]; // data[i]*n - s 의 절댓값을 담는다.
    int idx = -1;           // 인덱스가 배열의 인덱스가 아닌, 번호임에 주의.

    for (int i = 0; i < n; i++)
    {
        sum += data[i];
    }

    // data[i]*n - s 로 평균으로부터 얼마나 떨어져 있는지 구한다.
    for (int i = 0; i < n; i++)
    {
        dist[i] = abs(data[i] * n - sum);
    }

    int min = dist[0]; // 최솟값을 구하기 위한 min
                       // dist 가 최소인 값을 가지는 index 를 구해오면 된다.
    for (int i = 0; i < n; i++)
    {
        if (min > dist[i])
        { // 최솟값을 발견하면 최신화 해준다.
            min = dist[i];
            idx = i;
        }
    }
    printf("%d %d", idx + 1, data[idx]); // 값 출력 idx + 1임에 주의
    delete[] dist;                       // 동적배열 해제
}

int main()
{
    // 필요한 변수 선언
    int n;
    int *data;

    scanf("%d", &n); // 갯수 입력
    data = new int[n];

    for (int i = 0; i < n; i++) // 배열 데이터 입력
    {
        scanf("%d", &data[i]);
    }

    solve(data, n); // 해결 메소드 호출

    delete[] data;
    return 0;
}