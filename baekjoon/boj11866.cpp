#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N; //number of people
    int k; //kill frequency
    queue<int> people;
    vector<int> answer;
    cin>>N>>k;

    for(int i=0; i<N; i++)
        people.push(i+1);

    while(people.size()>0)
    {
        for(int i=1; i<k; i++)
        {
            people.push(people.front());
            people.pop();
        }
        answer.push_back(people.front());
        people.pop();
    }

    cout<<'<';
    for(int i=0; i<answer.size(); i++)
    {
    	if(i==(int)answer.size()-1)
    	cout<<answer[i];
    	else
        cout<<answer[i]<<", ";
    }
    
    cout<<'>';

    return 0;
}
