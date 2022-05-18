#include <stdio.h>
#include <iostream>

using namespace std;

void solve(int students[], int p, int q, int n)
{
    int passCount = 0; // 몸무게를 통과한 회원들의 수
    int weightSum = 0; // 몸무게 합산 결과

    for (int i = 0; i < n; i++) // 전체 동아리원을 검사
    {
        if (students[i] <= p) // 만약 몸무게가 p를 넘지 않는다면,
        {
            passCount++;              //체중 제한 인원수 증가
            weightSum += students[i]; // 몸무게 합산하기
        }
    }
    printf("%d %d\n", passCount, weightSum); // 답 출력 : 체중 제한 걸리지 않는 회원 수, 그들의 총 몸무게 합
    if (weightSum > q)                       // 합산 몸무게가 Q보다 클 때
    {
        printf("NO\n");
    }
    else // 아닐 때
    {
        printf("YES\n");
    }

    return; // void
}

int main()
{
    int n, p, q; // 각 변수는 문제에서 정의한 의미를 가진다.

    scanf("%d %d %d", &n, &p, &q); // n,p,q 입력 받아오기

    int *studentsWeightArray = new int[n]; // 아주대 동아리 회원들의 몸무게를 배열로 저장

    for (int i = 0; i < n; i++) // 아주대 동아리 회원들의 몸무게 입력 받아오기
    {
        scanf("%d", &studentsWeightArray[i]);
    }

    solve(studentsWeightArray, p, q, n); // 문제 해결을 위한 메서드 호출
    delete[] studentsWeightArray;        // 동적 할당한 배열 제거
    return 0;                            // 정상 종료를 나타내는 리턴 문
}