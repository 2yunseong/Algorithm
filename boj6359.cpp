#include <iostream>
#include <vector>

//홀수 : open 짝수 : 잠김

using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    int* answer = new int[testcase]();
    //0으로 초기화 꼭 해줘라..
    for(int i=0; i<testcase; i++)
    {
        int n;
        cin>>n;
        vector<int> room(n+1,0);   //0번방은 편의상 제외.
        
        //라운드
        for(int r=1; r<n+1; r++)    //라운드는 n번
        {
            int k =1;             //배수를 나타내는 임시변수  //r의 배수의 위치에 1씩 더한다. 열고-닫고-열고-닫고..
            int mul = 1;
            do
            {
                mul = r*k;
                if(mul>=n+1)
                    break;
                else
                {
                    room[mul]++;
                    k++;
                }
            } while (1);
                    
        }
        //도망간 사람 숫자 세기
        for(int t=0; t<n+1; t++)
            if(room[t]%2 !=0)    //룸의 번호가 홀수이면
                answer[i]++;    //탈옥성공.

    }


    for(int i=0; i<testcase; i++)
        cout<<answer[i]<<endl;

    delete[] answer;
    return 0;
}
