#include <stdio.h>
#include <iostream>

using namespace std;

void solve(int data[], int n)
{
    // pass
    for (int i = 0; i < n; i++)
    {
        int min = data[i]; // i~ n-1 에서 최솟값이 될 값
        int minIdx = i;    // 최솟값을 가지는 요소의 index
        for (int j = i; j < n; j++)
        {
            // 최솟값 최신화
            if (min > data[j])
            {
                // 비교를 위한 최솟값과 함께 최솟값 Index 저장
                min = data[j];
                minIdx = j;
            }
        }
        // 최솟값과, 이번 pass index와 교환.
        int temp = data[i];
        data[i] = data[minIdx];
        data[minIdx] = temp;
    }

    // 선택 정렬이 완료된 데이터를 출력하는 과정
    for (int i = 0; i < n; i++)
    {
        printf("%d ", data[i]);
    }
}

int main()
{
    int n;
    int *data;
    scanf("%d", &n);   // 배열의 크기 입력
    data = new int[n]; // 동적 배열 생성

    // 입력 받아오기
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
    }

    solve(data, n);
    delete[] data;
    return 0;
}