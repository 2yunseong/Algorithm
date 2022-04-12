#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main()
{

    int n;                       // 발열체크를 기다리는 사람
    int m;                       // 발열 측정기의 숫자
    unsigned long long time = 0; // 모두 측정하는데 걸리는 시간
    int count = 0;               // 측정 완료자를 세는 변수
    vector<int> checkTimes;      // 각 측정기마다 걸리는 시간을 저장한 배열
    int vecSize;                 // checkTimes의 size를 저장할 변수

    // 입력 조건에 따라 입력 받기
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        checkTimes.push_back(temp); // 위 checkTimes 배열에 넣어준다.
    }

    // 로직
    clock_t start = clock();     // 시간 측정 시작
    vecSize = checkTimes.size(); // 각 측정기의 갯수. for문에서 size()를 돌리면 그만큼 오버헤드가 생김.
    // 측정이 완료될 때까지 반복문을 돌린다.
    while (count < n)
    {
        time++; // 시간을 증가한 후,
        // 각 측정기마다, 시간을 처리할 수 있는지 본다. 이 때, 나머지 연산을 사용해 구한다.
        for (int i = 0; i < vecSize; i++)
        {
            /*
                시간을 측정기가 걸리는 시간으로 나눈 나머지가 0이 아니라면, 해당 측정기로는 그 시간에
                종료하지 못한다는 소리이다. 따라서, 추가적인 시간이 발생한다.
                따라서, 나머지가 0이 아닐 때는 측정기는 진행중 or Idle 상태이다.
            */
            if (time % checkTimes[i] == 0)
            {
                count++; // 0일 때는, 그 시간에 한 명을 측정으로 처리했다고 볼 수 있다. 따라서, count 변수의 값을 1 늘려준다.
            }
            // 만약 카운트가 n이 되면, 측정이 모두 끝났다고 볼 수 있다. 따라서 반복문을 종료한다.
            if (count == n)
                break;
        }
    }
    clock_t end = clock();                                               // 시간 측정 종료
    cout << time << '\n';                                                // 정답 출력
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC); // 소요 시간 출력
    return 0;
}
