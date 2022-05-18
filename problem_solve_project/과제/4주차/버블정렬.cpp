#include <iostream>

using namespace std;

int main()
{
    int n;            // 배열의 갯수
    cin >> n;         // 배열의 갯수 입력받기
    int *arr;         // 정렬할 배열
    arr = new int[n]; // 동적 할당
    // 배열 요소 입력 받기
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    // 버블정렬. i는 각 pass를 의미한다.
    for (int i = 0; i < n; i++)
    {
        int count = 0; // 가지치기를 위한 교환 카운트
        // 문제의 조건에 따라 ...
        // 배열의 0번칸의 숫자가 1번칸의 숫자보다 크면 교환 ... 배열의 n-2번 칸의 숫자가 n-1번 칸의 숫자보다 크면 교환
        // j의 최대는 n-2가 되어야 하므로, 구간 설정에 유의한다.
        // 큰 인덱스부터 차곡차곡 쌓아 올린다.
        for (int j = 0; j < n - 1 - i; j++)
        {
            // 문제의 조건에 따라 교환
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0) //교환이 일어나지 않는다면, 정렬이 되었다는 뜻으로 해석할 수 있다.
            break;
    }

    // 결과 출력
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}