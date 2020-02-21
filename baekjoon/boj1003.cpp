#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int testcase;   //testcase
    int count = 0;  //n�� �Է¹��� ī��Ʈ

    cin >> testcase;

    int *fibo_zero = new int[41];   
    int *fibo_one = new int[41];
    int *test_array = new int[testcase]; //�Է¹��� ��. n �� ����.

    for (int i = 0; i <= 40; i++)
    {
        if (i == 0)
        {
            fibo_zero[i] = 1;
            fibo_one[i] = 0;
        }
        else if (i == 1)
            {
                fibo_zero[i] = 0;
                fibo_one[i] = 1;
            }
        else
        {
            fibo_zero[i]=fibo_zero[i-2]+fibo_zero[i-1];
            fibo_one[i]=fibo_one[i-2]+fibo_one[i-1];
        }
    }

    while (count != testcase) //input 
    {
        scanf("%d", &test_array[count++]);     //������ ��Ҵ� n�� ��.
    }

    for(int i=0; i<testcase; i++)  //output
    {
        cout<<fibo_zero[test_array[i]]<<' '<<fibo_one[test_array[i]]<<endl;
    }

    delete[] fibo_one;
    delete[] fibo_zero;
    delete[] test_array;

    return 0;
}
