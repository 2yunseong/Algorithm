#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;                   // 사용할 카드의 수
    int m;                   // 당첨번호의 숫자
    vector<int> nCard;       // n개의 카드
    vector<int> drawNumbers; // 당첨번호
    vector<int> answers;     // 3개의 카드로 당첨번호를 만들수 있을 때 당첨번호를 저장하는 배열
    // 입력 받아오기
    cin >> n;
    cin >> m;
    // 카드 입력
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nCard.push_back(temp);
    }

    // 당첨번호 입력
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        drawNumbers.push_back(temp);
    }

    // 입력이 순서없이 들어올 수도 있으니 정렬해준다.
    sort(nCard.begin(), nCard.end());
    sort(drawNumbers.begin(), drawNumbers.end());

    for (int i = 0; i < m; i++)
    {
        int k = drawNumbers[i];  // 비교할 당첨번호
        bool isPossible = false; // 3개의 카드로 만들 수 있는지 확인하는 변수
        /*
            k = x + y + z 가 되는 세 카드가 있는지 확인해야된다.
            이 때, k 를 알고 있으므로 x,y 의 조합을 구하고, z = k - (x + y) 를 통해
            z가 nCard 에 존재하는지 여부로 판단하면 된다.
            이 때, x,y 는 같은 배열에서 뽑아오므로, 각각의 인덱스가 (0,1) 이나 (1,0) 이나 같다.
            따라서 중복을 제거해 주기 위해 다음과 같이 반복문을 적었다.
        */
        for (int j = 0; j < n; j++)
        {
            int x = nCard[j]; // x 선택
            for (int l = 0; l <= j; l++)
            {
                int y = nCard[l];    // y 선택
                int z = k - (x + y); // z 구하기
                // n은 정렬되어 있으므로, z가 존재하는지 이진탐색으로 찾는다.
                if (binary_search(nCard.begin(), nCard.end(), z) == true)
                {
                    // 찾았다면,
                    isPossible = true; // k가 당첨번호로 가능한 값이다.
                    break;
                }
            }
            // 이미 존재한다면, 해당 k 에 대해서는 더이상 탐색할 필요가 없다. 따라서 반복문을 종료한다.
            if (isPossible)
                break;
        }

        // 존재한다면, k를 답을 저장하는 배열에 넣어준다.
        if (isPossible)
        {
            answers.push_back(k);
        }
    }

    sort(answers.begin(), answers.end()); // 오름차순으로 정렬해야되므로 답 배열을 정렬.
    int answerSize = answers.size();      // 반복문에서 불필요한 size() 호출을 막기 위함.
    // 답 출력
    for (int i = 0; i < answerSize; i++)
    {
        cout << answers[i] << ' ';
    }

    return 0;
}