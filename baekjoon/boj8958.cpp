#include <iostream>
#include <string>

using namespace std;

int score(string str)
{
    int ret = 0 ;
    int tempscore = 1;
    for(int i=0; i<(int)str.size(); i++)
    {
        if(str[i]=='O')
            ret+=tempscore++;
        else if(str[i]=='X')
            tempscore=1;
    }
    
    return ret;
}
int main()
{
    int testcase;
    cin>>testcase;
    string* str = new string[testcase];
    int* answer = new int[testcase];

    for(int i=0; i<testcase; i++)
        cin>>str[i];
    
    for(int i=0; i<testcase; i++)
        answer[i] = score(str[i]);
        
    for(int i=0; i<testcase; i++)
    	cout<<answer[i]<<endl;
    
    delete[] str;
    delete[] answer;
    return 0 ;
}
