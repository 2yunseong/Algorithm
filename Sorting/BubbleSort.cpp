#include <iostream>
#define SIZE 10
using namespace std;

int main()
{
    int array[SIZE] = {8, 4, 1, 3, 5, 6, 9, 7, 2, 10};

    for (int i = 0; i < SIZE; i++)
    {
        int count = 0;
        for (int j = SIZE - 1; j > i; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                count++;
            }
        }
        if (count == 0)
            break;
    }

    for (int i = 0; i < SIZE; i++)
        cout << array[i] << ' ';

    return 0;
}