#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2;
    bool isFindAnswer = false; // 사전 순을 찾았을 경우, true가 된다.
    cin >> s1 >> s2;           // 추출 연산자를 이용해 입력 받음.

    int minStrLength = min(s1.length(), s2.length()); // 두 문자열 중 더 짧은 길이의 문자열을 기준으로 비교함.

    // a-z는 아스키코드 상 a가 가장 작은 수고, z가 가장 큰수다.
    // 따라서, 각 자리를 비교하면 된다.
    for (int i = 0; i < minStrLength; i++)
    {
        // 앞의 문자가 더 앞설 때
        if (s1[i] < s2[i])
        {
            cout << -1;          // 답 출력
            isFindAnswer = true; // answer를 찾았으므로 true로 변경
            break;               // 반복문 종료
        }
        // 뒤에 문자가 더 앞설 때
        else if (s1[i] > s2[i])
        {
            cout << 1;           // 답 출력
            isFindAnswer = true; // answer를 찾았으므로 true로 변경
            break;               // 반복문 종료
        }
    }
    // for문을 거처도 결과가 나오지 않았으면, 두 가지 경우를 가진다.
    // 1. 동치 일 때 (hello, hello)
    // 2. 한 단어가 한 단어에 속할 때 (algo, algorithm)
    if (!isFindAnswer)
    {
        // 1. 동치 일 때 -> 값이 같으므로, 0 출력
        if (s1.length() == s2.length())
        {
            cout << 0;
        }
        // 2. 한 단어가 한 단어에 속할 때
        else
        {
            // 글자 수가 더 작은 문자열이 사전 순으로 앞 선다.
            if (minStrLength == s1.length())
            {
                cout << -1;
            }
            else if (minStrLength == s2.length())
            {
                cout << 1;
            }
        }
    }

    return 0;
}