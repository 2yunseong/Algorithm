#include <iostream>
#include <string>
#include <vector>

#define TYPE 4
#define BLOCK_Y 2
#define BLOCK_X 2
using namespace std;

int blockcoverdtype[TYPE][BLOCK_Y][BLOCK_X]=
{
    {{0,0},{1,0},{0,1}},    //type 0
    {{0,0},{0,1},{1,1}},    //type 1
    {{0,0},{1,0},{1,1}},    //type 2
    {{0,0},{1,0},{1,-1}}    //type 3
};

int main()
{
    int testcase;
    cin>>testcase;

    int* answer = new int[testcase];

    for(int t=0; t<testcase; t++)
    {
        //필요한 객체 및 변수 선언부 
        int height;                          //판의 높이(보드의 세로 dy)
        int width;                           //판의 너비 (보드의 가로 dx)
        int basecase_one = 0;                //기저 사례 1 판단.
         cin>>height>>width;
        string* line = new string[height];

        //2차원 벡터의 동적할당
    
        vector<vector<int> > board(height, vector<int>(width,0)) ;
        
        //# : 검은 칸 . : 흰 칸
        //보드 입력 받아오기
        for(int i=0; i<height; i++)
            cin>>line[i];

        //보드 변환 시키기
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(line[i][j]=='#')
                    board[i].push_back(1);
                else if(line[i][j]=='.')
                    board[i].push_back(0);    
            }
        }

        //기저 사례1 : 만약 흰색 칸의 수가 3의 배수가 아니면 
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(board[i][j]==0)
                    basecase_one++;
            }
        }
        
        if(basecase_one%3!=0)
            answer[t]=0;        //이번 케이스의 답은 0이된다.

        else
        {
            

        }
        
        //동적 할당 한 객체 메모리 해제 시키기
        delete[] line;
        for(int i=0; i<height; i++)
            delete[] board[i];
        delete[] board;
    }
    return 0;
}
