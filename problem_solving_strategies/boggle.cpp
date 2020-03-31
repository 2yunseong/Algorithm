#include <iostream>

using namespace std ;

//board�� ������ ����.
char board[5][5] = {'U','R','L','P','M',
                    'X','P','R','E','T',
                    'G','I','A','E','T',
                    'X','T','N','Z','Y',
                    'X','O','Q','R','S'};


const int dx[8]={-1,-1,-1, 1,1,1 ,0,0}; //x��ǥ Ŀ��
const int dy[8]={-1, 0, 1,-1,0,1,-1,1}; //y��ǥ Ŀ�� 

bool inRange(int y, int x)
{
    if(y<0 || y>4)
        return false;
    if(x<0 || x>4)
        return false;
    return true;
}
//board [y][x] ���� �˰�����.(�����)
bool HasWord(int y, int x, const string& word)
{
    if(!inRange(y,x)) return false; //���� ���̸� �Ÿ���
    if(board[y][x] != word[0]) return false;     //ù�ܾ Ʋ���� �Ÿ���
    if(word.size() == 1) return true;   //�ܾ 1���� ����.

    for(int direction = 0; direction <8; direction++)//��� �� ������ Ž���Ѵ�
    {
        int nextY = y+dy[direction];
        int nextX = x+dx[direction];
        if(HasWord(nextY,nextX,word.substr(1))) //��� ȣ��
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
