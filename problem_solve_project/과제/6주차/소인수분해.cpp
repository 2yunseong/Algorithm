#include <iostream>
#include <vector>

using namespace std;
// ppt의 소인수분헤 알고리즘 사용.
int main()
{
    // testcase 입력
    int testCase;
    cin >> testCase;
    for (int i = 1; i <= testCase; i++)
    {
        // 소인수분해할 숫자 입력 받기
        int num;
        cin >> num;
        // 나누어질 숫자를 사용하기 위해 따로 변수로 분리.
        int useNum = num;

        vector<int> L; // 소인수들을 저장할 리스트를 추가한다.

        // 2부터 ~ n까지 반복(시간복잡도가 N이긴함.)
        for (int m = 2; m <= num; m++)
        {
            // m이 약수이면
            while (useNum % m == 0)
            {
                // 소인수 리스트에 추가한다.
                L.push_back(m);
                // 다음 소인수분해를 위해 나누어준다.
                useNum /= m;
            }
        }
        // 다 마치고도 숫자가 남아 있으면 약수일 수 밖에없다.
        if (useNum > 1)
        {
            L.push_back(useNum);
        }

        // 답 출력하기
        printf("#%d:\n", i);
        for (int i = 0; i < L.size(); i++)
        {
            cout << L[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}