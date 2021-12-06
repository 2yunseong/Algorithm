#include <iostream>
#define SIZE 10
using namespace std;

int main()
{
    int array[SIZE] = {8, 4, 1, 3, 5, 6, 9, 7, 2, 10};
    int m;

    for (int i = 0; i < SIZE - 1; i++)
    {
        m = i;

        for (int j = i + 1; j < SIZE; j++)
        {
            if (array[m] > array[j])
            {
                int temp = array[m];
                array[m] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << ' ';
    }
}