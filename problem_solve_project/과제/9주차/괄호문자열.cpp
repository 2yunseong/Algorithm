#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int testcase;    // testcase
    cin >> testcase; // testcase 입력
    while (testcase)
    {
        stack<int> stk;    // 괄호문자열인지 판단하는 스택. 그냥 임의의 자료형을 가지는 스택이다.
        bool check = true; //체크 하는 문자열
        string temp;       // 테스트 케이스 별 체크할 문자열
        cin >> temp;

        int ps_size = (int)temp.size(); // 문자열의 사이즈

        // 문자열을 전체 순회하면서, 괄호문자열인지 판단한다.
        // #1. ( 모양은 push, )는 pop을 한다. 이 때, 마지막 문자까지 탐색을 마치면 스택은 비어있어야한다.
        // #2. 비어있지 않다면, 괄호문자열이 아님. 왜냐하면 괄호의 수가 맞지 않기 때문이다.
        // #3. 하지만 수가 똑같다고 괄호 문자열은 아니다. )( 와 같은 케이스가 있기 때문이다.
        // #4. 따라서, 비어있는 스택에 pop을 시도한다면 false를 리턴한다.
        for (int i = 0; i < ps_size; i++)
        {
            // )면 pop 시도.
            if (temp[i] == ')')
            {
                // 스택이 비어있을 때 )가오면 괄호문자열이 아님 (#3, #4 참고)
                if (stk.empty())
                {
                    // false 체크
                    check = false;
                    break;
                }
                // 스택이 비어있지 않다면 pop
                else
                    stk.pop();
            }
            // ( 면 push 를 한다.
            else if (temp[i] == '(')
                stk.push(1); // int 형을 담을 수 있으므로 임의의 숫자를 담는다. 어떤 수를 담든 상관없다. 여기서는 임의로 1로 잡음
        }
        // 다 마친 이후, 스택이 비어있지 않는다면 괄호문자열이 아니다.
        if (!stk.empty())
            check = false;

        // 결과에 따라 출력
        if (check)
            cout << "YES\n";
        else
            cout << "NO\n";
        testcase--;
    }
    return 0;
}