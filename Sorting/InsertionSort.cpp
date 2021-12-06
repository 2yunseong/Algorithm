#include <iostream>
#define SIZE 10
using namespace std;

int main()
{
    int array[SIZE] = {8, 4, 1, 3, 5, 6, 9, 7, 2, 10};
    int m;

    for (int i = 1; i < SIZE; i++)
    {
        int j;
        m = array[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] < m)
                break;
            else
                array[j + 1] = array[j];
        }
        array[j + 1] = m;
    }
    for (int i = 0; i < SIZE; i++)
        cout << array[i] << ' ';

    return 0;
}