#include <iostream>

using namespace std;

// 시간복잡도가 O(n^1/2) 인 로직
bool isPrime(int n)
{
    if (n == 1) // 1이면, 소수가 아님
        return false;
    for (int i = 2; i * i <= n; i++) // 강의에서 설명한대로, sqrt(n)까지만 검사하면 된다.
        if (n % i == 0)              // 하나라도 나누어지면 자기 자신을 제외한 약수가 있다는 뜻이므로, 소수가 아님
            return false;
    return true;
}
/*
12 = a x b 로 나타낼 수 있다. (a,b 는 약수, a>=b)
이 때, a는 sprt(12) 보다 클 수 없다.
띠라서, 2 ~ sprt(n) 까지만 조사하면 된다.
*/
int main()
{
    int testCase; // 테스트 케이스 수
    cin >> testCase;

    // 반복문으로 각 테스트 케이스 실행
    for (int i = 0; i < testCase; i++)
    {
        int temp; // 개별 테스트 케이스의 판별할 수
        cin >> temp;
        cout << "Case #" << i + 1 << '\n'; // 케이스를 나타내는 문장.
        if (isPrime(temp))                 // 만약 소수면,
        {
            cout << "YES\n";
        }
        else // 소수가 아니면
        {
            cout << "NO\n";
        }
    }

    return 0;
}