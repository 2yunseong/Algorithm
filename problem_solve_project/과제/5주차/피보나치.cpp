#include <iostream>
#include <vector>

using namespace std;

vector<int> makeFibonacciTable(int n)
{
    const int Mod = 100000000; // 8자리 출력을 위해 사용하는 modular
    vector<int> ret(n + 1);    // 0은 사용하지 않음.
    ret[1] = 0;                // 1번째 수는 0
    ret[2] = 1;                // 2번째 수는 1

    for (int i = 3; i <= n; i++)
    {
        ret[i] = ret[i - 1] + ret[i - 2]; // 피보나치 수 구하기
        ret[i] %= Mod;                    // Mod 만큼 나누어준다.
    }

    return ret;
}
int main()
{
    int testCase;       // testCase 변수
    cin >> testCase;    // testCase 입력
    vector<int> nArray; // testCase 당 n을 담을 배열

    // 입력
    for (int i = 0; i < testCase; i++)
    {
        int n;
        cin >> n;
        nArray.push_back(n); // n을 담을 배열
    }

    int testCaseSize = nArray.size(); // n 의 갯수만큼 출력하기 위한 반복문의 조건을 변수로 설정
    // 출력(한꺼번에 진행)
    for (int i = 0; i < testCaseSize; i++)
    {

        vector<int> answer = makeFibonacciTable(nArray[i]); // 피보나치 수 구하기
        cout << answer[nArray[i]] << '\n';                  // 답 출력
    }

    return 0;
}
