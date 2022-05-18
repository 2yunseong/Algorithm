#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void solve(string schools[], int n)
{
    int firstIdx = -1; // 첫번째 아주가 나온 인덱스 표시
    int lastIdx = -1;  // 마지막으로 아주가 나온 인덱스 표시
    // 선형 탐색
    for (int i = 0; i < n; i++)
    {
        if (schools[i] == "AJOU") // 일치한다면
        {
            if (firstIdx == -1) // 처음 출현하는 거라면
            {
                firstIdx = i + 1; // 처음 인덱스 변경
            }
            lastIdx = i + 1; // 마지막 인덱스 최신화 시키기
        }
    }

    printf("%d %d", firstIdx, lastIdx); // 정답 출력
}
int main()
{

    int n;
    char buff[11]; // 입력 받을 때 임시로 저장할 변수로 사용함.
    string *schools;

    scanf("%d", &n);
    schools = new string[n];

    for (int i = 0; i < n; i++) // 각 학교 이름 입력 받아오기
    {
        scanf("%s", buff);
        schools[i] = buff;
    }

    solve(schools, n);
    delete[] schools; // 동적 할당 메모리 해제
    return 0;
}