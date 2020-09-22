#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int testcase;
    cin>>testcase;
    vector<int> *student_score = new vector<int>[testcase];
    double* average = new double[testcase]();
    int* high_student_num = new int[testcase]();
    double* answer = new double[testcase];
    //동적배열 0으로 초기화 하는 방법. ()

    //score 입력 받아오기
    for(int i=0; i<testcase; i++)
    {
        int student_num ;
        cin>>student_num;
        for(int j=0; j<student_num; j++)
        {
            int temp;
            cin>>temp;
            student_score[i].push_back(temp);
        }
    }

    //평균 구해오기 
    for(int i=0; i<testcase; i++)
    {
        for(int j=0; j<(int)student_score[i].size(); j++)
            average[i]+=(double)student_score[i][j];
        average[i]/=(double)student_score[i].size();
    }

    //평균보다 높은 인원 수 구해오기
    for(int i=0; i<testcase; i++)
    {
        for(int j=0; j<(int)student_score[i].size(); j++)
        {
            if(average[i]<student_score[i][j])
                high_student_num[i]++;
        }
    }
    //답 구하기. (평균보다 높은 비율) (높은 학생*100)/(전체 학생)
    for(int i=0; i<testcase; i++)
        answer[i] = (high_student_num[i]*(double)100)/(double)student_score[i].size();
    
    //답 출력.
    for(int i=0; i<testcase; i++)
        printf("%.3f\%\n", answer[i]);

    //동적 할당 해제.
    delete[] student_score;
    delete[] average;
    delete[] high_student_num;
    delete[] answer;
    
    return 0;
}


/* 반올림 출력:%.3f */
