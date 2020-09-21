#include <iostream>
#include <string>
#define TYPE 4
#define BLOCK_Y 2
#define BLOCK_X 2
using namespace std;

int blockcoverdtype[TYPE][BLOCK_Y][BLOCK_X]=
{
    {{0,0},{0,1},{1,1}},    //type 1
    {{0,0},{0,1},{1,0}},    //type 2
    {{0,0},{1,0},{1,1}},    //type 3
    {{0,0},{1,0},{-1,-1}}   //type 4
};

int main()
{
    int testcase;

    while(testcase)
    {
        //필요한 객체 및 변수 선언부 
        int height;                          //판의 높이(보드의 세로 dy)
        int width;                        //판의 너비 (보드의 가로 dx)
         cin>>height>>width;
        string* line = new string[height];

        //2차원 배열의 동적할당
        int** board = new int* [height]; //행 부터 할당
        for(int i=0; i<height; i++)
            board[i] = new int[width];
        
        //# : 검은 칸 . : 흰 칸
        //보드 입력 받아오기
        for(int i=0; i<height; i++)
            cin>>line[i];

        //보드 변환 시키기
        for(int i=0; i<height; i++)
        {
            for(int j=0; j<width; j++)
            {
                if(str[i][j]=='#')
                    array[i][j]=1;
                else if(str[i][j]=='.')
                    array[i][j]=0;
            }
        }
    

        //동적 할당 한 객체 메모리 해제 시키기
        delete[] line;
        for(int i=0; i<height; i++)
            delete[] board[i];
        delete[] board;

        testcase--;
    }
    return 0;
}