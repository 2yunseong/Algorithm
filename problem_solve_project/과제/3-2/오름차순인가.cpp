#include <iostream>

using namespace std;

int main()
{
    bool isUp = true; // 오름차순인지 아닌지 결과를 나타내는 변수
    int n;            // 학생의 수
    cin >> n;         // 학생의 수 입력
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // [1, n) 까지 탐색
    for (int i = 1; i < n; i++)
    {
        // 앞에 있는 원소가 뒤에 있는 원소보다 크면,
        if (arr[i - 1] > arr[i])
        {
            isUp = false;
            break;
        }
    }

    // 오름차순인지 아닌지에 따라, 정답을 출력하는 로직
    if (isUp)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    delete[] arr;
    return 0;
}