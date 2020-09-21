#include <iostream>
#include <string>

using namespace std;

int main()
{
    int testcase;

    cin>>testcase;

    string* answer = new string[testcase];

    for(int i=0; i<testcase; i++)
        cin>>answer[i];
    

    for(int i=0; i<testcase; i++)
            cout<<"Hello, "<<answer[i]<<'!'<<endl;
    delete[] answer;
    return 0;
}

/*
RTE (SIGSEGV: segmentation fault, probably incorrect memory access or stack overflow)
string* answer = new string[5]; <- 이게 문제다. 함부로 testcase의 갯수를 나도 모르게 정해버림.
예제를 보면 testcase의 개수가 5개라고 나와있다고 무의식적 으로 5를 때려박았다. */
