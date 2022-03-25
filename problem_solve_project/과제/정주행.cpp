#include <iostream>
#include <climits>

using namespace std;

/*
    식 : max - min = n - 1
    이는 귀납적으로 증명이 가능하다. 문제에 연속적인 수열의 정의에 따라 배열을 만들어보자.
    먼저 문제에서 연속적인 수열의 정의는, 항상 i번째 숫자가 (i+1)번째 숫자보다 1만큼만 작다 이다.
    다음 정의로 배열을 만들면, 다음과 같다.
    [i , (i+1), (i+2), ... ,(i+n)]
    배열은 총 n+1개임을 알 수 있다. 그리고, 최대, 최소의 차는 (i+n) - i = n 이므로
    배열의 갯수 -1 로 표현할수 있다.
    따라서 위 식은 성립한다.
*/
int main()
{
    int n;
    cin >> n; // 에피소드의 갯수 입력 받아 오기
    int *arr = new int[n];
    int min_value = INT_MAX; // 최소값
    int max_value = INT_MIN; // 최댓값

    // 입력받기
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    // 최대 최소 찾기 : 배열의 요소가 최대/최소 값보다 크면/작으면 값을 갱신한다.
    for (int i = 0; i < n; i++)
    {
        // 최댓값 설정
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
        // 최솟값 설정
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    // 위 주석에있는 식에 따라, 연속적인 수열인지 판단
    if ((max_value - min_value) == (n - 1))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    delete[] arr;
    return 0;
}