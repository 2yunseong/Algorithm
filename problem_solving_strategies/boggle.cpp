#include <iostream>

using namespace std ;

//board는 임의의 예제.
char board[5][5] = {'U','R','L','P','M',
                    'X','P','R','E','T',
                    'G','I','A','E','T',
                    'X','T','N','Z','Y',
                    'X','O','Q','R','S'};


const int dx[8]={-1,-1,-1, 1,1,1 ,0,0}; //x좌표 커서
const int dy[8]={-1, 0, 1,-1,0,1,-1,1}; //y좌표 커서 

bool inRange(int y, int x)
{
    if(y<0 || y>4)
        return false;
    if(x<0 || x>4)
        return false;
    return true;
}
//board [y][x] 임을 알고있자.(행과열)
bool HasWord(int y, int x, const string& word)
{
    if(!inRange(y,x)) return false; //범위 밖이면 거른다
    if(board[y][x] != word[0]) return false;     //첫단어가 틀리면 거른다
    if(word.size() == 1) return true;   //단어가 1개면 성공.

    for(int direction = 0; direction <8; direction++)//모든 옆 범위를 탐색한다
    {
        int nextY = y+dy[direction];
        int nextX = x+dx[direction];
        if(HasWord(nextY,nextX,word.substr(1))) //재귀 호출
            return true;
    }
    return false;
}
int main()
{
    string Word_ONE = "PRETTY";
    string Word_two = "GIRL";

    if(HasWord(2,0,Word_two))
        cout<<"find!"<<endl;
    else
    {
        cout<<"cannot find!"<<endl;
    }
    
    return 0 ;
}
