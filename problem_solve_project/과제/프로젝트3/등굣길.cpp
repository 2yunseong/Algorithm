#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#define FIRST_ARRIVE_TIME 540
#define SLEEP_TIME 1439
using namespace std;
/*
    입/출력 예시를 바탕으로 생각해보자.
    첫번째 케이스는, 각각 시간의 분이 480, 481, 482, 483이다.
    따라서 한대의 버스 밖에 운영하지 않지만,
    학생들이 모두 타도, 전남이는 정각에 탈 수 있다. 한자리가 비니까 무조건 탈 수 있다.(09:00)

    두번째 예시를 보자.
    각각의 학생들의 도착 시간을 정렬하면, 480, 549, 550 이다.
    일단 9시나 9시(540분) 이전에 도착한 학생만 탑승한다.
    그러기 때문에 08:00 학생만 탄다.
    그 이후 간격이 10분이기 때문에, 550분(09:10)에는 2명의 학생이 탑승하는데,
    이게 마지막 버스이기 때문에 전남이는 타야한다.
    버스는 두명만 수용가능한데, 전남이가 타려면 549(09:09)분에는 와야 550(09:10)인 친구보다 먼저 타므로
    549(09:09)분에는 와야 한다.

    세 번째 예시를 보자.
    23:59에 도착한 학생은 집을 돌아간다.
    버스는 1대 밖에 운영하지 않으므로,
    따라서 전남이는 09:00에는 나와야 한다.

    두 가지 케이스로 나눌 수 있겠다. 첫 번째 예시와 두 번째 예시로 보면
    1. 마지막 버스를 탈 빈 공간이 있을 경우
        마지막 버스를 탈 수 있는 경우에는, 전남이는 마지막 버스가 도착하는 시간에 와야한다.
    2. 마지막 버스를 탈 빈 공간이 없을 경우
        마지막 버스에 자리가 남지 않으면, 탈 수 있는 가장 마지막 친구의 시간보다 1분 일찍 와야
        그 친구를 제치고 탈 수 있기 때문이다.
*/
vector<string> split(string input, char delimiter)
{ //공백을 기준으로 슬라이싱하여 string 벡터에 차례대로 넣어주는 함수

    vector<string> result;  //슬라이싱된 string들을 저장할 string 벡터 선언
    stringstream ss(input); // stringstream 객체 ss를 선언하고  input 문자열 (공백이 포함되어있는 문자열)로 초기화
    string temp;

    while (getline(ss, temp, delimiter))
    { //입력스트림 객체인 ss에서 delimiter를 만날때까지의 string을 뽑아내temp에 저장
        result.push_back(temp);
    }
    return result;
}

int convertStringTimeToInteger(string param)
{
    // 각 시간을 시, 분의 숫자로 바꾸기
    string hourString = param.substr(0, 2);
    string minString = param.substr(3, 4);

    // 각 숫자 문자열을 정수형으로 변환
    int hour = stoi(hourString);
    int min = stoi(minString);
    // 시간을 분단위로 변환
    int timeToMin = hour * 60 + min;

    return timeToMin;
}

// 정답을 문자열로 변환
string convertIntegerToString(int param)
{
    // 분 단위 시간을 다시 시 , 분으로 나누기
    int hour = param / 60;
    int min = param % 60;

    // 각 시간 값을 스트링으로 저장
    string hourString;
    string minString;

    // 10보다 작을 때 앞에 0을 붙여줘야함.
    if (hour < 10)
    {
        hourString = "0";
    }

    if (min < 10)
    {
        minString = "0";
    }
    // 시간 붙이기
    hourString += to_string(hour);
    minString += to_string(min);
    // 정답 형식으로 변경
    string ret = hourString + ':' + minString;
    // 리턴
    return ret;
}

int main()
{
    int n;                                // 운행 횟수
    int t;                                // 간격
    int m;                                // 최대 수용량
    int busArriveMin = FIRST_ARRIVE_TIME; //버스는 9시부터 도착한다. 이걸 분으로 표시
    vector<string> timetables;            //시간들을 담을 벡터변수
    string timetable;                     // 입력받을 학생들의 도착시간
    vector<int> busWaitingQueue;          // 학생들의 도착시간을 int형으로 변환에 담는 배열
    int answer;                           // 전남이가 버스정류장에 도착해야하는 시간
    cin >> n >> t >> m;

    cin.ignore();                       //버퍼에 엔터가 남아있으면 getline에서 이미 입력을 받은 것으로 처리하기 때문에 getline전에 버퍼를 비워줌
    getline(cin, timetable);            //엔터가 들어오기 전까지 공백을 포함하여 문자열 입력받기
    timetables = split(timetable, ' '); // split 함수를 이용해서 입력받는 문자열을 공백을 기준으로 슬라이싱

    clock_t start = clock();                      // 실행시간 측정
    int timeTablesVectorSize = timetables.size(); // timeTables의 사이즈
    // string -> int 로 변환해 busWaitingQueue에 넣어준다.
    for (int i = 0; i < timeTablesVectorSize; i++)
    {
        busWaitingQueue.push_back(convertStringTimeToInteger(timetables[i]));
    }
    // 먼저 온 순으로 정렬
    sort(busWaitingQueue.begin(), busWaitingQueue.end());

    int getBusIdx = 0; // 버스에 태울 학생의 인덱스
    // 버스 횟수 만큼 반복
    for (int i = 0; i < n; i++)
    {
        int humanCount = 0; // 버스에 몇명 탔는지 확인하는 배열
        // 지금 버스에 몇 명탈 수 있는지 계산해본다.
        while (humanCount < m)
        {
            // 지금학생이 이번 버스에 탈 수 있는 시간에 왔다면, 카운트를 늘린다.
            if (busWaitingQueue[getBusIdx] <= busArriveMin)
            {
                humanCount++;
                getBusIdx++;
                // 이제 꽉 찼다면, 다음버스로 넘어간다.
                if (humanCount >= m)
                    break;
                // 남은 학생이 없다면, 반복문을 종료한다.
                if (timeTablesVectorSize == getBusIdx)
                    break;
            }
            else if (busWaitingQueue[getBusIdx] == SLEEP_TIME)
            {
                getBusIdx++;
                // 남은 학생이 없다면, 반복문 종료
                if (timeTablesVectorSize == getBusIdx)
                    break;
            }
            // 아니라면, 더이상 버스에 탈 수 없으므로 반복문 종료
            else
            {
                break;
            }
        }
        // 해당 버스가 마지막 버스 인지 검사한다.
        if (i == n - 1)
        {
            // 마지막 버스가 꽉 차지 않았다면, 용봉이는 마지막 버스 시간에 와야함.
            if (humanCount < m)
            {
                answer = busArriveMin;
            }
            if (humanCount == m)
                answer = busWaitingQueue[getBusIdx - 1] - 1;
        }
        // 마지막 버스가 아니라면, 마지막 버스를 향해 반복문을 돌리자. 그전에, 출발 시간을 변경한다.
        busArriveMin += t;
    }

    cout << convertIntegerToString(answer) << endl;
    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC); // 소요 시간 출력
    return 0;
}