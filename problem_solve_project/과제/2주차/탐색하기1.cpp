#include <stdio.h>
#include <iostream>

using namespace std;

/*
    문제 조건에 메모리 제한, 시간제한이 없으므로, 메모리와 로직에 시간복잡도에 대해서는 생각하지 않아도 됨.
    n은 1만이하, m은 1~1000 중 한 가지 수 이므로 int 형을 사용해도 된다.
*/

int findIndex(int arr[], int n, int m) // index 를 찾는 과정
{
    int idx = -1; // 인덱스 검색결과를 저장하는 변수 선언, 기본 값을 -1로 해서 못찾을 경우 -1을 반환할 수 있게 한다.

    // 선형탐색
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == m) // 일치 값을 찾았을 경우
        {
            // 해당 인덱스를 저장하고, 탐색을 종료한다.
            idx = i; // 인덱스를 저장함에 주의
            break;   // 반복문 탈출
        }
    }

    return idx; // 결과값 반환
}
int main()
{
    int n, m; // 각 변수는 문제에서 정의한 의미를 가진다.

    scanf("%d %d", &n, &m); // n, m 입력 받아오기

    int *arr = new int[n]; // n개의 요소를 저장할 배열 생성

    for (int i = 0; i < n; i++) // N개의 정수 입력
    {
        scanf("%d", &arr[i]);
    }
    int answer = findIndex(arr, n, m);
    printf("%d", answer); // 답 출력
    delete[] arr;
    return 0;
}