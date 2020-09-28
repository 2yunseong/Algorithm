#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N; //number of people
    int k; //kill frequency

    // 1: die 0:arrive
    vector<int> people;
    vector<int> answer;

    int idx = 0;
    int count = 0;
    bool finish = true;

    //problem input
    cin>>N>>k;

    //already exclude people[0]
    people.push_back(1);
    answer.push_back(0);
    //join people
    for (int i = 0; i < N; i++)
        people.push_back(0);

    //initialize count
    int last = 0;

    while (finish)
    {
        //base case : last one
        
        for (int i = 1; i < (int)people.size()-1; i++)
        {
            if (people[i] == 0)
                last++;
        }
        //더이상 살아남은 사람이 없으면
        if (last == 0)
        {
            finish = false;
            break;
        }
        //있으면 계속 진행
        else
        {
            last =0;
            //idx 설정
            while (count <= k)
            {
                //idx가 초과되면
                if (idx > N)
                    idx -= N;
                //죽어있으면
                if (people.at(idx) == 1)
                    idx++;

                //살아있으면
                else if (people.at(idx) == 0)
                {
                    idx++;
                    count++;
                }
            }

            //idx를 설정했으므로, 죽인다
            people.at(idx) = 1;
            answer.push_back(idx);
            //count 초기화
            count = 0;
        }
    }
        for(int i=1; i<(int)answer.size()-1; i++)
            cout<<answer[i]<<' ';
    return 0;
}
