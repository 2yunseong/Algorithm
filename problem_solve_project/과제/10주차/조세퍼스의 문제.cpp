#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Player {
    public:
        int index;
    
    Player(int index = 0){
        this->index = index;
    }
};

    vector<Player> getOutPlayersList(int n, int m, const vector<Player> &players){
        vector<Player> outPlayers ; // out 된 player list

        queue<Player> que; // 아직 게임에서 제외되지 않은 플레이어들의 리스트

        // 초기 사람들을 담은 큐를 저장한다. 
        for(int i=0; i<n; i++){
            que.push(players[i]);
        }
        for(int i = 0; i< n; i++){
            int jump = 1 + (m - 1) % que.size(); // 점프 인터벌을 구한다. 이 때, n 보다 클 경우가 있으므로 나머지 연산으로 설정
            // 점프 수 만큼 사이클을 돌리는 로직
            for(int j = 0; j < jump - 1; j++){
                Player p = que.front(); // 앞 값을 저장 한뒤 
                que.pop();  // 빼고
                que.push(p); // 맨 뒤로 넣는다.
            }

                    // 점프 수 만큼 사이클을 돌렸다면, 그 사람은 게임에서 제외 시킨다.
            Player outPlayer = que.front();
            que.pop();

            outPlayers.push_back(outPlayer); // 아웃 리스트에 올린다.
        }
        return outPlayers;
    }

void testCase(int caseIndex){
    int n, m;
    cin >> n >> m;

    vector<Player> players; // player를 담을 배열
    // player들을 담는다. 
    for(int i=0; i <n; i++){
        players.push_back(Player(i + 1));
    }

    vector<Player> outPlayers = getOutPlayersList(n, m, players); // 배제될 유저를 담을 리스트

    // 답 출력
    for(int i = 0; i< n; i++){
        cout << outPlayers[i].index << ' ';
    }
    cout << '\n';
}

int main(){
    int t;
    cin >> t;
    // testcase를 받아오는 과정.
    for(int i=0; i<t; i++){
        testCase(i);
    }

    return 0;
}