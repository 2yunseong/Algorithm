#include <iostream>
#include <vector>

using namespace std;
// 각 인덱스는 숫자를 의미하므로 백만까지의 숫자가 소수인지 아닌지 표현하기 위해 100만 + 1을 MAx값으로 사용한다.
const int MAX_VALUE = 1000001;

int main()
{
    // 테스트케이스 입력받기
    int testCase;
    cin >> testCase;
    // 데이터 전처리
    vector<bool> isPrimes(MAX_VALUE, true); // 일단 전부 소수라고 생각한다.
    isPrimes[0] = isPrimes[1] = false;      // 0과 1은 소수가 아니다.

    // 2부터 ~ 백만까지 모두 소수를 구한다.
    for (int num = 2; num <= MAX_VALUE; num++)
    {
        // 소수가 아니면 건너 뛴다.
        if (isPrimes[num] == false)
        {
            continue;
        }

        // M^2 부터 ~ N까지(100만) M의 배수는 모두 소수가 아니다.
        for (long long mul = (long long)num * num; mul <= MAX_VALUE; mul += num)
        {
            int index = (int)mul;
            isPrimes[index] = false;
        }
    }

    // testcase 시행
    for (int i = 1; i <= testCase; i++)
    {
        int L, R;      // 구간
        int count = 0; // 소수 갯수 카운트
        cin >> L >> R; // 구간 입력

        // 구간의 소수 갯수 카운트
        for (int i = L; i <= R; i++)
        {
            if (isPrimes[i])
                count++;
        }
        // 출력
        printf("Case #%d:\n", i);
        cout << count << '\n';
    }
    return 0;
}