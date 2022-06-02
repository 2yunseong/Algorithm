#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> adjArr;
    string s;
    cin >> s;
    int sSize = s.size();
    for (int i = 0; i < sSize; i++)
    {
        adjArr.push_back(s.substr(i, sSize));
    }

    sort(adjArr.begin(), adjArr.end());

    for (vector<string>::iterator iter = adjArr.begin(); iter != adjArr.end(); iter++)
    {
        cout << *iter << '\n';
    }
    return 0;
}