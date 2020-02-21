#include <iostream>
using namespace std;

int main () 
{
    int Testcase;
    int count = 0;


    cin >> Testcase;

    int* answer = new int[Testcase];    // 답을 이곳에 저장

    while (count < Testcase)   // 구간 [0,testcase)
    {
        int a, b;

        cin >> a >> b;

        int* lotnum = new int[b+1]; //구간은 [0,1000000]

        lotnum[0] = 1; //딱히 필요없는 것

        for (int j = 1; j <= b; j++) //구간 [2,b]
        {
            lotnum[j] = lotnum[j-1]*a; //남은 1의자리에 a를 곱하고..
            lotnum[j] %= 10; //1의 자리만 남겨서..저장한다.
        }

        answer[count] = lotnum[b]; //a^b 의 1의자리
        count++;

        delete[] lotnum;
    }

    /* 답의 출력 */

    for (int i = 0; i < Testcase; i++) //구간 [0,Testcase)
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
