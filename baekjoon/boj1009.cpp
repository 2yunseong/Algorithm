#include <iostream>
using namespace std;

int main () 
{
    int Testcase;
    int count = 0;


    cin >> Testcase;

    int* answer = new int[Testcase];    // ���� �̰��� ����

    while (count < Testcase)   // ���� [0,testcase)
    {
        int a, b;

        cin >> a >> b;

        int* lotnum = new int[b+1]; //������ [0,1000000]

        lotnum[0] = 1; //���� �ʿ���� ��

        for (int j = 1; j <= b; j++) //���� [2,b]
        {
            lotnum[j] = lotnum[j-1]*a; //���� 1���ڸ��� a�� ���ϰ�..
            lotnum[j] %= 10; //1�� �ڸ��� ���ܼ�..�����Ѵ�.
        }

        answer[count] = lotnum[b]; //a^b �� 1���ڸ�
        count++;

        delete[] lotnum;
    }

    /* ���� ��� */

    for (int i = 0; i < Testcase; i++) //���� [0,Testcase)
    {
        if (answer[i] == 0)
            cout << 10 << endl;
        else {
            cout << answer[i] << endl;
        }
    }

    delete[] answer;
    return 0;
}
