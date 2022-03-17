#include <iostream>

using namespace std;

int main()
{
    int n;       // 화보의 수
    int current; // 최근 화보의 고유넘버
    int count = 0;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            count++;
            current = arr[i];
        }
        if (current != arr[i])
        {
            count++;
            current = arr[i];
        }
    }

    cout << count;
    delete[] arr;
    return 0;
}