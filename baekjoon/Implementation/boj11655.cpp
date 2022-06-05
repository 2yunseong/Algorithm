#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<char> smallCases;
    vector<char> largeCases;
    char s = 'a';
    char S = 'A';
    for (int i = 0; i < 26; i++)
    {
        smallCases.push_back(s++);
        largeCases.push_back(S++);
    }

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] > 96 && str[i] < 123)
        {
            int idx = str[i] - 97;
            idx += 13;
            idx %= 26;
            cout << smallCases[idx];
            continue;
        }
        if (str[i] > 64 && str[i] < 91)
        {
            int idx = str[i] - 65;
            idx += 13;
            idx %= 26;
            cout << largeCases[idx];
            continue;
        }
        else
        {
            cout << str[i];
        }
    }
    return 0;
}