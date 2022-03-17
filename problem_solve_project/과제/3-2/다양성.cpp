#include <iostream>

using namespace std;

int main()
{
    int n;       // 화보의 수
    int current; // 최근 화보의 고유넘버
    int count = 0;
    cin >> n;
    int *arr = new int[n]; // 화보를 받아올 배열 생성

    // 화보 고유번호 입력 받아오기
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        // 화보의 갯수가 1개가 보장되므로, i 가 0일때는 일단 세어준다.
        if (i == 0)
        {
            count++;
            current = arr[i];
        }
        // 화보가 오름차순으로 정렬되어있으므로. 현재의 값과 다르면 다른 화보이므로 카운트한다.
        if (current != arr[i])
        {
            count++;
            current = arr[i];
        }
    }

    cout << count; // 답 출력
    delete[] arr;
    return 0;
}