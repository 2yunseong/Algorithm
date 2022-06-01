#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <utility>
#include <ctime>

using namespace std;
typedef pair<string, int> pairStrInt; // bfs 탐색을 위한 pair. string은 바뀐 카드 순서, count는 탐색 깊이를 나타낸다.

int main()
{
    ios::sync_with_stdio(false);   // printf, scanf는 사용하지 않으므로, 동기화를 꺼 불필요한 오버헤드 줄이기.
    int n, k;                      // 카드의 갯수와 뒤집는 개수
    map<string, int> mappingTable; // 1이면 방문, 0이면 방문하지 않음
    cin >> n >> k;
    int iteration = n - k + 1; // 뒤집는 경우의 수
    string input;              // 비교하기 쉽게 카드의 순서를 스트링으로 받아온다.
    int ans = -1;              //답이 될 횟수. 모든 경우가 없다면 -1을 출력한다.
    // 카드 입력 받기
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        input += temp;
    }
    clock_t start = clock();
    string sorted = input;              // 오름차순이 될 값
    sort(sorted.begin(), sorted.end()); // 비교를 위해 카드의 오름차순을 구해놓음

    queue<pairStrInt> q; // bfs 탐색을 위한 큐
    pairStrInt p1 = make_pair(input, 0);

    q.push(p1); // 시작 노드를 넣는다.

    while (!q.empty())
    {
        pairStrInt cur = q.front(); // 탐색을 시작한다.
        q.pop();                    // 탐색을 시작하고 꺼낸다.
        // 탐색해서 오름차순이면, 종료
        if (sorted == cur.first)
        {
            ans = cur.second; // ans 최신화
            break;
        }
        // 아니면, 다음 큐로 탐색을 시작한다.
        for (int i = 0; i < iteration; i++) // i 가 iteration을 초과하면 카드를 뒤집을 수 없다.
        {
            string reverseCard = cur.first.substr(i, k);     // 뒤집을 카드 문자열
            reverse(reverseCard.begin(), reverseCard.end()); // 카드를 뒤집고..
            // 뒤집은 카드를 다시 붙여 준다. [0, i) + [i, i + k) + [i + k, 사이즈) = [0, 사이즈)
            string searchNext = cur.first.substr(0, i) + reverseCard + cur.first.substr(i + k, cur.first.size());

            // 탐색하지 않은 카드 수열이라면 (이미 탐색을 한 카드 순서는 방문할 필요가 없다.)
            if (mappingTable.count(searchNext) == 0)
            {
                mappingTable[searchNext] = 1;                         // 방문했다는 표시를 남기고
                pairStrInt p = make_pair(searchNext, cur.second + 1); // count를 증가시키는 이유는 다음 깊이 이기 때문에
                q.push(p);                                            //큐에 넣는다.
            }
        }
    }
    clock_t end = clock();
    cout << ans << '\n'; // 답 출력.
    cout << "실행시간: " << double((end - start) / CLOCKS_PER_SEC) << "초" << '\n';
    return 0;
}
