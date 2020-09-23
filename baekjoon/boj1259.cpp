#include <iostream>
#include <vector>


using namespace std;

bool isright(int n)
{
    bool ret = false;
    int temp = n;
    vector<int> digit;
    //자릿수 저장하기
    while(temp!=0)
    {
        digit.push_back(temp%10);
        temp/=10;
    }
    //2자리 수 일때
    if((int)digit.size()==2)
    {
        if(digit[0]==digit[1])
            ret = true;
    }
    //3자리 수 일때
    else if((int)digit.size()==3)
    {
        if(digit[0]==digit[2])
            ret = true;
    }
    //4자리 수 일때
    else if((int)digit.size()==4)
    {
        if((digit[0]==digit[3])&&(digit[1]==digit[2]))
            ret = true;
    }
    //5자리 수 일때
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

/* �׻� ���� ������ ��������.
�ʿ��� ���� ���ǹ��� ���� �� ���ִ� �͵� �ʿ��ϴ�.
���ǹ��� �뿩���� ���� �� ������ ����. */ 
