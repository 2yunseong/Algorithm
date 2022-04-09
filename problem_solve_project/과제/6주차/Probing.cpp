#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; // 준비된 행운권의 수
    int m; // 입장할 회원의 수

    cin >> n >> m;
    vector<int> ticket(n); // 0으로 초기화 된 티켓. 0 지급가능, 1 지급됨.

    for (int i = 0; i < m; i++)
    {
        int userId; // 회원번호
        cin >> userId;
        int ticketIndex = userId % n; // 일단 행운권 번호를 구한다.

        while (1)
        {
            ticketIndex = (ticketIndex % n); // index가 더해지는 과정에서 n-1보다 over될수 있으므로 작성
            // 지급가능한 티켓이면
            if (ticket[ticketIndex] == 0)
            {
                // 지급하고 출력
                ticket[ticketIndex] = 1;
                cout << ticketIndex << '\n';
                break; // 종료
            }
            else
            {
                // 1을 더한다. 인덱스 처리는 반복문 첫번째에서 해주므로 필요가 없다.
                ticketIndex++;
            }
        }
    }
    return 0;
}