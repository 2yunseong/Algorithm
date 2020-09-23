#include <iostream>
#include <vector>
#define CLOCK_N 16
#define BUTTON_N 10

using namespace std;

//x:연결된 시계 .:연결되지 않은 시계
const char button[BUTTON_N][CLOCK_N+1] ={
   //0123456789012345
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

//스위치를 누르는 함수
//sw_num : 스위치의 번호
void push_switch(vector<int>& clocks, int sw_num)
{
    for(int i=0; i<CLOCK_N; i++)
    {
        if(button[sw_num][i]=='x')
        {
            clocks[i]+=3;
            if(clocks[i]>=15)
                clocks[i]=3;
        }
    }
}

//시계가 정렬이 되어 있는지 확인하는 함수
bool isright(const vector<int>& clocks)
{
    bool ret = true;
    for(int i=0; i<CLOCK_N; i++)
    {
        if(clocks[i]!=12)
        {
            ret = false;
            break;
        }
    }
    return ret;
}

//문제를 풀기 위한 함수
//반환 값: 스위치를 얼만큼 눌러야 하는지
//swit_num: 재귀 호출의 깊이
int solved(vector<int>& clocks, int swit_num)
{

}
int main()
{
    int testcase;
    cin>>testcase;
    int* answer = new int[testcase];

    while(testcase!=0)
    {
        vector<int> clocks(16,0);
        //시계 입력 받아오기
        for(int i=0; i<CLOCK_N; i++)
        {
            int temp;
            cin>>temp;
            clocks.push_back(temp);
        }


        // 반복문 실행
        testcase--;
    }

}