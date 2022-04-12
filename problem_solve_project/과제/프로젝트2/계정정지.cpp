#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <ctime>

using namespace std;
set<set<string> > answerSet; //답이 되는 경우를 추가할 집합

//  filterID 의 각 요소별 인덱스에서, 제제 사용자 명단으로 가능한 모든 경우의 수를 뽑아낸다.
//  이 때, answerSet이라는 set Container에 저장해, 집합의 중복을 차단한다.
//  banTargetL : banTargetList
//  btlIdx : 완전탐색을 하기위한 index
//  s : 결과를 저장하기 위한 집합.
// 재귀호출을 통한 완전 탐색으로 구현하였다. 트리를 그려 해당 재귀함수를 구현함.
void solve(vector<vector<string> > &banTargetL, int btlIdx, set<string> &s)
{
    // 기저 조건 : 모두 탐색을 마쳤을 때 => index가 0아래이면, 탐색을 마친 것이다.
    if (btlIdx < 0)
    {
        // 중복되는 것들을 추가가 되지 않으므로, 사이즈가 같다면 답을 찾은 것이다.
        if (s.size() == banTargetL.size())
        {
            answerSet.insert(s); // 중복되는 경우에는 추가되지 않음.
        }
        return;
    }
    int banTargetElementSize = banTargetL[btlIdx].size();

    for (int i = 0; i < banTargetElementSize; i++)
    {
        bool insertFlag;                                     // insert가 일어났는지 판단하는 flag
        insertFlag = s.insert(banTargetL[btlIdx][i]).second; // insert는 Pair를 return 하므로 두번째값인 boolean 값으로 insert 여부를 판단.
        solve(banTargetL, btlIdx - 1, s);                    // 재귀호출. 트리의 다음 깊이를 탐색.
        // 중복(insert가 되지 않았을 경우 )이 일어나면, 값을 erase할때 이전 값이 지워지므로 insert가 되었을 때만 집합에서 값을 제한다.
        if (insertFlag)
            s.erase(banTargetL[btlIdx][i]); // 위 재귀함수가 끝나면, 사용했던 값을 지운다.(트리의 위로 올라간다.)
    }
}

/*
    코드가 매우 깨끗하지 않아, 주석을 달아도 이해하기 난잡하므로 좀 정리해서 적어보자면..
    userID : 사용자의 ID 가 담기는 배열이다. (frodo, fradi, crodo, abc123 등)
    filterID : 제제 대상자 아이디가 담기는 배열이다. (*rodo, *rodo ****** 등)
    banTargetList : 제제 대상자 아이디가 담기는 배열의 순서대로, userID에서 제제 대상자가 되는 모든 경우를 담는 2차원 배열이다.
    ex) 위 예시에서 banTargetList[0] 의 요소들은 frodo, crodo 가 담기고, banTargetList[1] 에는 frodo, crodo, banTargetList[2] 는 abc123을 가지는 배열임
*/
int main()
{
    int n; // 이용자 수 n
    cin >> n;

    // user ID 입력 로직
    string userID[n];
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        userID[i] = temp;
    }

    int m; // 제제 대상자 수 m
    cin >> m;
    string filterID[m]; // 제제 정지 대상자 필터링 목록
    // ban ID 입력받기
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        filterID[i] = temp;
    }

    // 로직
    clock_t start = clock();               // 클록 시작
    vector<vector<string> > banTargetList; //각 filterID에 관해, 제제가 될 수 있는 타겟을 설정한다.

    for (int i = 0; i < m; i++)
    {
        vector<string> banTarget; // 각 제제 대상자 아이디에 속할 수 있는 유저가 담긴 배열

        // 각 UserID에 대해 filterID를 비교
        for (int j = 0; j < n; j++)
        {
            bool isSame = true; // 제제 대상자임을 나타내는 변수
            // string 사이즈가 같을 때만 평가. 다르면 제제 대상자가 아니다.
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
            // 문자열 길이가 서로 다르다면 제제 대상자가 아님.
            else
                isSame = false;

            // 만약 밴 유저라고 판단된다면, banTarget에 저장한다.
            if (isSame)
            {
                banTarget.push_back(userID[j]);
            }
        }
        // 만들어진 제제 대상자 ID(filterID) 요소 별 제제 가능한 아이디 목록을 저장.
        banTargetList.push_back(banTarget);
    }

    int btlSize = banTargetList.size();   // banTargetList 를 통해 경우의 수 측정
    set<string> t;                        // 임시로 사용할 set 컨테이너
    solve(banTargetList, btlSize - 1, t); // banTargetList 통해 가능한 경우의 수를 완전 탐색한다.
    // 답 출력
    clock_t end = clock();
    cout << answerSet.size() << '\n';
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC); // 소요 시간 출력
    return 0;
}
