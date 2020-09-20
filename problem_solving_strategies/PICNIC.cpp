#include <iostream>

using namespace std;

bool arefriends[10][10];

void ShowArefriend()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(arefriends[i][j]==true)
                printf("T ");
            else
                printf("X ");
        }
        cout<<endl;
    }
}
//taken[i] -> true:짝을 찾음. false:짝을 못찾음
int countpairing(bool taken[10], int n)
{ 
    int firstman = -1;
    for(int i=0; i<n; i++)
    {
        if(!taken[i])//짝을 못찾은 친구중에 가장 빠른 자
        {
        firstman = i;
        break;
        }
    }
    //base case 1: 짝을 모두 다 찾았을 경우
    if(firstman == -1) return 1; 

    int ret = 0;
    for(int i=firstman+1; i<n; i++)
    {
            if(!taken[i] && arefriends[i][firstman])  //arefriend의 j i 순서가 중요
            {
                taken[i]=taken[firstman]=true;
                ret+=countpairing(taken, n);
                taken[i]=taken[firstman]=false;
            }
    }
    return ret;			//이 문장이 있어야 1이 더 안더해지고 종료가 된다.
}
int main()
{
    int testcase;

    cin>>testcase;
    int* answer = new int[testcase];

    for(int i=0; i<testcase; i++)
    {
        int friend_num;     //학생의 수
        int friend_pair;    //친구 쌍의 수
        cin>>friend_num>>friend_pair;
        //친구 쌍의 수 만큼 입력을 받아서, arefriend에 저장한다.
        for(int i=0; i<friend_pair; i++)
        {
            int t_a, t_b;
            cin>>t_a>>t_b;
            arefriends[t_b][t_a]=true;
            arefriends[t_a][t_b]=true;
        }
        bool take[10]={false};
        answer[i]=countpairing(take , friend_num);
        for(int i=0; i<10; i++)
        {
            take[i]=false;
            for(int j=0; j<10; j++)
            arefriends[i][j]=false;
        }
    }

    for(int i=0; i<testcase; i++)
        cout<<answer[i]<<endl;
    delete[] answer;
    return 0;
}
