#include <iostream>
#include <vector>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000; // 시리얼 넘버 최댓값

int main()
{

    int n; //데이터의 수
    cin >> n;

    vector<int> data; // 데이터

    // 시리얼 입력받기
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        data.push_back(temp);
    }

    vector<int> answer;                          // 중복을 제거한 배열 (응모 대상 시리얼)
    int *table = new int[MAX_SERIAL_NUMBER + 1]; // 시리얼이 얼마나 나왔는지 빈도를 체크하는 배열

    // table 빈도 체크
    for (int i = 0; i < n; i++)
    {
        table[data[i]]++;
    }
    // 응모 가능성 체크
    for (int i = 0; i <= MAX_SERIAL_NUMBER; i++)
    {
        // 단 하나의 시리얼 넘버만 응모대상에 넣는다.
        if (table[i] == 1)
        {
            answer.push_back(i); // 답을 출력할 배열에 넣는다.
        }
    }
    int answerLen = answer.size(); // size함수를 반복문 안에 넣으면, 반복문 조건체크마다 함수가 호출되므로 미리 변수로 빼둔다.

    // 형식에 맞게 답 출력.
    for (int i = 0; i < answerLen; i++)
    {
        // 0이 아닐 때는 공백을 넣어주어 구분해준다.
        if (i > 0)
        {
            cout << ' ';
        }
        cout << answer[i];
    }

    delete[] table; // 동적 배열 해제.
    return 0;
}