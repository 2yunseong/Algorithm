#include <iostream>
#define MALE 1
using namespace std;

//학년 마다 여학생과 남학생의 수
int girl_count[7];
int boy_count[7];

void calculate(int arr[],int max_room, int& count)
{
    int gra = 1;
    while(gra<6+1)
    {
        if(arr[gra]==0)
            continue;
        else
        {
            //max_room 보다 작은경우
            if(arr[gra]/max_room==0)
                count++;
            //나누어 떨어지는 경우
            else if(arr[gra]/max_room!=0 && arr[gra]%max_room==0)
                count+=arr[gra]/max_room;
            //나누어 떨어지지 않는 경우
            else if(arr[gra]/max_room!=0 && arr[gra]%max_room!=0)
            {
                count+=arr[gra]/max_room;
                count++;
            }
        }
        gra++; 
    }
}
int main()
{
    //K:max room capacity
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int sex,grade;
    cin>>n>>k;
    int room_count = 0;
    //input
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

/* 시간 초과 가 뜬다.. 빨리 고쳐볼것..ㅠ*/