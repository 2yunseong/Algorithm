#include <iostream>
#define MALE 1
#define FEMALE 0
#define MAX_GRADE 6
using namespace std;

//학년 마다 여학생과 남학생의 수 인덱스 0의 원소는 더미데이터.
int girl_count[7];
int boy_count[7];
int room_count;

void calculate(int arr[],int max_room, int& count)
{
    int grade = 1;
    while(grade<MAX_GRADE+1)
    {
        if(arr[grade]==0);
        /*
            if(arr[grade]==0)
                continue;
            면, grade++가 실행되지않아서, 무한루프에 걸릴 수 있다.
        */
        else
        {
            //max_room 보다 작은경우
            if(arr[grade]/max_room==0)
                count++;
            //나누어 떨어지는 경우
            else if(arr[grade]/max_room!=0 && arr[grade]%max_room==0)
                count+=arr[grade]/max_room;
            //나누어 떨어지지 않는 경우
            else if(arr[grade]/max_room!=0 && arr[grade]%max_room!=0)
            {
                count+=arr[grade]/max_room;
                count++;
            }
        }
        grade++; 
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int sex,grade;
    cin>>n>>k;
    
    for(int i=0; i<n; i++)
    {
        
        cin>>sex>>grade;

        if(sex==MALE)
            boy_count[grade]++;
        else
            girl_count[grade]++;
    }
    calculate(boy_count, k, room_count);
    calculate(girl_count, k, room_count);

    cout<<room_count;
    return 0;
}

 //for문이나 while문의 {}안에서 continue 문장을 만난 순간 
 //continue문 아래에 있는 실행해야 하는 문장들을 건너 뛰고, 다음
 //       반복을 시작한다. 

 //시간 초과가 날때: 일단 무한 루프부터 의심해라. 제일 의심스러운 곳이다.