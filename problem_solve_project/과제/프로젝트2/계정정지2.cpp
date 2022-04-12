#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;

int main()
{
    int n; // 회원 목록
    int m; // 제제 대상자 수
    cin >> n;
    string userID[n];
    bool isBans[n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        userID[i] = temp;
    }
    cin >> m;
    string filterID[m];
    // ban ID 입력받기
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        filterID[i] = temp;
    }

    // 로직
    clock_t start = clock();

    for (int i = 0; i < m; i++)
    {
        // 각 UserID에 대해 filterID를 비교
        for (int j = 0; j < n; j++)
        {
            bool isSame = true; // 밴 리스트에 등재 가능한지 판단하는 변수
            // string 사이즈가 같을 때만 평가
            if (userID[j].size() == filterID[i].size())
            {
                int strSize = userID[j].size();
                // 각 문자열의 요소가 서로 같은지 비교하는 연산
                for (int k = 0; k < strSize; k++)
                {
                    // 와일드카드 문자는 존재한다면, 모든 문자와 같으므로 skip한다. 이 때, 서로 사이즈가 같으므로 다른 고려사항은 없다.
                    if (filterID[i][k] == '*')
                        continue;

                    // 다르다면, IsSame 을 False 로 한다.
                    if (filterID[i][k] != userID[j][k])
                    {
                        isSame = false;
                        break;
                    }
                }
            }
            else
                isSame = false;

            // 만약 밴 유저라고 판단된다면, isBans의 값을 바꾸어준다.
            if (isSame)
            {
                isBans[j] = true;
            } else {
                isBans[j] = false;
            }
        }
    }

    // 조합의 경우를 따지기 위해 인덱스를 가져온다.
    vector<int> banIdxs; // 밴 유저인 userID 배열의 index를 저장하는 배열
    for(int i=0; i<n; i++){
        if(isBans) banIdxs.push_back(i);
    }

    // m에 따른 각 인덱스의 조합을 따른다. 이 때, 식은 mC_banIdxs.size 이고,
    // 나오는 경우는 해당 식에 따른 조합이다.
    // 그 후, 올바른 조합이면 count를 한다.
    int count = 0;
    

    // 답 출력
    clock_t end = clock();

    return 0;
}

void combinationResult(int n, vector<int>&picked, int m){
    if(m == 0){
        // 찾았을 시 들어갈 로직
        return ;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next = smallest; next < n; next++){
        picked.push_back(next);
        combinationResult(n, picked, m - 1);
        picked.pop_back();
    }
}

int getCombinationVector(vector<int>& )