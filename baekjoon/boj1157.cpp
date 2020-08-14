#include <iostream>
#include <string>
#define ALPHA_NUM 26
#define ASCII_SMALL 97
#define ASCII_LARGE 65
using namespace std;

/*
    1.대문자 카운트 배열 과 소문자 카운트 배열을 만든다.
    2.결과 카운트 배열 = 대문자 카운트 배열 + 소문자 카운트 배열
    3.결과 카운트 배열이 가장 큰 값이 가장 많이 쓰인 단어.(대문자로 출력)
    4.아스키 코드로 변환해서 구현.
    5.같은 값이 있으면 물음표를 출력해야한다.
    -일단 최대 값을 찾고, 그 최대값을 갖는 idx 도 저장한다
    -그 이후, 다시 한번 total_count를 탐색해, 
    -그 최대값과 일치하는 값이 하나 더 있으면 ?를 출력한다.
    A~Z: 65~90
    a~z: 97~122
*/


int main()
{
    int small_count[ALPHA_NUM]={0};
    int large_count[ALPHA_NUM]={0};
    int total_count[ALPHA_NUM]={0};
    int maxium = -1024;
    int max_idx ;
    int same_flag = 0;
    string str;
    string::iterator iter;
    //input string 
    cin>>str;

    for(iter=str.begin(); iter!=str.end(); iter++)
    {
        int temp = (int)*iter;
        //upper case
        if(ASCII_LARGE<=temp && temp<=90)
            large_count[temp-ASCII_LARGE]++;
        
        //lower case
        else if(ASCII_SMALL<=temp && temp<=122)
            small_count[temp-ASCII_SMALL]++;
    }

    for(int i=0; i<ALPHA_NUM; i++)
        total_count[i] = small_count[i]+large_count[i];

    //1.find maxium
    for(int i=0; i<ALPHA_NUM; i++)
        if(maxium<total_count[i])
            {
                maxium = total_count[i];
                max_idx = i ;
            }
    
    //2.check same maxium
    for(int i=0; i<ALPHA_NUM; i++)
    {
        if(i!=max_idx)
        {
            if(maxium==total_count[i])
                {
                    same_flag = 1;
                    break;
                }
        }
        else
            continue;
    }
    

    //output
    if(same_flag==1)
        cout<<'?';
    else
        cout<<(char)(max_idx+ASCII_LARGE);
    
    return 0;
}