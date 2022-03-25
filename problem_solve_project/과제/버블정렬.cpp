#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        int count = 0; // 가지치기. 스왑이 일어나지 않는다면, 정렬이 되었다는 뜻이다. 
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }
        if (count == 0)
            break;
        }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }

    delete[] arr;
    return 0;
}