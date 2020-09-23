#include <iostream>
#include <vector>


using namespace std;

bool isright(int n)
{
    bool ret = false;
    int temp = n;
    vector<int> digit;
    //ìë¦¿ìˆ˜ ì €ì¥í•˜ê¸°
    while(temp!=0)
    {
        digit.push_back(temp%10);
        temp/=10;
    }
    //2ìë¦¬ ìˆ˜ ì¼ë•Œ
    if((int)digit.size()==2)
    {
        if(digit[0]==digit[1])
            ret = true;
    }
    //3ìë¦¬ ìˆ˜ ì¼ë•Œ
    else if((int)digit.size()==3)
    {
        if(digit[0]==digit[2])
            ret = true;
    }
    //4ìë¦¬ ìˆ˜ ì¼ë•Œ
    else if((int)digit.size()==4)
    {
        if((digit[0]==digit[3])&&(digit[1]==digit[2]))
            ret = true;
    }
    //5ìë¦¬ ìˆ˜ ì¼ë•Œ
    else if((int)digit.size()==5)
    {
         if((digit[0]==digit[4])&&(digit[1]==digit[3]))
            ret = true;
    }
    return ret;
}
int main()
{
    vector<int> num;
    int temp;

    while(1)
    {
        cin>>temp;
        if(temp==0)
            break;
        else
            num.push_back(temp);
    }

    for(int i=0; i<num.size(); i++)
    {
        //1~9
        if(num[i]<10)    
            cout<<"yes"<<endl;
        //10~99999
        else
        {
            if(isright(num[i]))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
    return 0;
}

/* Ç×»ó ¹üÀ§ ¼³Á¤À» ÀßÇØÁÖÀÚ.
ÇÊ¿äÇÒ ¶§´Â Á¶°Ç¹®À» ¿©·¯ °³ ½áÁÖ´Â °Íµµ ÇÊ¿äÇÏ´Ù.
Á¶°Ç¹®À» ´ë¿©¼¸°³ Àû´Â °É ²¨¸®Áö ¸»ÀÚ. */ 
