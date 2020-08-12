#include <iostream>
#include <string>

using namespace std;
/* ASCII code
a : 97
~
z : 122
*/

/*
   
    그룹 단어 찾기
1.그룹 단어가 2개 이상일때
    ex)aaaba
   0~1 aa 비교. grchek++;
   1~2 aa 비교. grchek++;
   2~3 ab 비교 x
   3~4 ba 비교 x

   알파벳 카운트  ==grchek+1 이면 그룹단어

2.단어가 알파벳 하나로만 구성되어있을때.
grchek의 값은 0이 된다.
따라서 알파벳 카운트 >1 을 만족하는 값이 없으면 그룹단어.
*/


int main()
{
    int group_word_count = 0;
    int test_case; 
    

    //input test case.
    cin>>test_case;

    while(test_case!=0)
    {
        string *str = new string;
        
        getline(cin,*str,'\n');
        
        //초기화
        int group_check = 0;
        int alphabet_check_array[26]={0};

        //그룹 단어 탐색
        for(int i=0; i<(int)str->size(); i++)
        {
            string temp;
            string last_temp;
            last_temp =str[i-1];
            temp =str[i];
            int last_idx ;
            int idx =stoi(temp)-97; 
               //change int
            if(i>0)  
            {           
                last_idx =stoi(last_temp)-97; //set last index

                if(last_idx==idx)   //find group word
                {
                    group_check++;
                    alphabet_check_array[idx]++;
                }
            }
            alphabet_check_array[idx]++;
        }
        //단어가 알파벳 하나로만 구현되어 있을때.
        if(group_check==0)  
        {
            int flag = 1;
            for(int i=0; i<(int)str->size(); i++)
            {
                if(alphabet_check_array[i]>1)   //알파벳이 하나 더 나오면
                    {
                        flag = 0;
                        break;
                    }
            }
            if(flag==0)
                continue;
            else if(flag==1)
                group_word_count++;
        }
         //그룹 단어로 되어있을때
        else   
        {
            int flag_group=1;
            for(int i=0; i<(int)str->size(); i++)
            {
                if(alphabet_check_array[i]=!(group_check+1))
                {
                    flag_group =0 ;
                    break;
                }
            }
            if(flag_group==1)
                group_word_count++;
        }

        str->clear();
        test_case--;
    }

    cout<<group_word_count;

    return 0;
}
