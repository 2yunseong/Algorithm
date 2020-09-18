/* 
문제명:록 페스티벌 (FESTIVAL)
문제출처:알고스팟, 문제해결전략 7p
*/

#include <iostream>
#include <vector>

using namespace std;

void ShowArray(const int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i]<<' ';
		cout<<endl;
}
int main()
{
    int testcase; 
    int aver_idx = 0;   //average_cost_answer 의 인덱스
    cin>>testcase;
    double *average_cost_answer = new double[testcase];    //testcase 개수만큼의 평균비용
    while(testcase!=0)
    {
        int maxday;     //공연장을 대여할 수 있는 날들의 최대 수. N
        int num_of_team;  //공연팀의 숫자. L
        double min_average =99999.0; //평균 최솟값 
         //평균
        scanf("%d %d",&maxday ,&num_of_team);
        int* cost = new int[maxday];
        for(int i=0; i<maxday; i++)
            cin>>cost[i];
		

        //최소 평균 비용 구하기.
        for(int i=num_of_team; i<maxday+1; i++)  // [L,N+1)
        {
            //cout<<"i :"<<i<<endl;
            for(int j=0; j<maxday-i+1; j++) // pass index [0,N+1-i) 
            {
                double average = 0.0;   //멍청하게 이걸 for 문 밖에 선언함!!!!!!!!
                for(int k=0; k<i; k++)      //실제 더하는 개수. i개
                {
                    average+=(double)cost[j+k];
                    //cout<<"plus cost["<<j+k<<"]:"<<(double)cost[j+k]<<endl;
                }
                average /= (double)i;   //평균을 구한다.
                //cout<<"average :"<<average<<endl;
                if(min_average >average)    //구한 값이 최소 평균 비용보다 작으면
                {   
                    //cout<<"find min!"<<average<<endl;
                    min_average = average;  //구한 값이 최소 평균 비용이 된다.
                }
            }
        }
        //구해온 최소평균비용을 대입.
        average_cost_answer[aver_idx++] = min_average;
        delete[] cost;
        testcase--;
    }

    for(int i=0; i<aver_idx; i++)
        printf("%.9f\n", average_cost_answer[i]);
     
    delete[] average_cost_answer;
    return 0;
}


/*FeedBack 
    -개 멍청하게 average는 j 반복문이 돌아갈 때 마다 초기화가 되어야 하는데, 이걸 for 문 밖에
    선언 했다.. 연산 상에 문제가 있는 줄 알고 20분을 삽질을 했다. 반복문 설계를 잘하는 연습을
    하자. 이거 오늘 안잡았으면 뭐가 문제인지 모르고 연등 끝낼 뻔 했다.
    -C++ 입출력 응용이 아직도 미흡하다. 연습 하도록 하자.
    -문제를 잘 좀 읽자. 소수점 7자리 까지 출력이고 각 테스트케이스 결과를 개행해서 출력해야
    하는데 다 간과해버렸다. 간단한건데 25분또 삽질.
*/
