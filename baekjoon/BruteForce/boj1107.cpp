#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isBroken[10];

int isMade(int num)
{
    string numStr = to_string(num);

    for (int i = 0; i < numStr.size(); i++)
    {
        if (isBroken[numStr[i] - 48] == 1)
            return 0;
    }
    return numStr.size();
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int m;
    int plusButton = 0;
    int minusButton = 0;
    int lowRangeCount = -1;
    int highRangeCount = -1;
    int answer = 0;

    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        isBroken[temp] = 1;
    }

    int onlyPlusOrMinusCount = n > 100 ? (n - 100) : (100 - n);
    // cout << "only +, - :" << onlyPlusOrMinusCount << endl;

    for (int i = n; i >= 0; i--)
    {
        int madeNumber = isMade(i);
        if (madeNumber == 0)
        {
            plusButton++;
        }
        else
        {
            lowRangeCount = madeNumber + plusButton;
            // cout << "i :" << i << "low :" << lowRangeCount << endl;
            break;
        }
    }

    for (int i = n; i < 2000000; i++)
    {
        int madeNumber = isMade(i);
        if (madeNumber == 0)
        {
            minusButton++;
        }
        else
        {
            highRangeCount = madeNumber + minusButton;
            // cout << "i :" << i << "high :" << highRangeCount << endl;
            break;
        }
    }

    if (lowRangeCount < 0)
        answer = onlyPlusOrMinusCount;
    else if (onlyPlusOrMinusCount >= lowRangeCount)
    {
        answer = lowRangeCount;
    }
    else
    {
        answer = onlyPlusOrMinusCount;
    }

    if (highRangeCount < 0)
        ;
    else if (answer >= highRangeCount)
    {
        answer = highRangeCount;
    }

    cout << answer;
    return 0;
}