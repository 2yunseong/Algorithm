#include <iostream>

using namespace std;

const int MAX_TABLE_LENGTH = 10000;
int phoneNumArray[10000]; // 전역변수로 선언한 배열은 모두 0으로 초기화 되어 있다.
/*
    메모이제이션을 사용하여 문제를 해결했다.
    1. 전화번호를 받으면, 그 전화번호에 맞는 인덱스에 카운트를 한다.
    2. 가장 많은 카운트의 숫자를 출력한다.

*/
int main()
{
    int n;
    cin >> n; // 전화번호 갯수 입력빧기

    for (int i = 0; i < n; i++)
    {
        int temp; // 숫자는 0002 이런식으로 들어와도 2로 인식한다.
        cin >> temp;
        phoneNumArray[temp]++; // 횟수를 받자마자 바로 카운트함.
    }

    int maxCount = -1; // 카운트 최댓값 저장하기
    int maxIdx = 0;    // 최대 카운트를 가지는 index 를 저장. 이때, 초기값은 0이어야 한다.(0일때 사전순으로 가장 빠른 숫자를 출력해야되기 때문)

    // 가장 많이 사용되는 번호를 찾는 로직
    for (int i = 0; i < MAX_TABLE_LENGTH; i++)
    {
        // 최대 카운트를 가지는 번호를 찾았다면, maxCount, maxIdx 값 최신화
        if (maxCount < phoneNumArray[i])
        {
            maxCount = phoneNumArray[i];
            maxIdx = i;
        }
    }

    printf("%04d", maxIdx); // 전화번호 형식에 맞게 출력.

    return 0;
}