#include <iostream>
// raster scan
using namespace std;

// 각 행의 인덱스를 얻는다. 이 때 인덱스는 1부터 시작하는 인덱스이다.
int getRowByIndex(int index)
{
    /*
        각 행마다 속해있는 번호의 규칙을 찾아보자.
        1행 : 1~9
        2행 : 10~18
        ...
        각 행을 9로 나누어 주면
        1행 : 0 0 0 0 0 ... 1
        2행 : 1 1 1 1 1 ... 2
        각 열에 1을 빼주고 9로 나누어준 몫을 구하면...
        1행 : 0 0 0 0 0 ... 0 (0~8)
        2행 : 1 1 1 1 1 ... 1 (9~17)
        인덱스는 1부터 시작하므로 1을 더해주면 아래의 수식을 리턴하면 된다.
    */
    return (index - 1) / 9 + 1;
}

// 각 열의 인덱스를 얻는다. 이 때 인덱스는 1부터 시작한다.
int getColByIndex(int index)
{
    /*
    각 열마다 속해있는 번호의 규칙을 찾아보자.
    1열 : 1, 10 , 19 ...
    2열 : 2, 11, 20 ...
    1열에 1을 빼주면... 9로 나누어준 나머지가 0임을 알수 있다. (0, 9, 18)
    나머지 열부터는 1씩 더해지는 구조 이므로 2열은 1, 3열은 2... 가된다.
    마찬가지로 인덱스는 1부터 시작하므로 1을 더해주면,
    아래 식을 도출해낼 수 있다.
*/
    return (index - 1) % 9 + 1;
}

// 그룹을 찾는 함수
int getGroupByIndex(int index)
{
    // 나는 그룹테이블을 만들어 주었다. 문제의 그림처럼 그룹을 하나의 2차원 배열로 추상화.
    int groupTable[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    /*
        행과 열을 찾아, 규칙을 찾을 수 있었다. 그룹을 2차원 배열로 추상화하면, 9가지의 행과 열을 3가지로 묶을 수 있다.
        전체 행은 9행지만, 그룹은 3행이다. 그러면 행을 (1,2,3) (4,5,6) (7,8,9)로 그룹은 3행으로 볼 수 있다.
        그럼 규칙을 찾아보자. 각각 1씩 빼주면, (0,1,2) (3,4,5) (6,7,8) 이 된다.
        이는 3으로 나누어주고 몫을 구하면, (0,0,0) (1,1,1) (2,2,2) 로 그룹테이블의 행의 인덱스를 구할수 있다.
        배열의 인덱스는 0부터 시작하므로, 추가적인 처리는 필요없다.
        열도 똑같이 구해주면 된다.
    */
    int row = getRowByIndex(index);
    int col = getColByIndex(index);
    int rowIdx = (row - 1) / 3;
    int colIdx = (col - 1) / 3;

    // 위 방식으로 구한 그룹 번호를 리턴한다.
    return groupTable[rowIdx][colIdx];
}
int main()
{
    // TestCase 입력받기
    int testCase;
    cin >> testCase;

    // 문제에서 요구한 답 출력 과정
    for (int caseIndex = 1; caseIndex <= testCase; caseIndex++)
    {
        // 스도쿠 판의 번호 입력받기
        int indexNumber;
        cin >> indexNumber;
        // 답 출력
        printf("Case #%d:\n", caseIndex);
        printf("%d %d %d\n", getRowByIndex(indexNumber), getColByIndex(indexNumber), getGroupByIndex(indexNumber));
    }
    return 0;
}