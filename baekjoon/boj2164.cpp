#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> cards;
    int N;
    cin >> N;

    //card setting
    for (int i = 1; i < N + 1; i++)
        cards.push(i);

    while (1)
    {
        if (cards.size() == 1)
            break;
        else
        {
            //1.trash first card
            cards.pop();
            if (cards.size() == 1)
                break;
            //2.first cards go last
            int temp = cards.front();
            cards.pop();
            cards.push(temp);
        }
    }
    cout<<cards.front()<<endl;
    return 0;
}

/* 아직 STL 사용이 미숙하다. 좀더 연습해야 겠다. 
 문제 자체는 쉬운편.
 1.맨위 카드를 버린다
 -종료 조건 체크: queue.size == 1
 2.그 다음 카드를 맨 뒤로 보낸다
 -temp 에 queue.front 저장
 -queue.pop();
 -queue.push(temp);
 (혹은 그냥 queue.push(queue.front());)<- 이쪽이 더 간단할 수도 있겠다
 3.종료조건 체크: queue.size == 1
 
 */
