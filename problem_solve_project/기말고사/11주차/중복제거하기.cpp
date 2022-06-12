#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        // 존재할 경우
        if (s.find(temp) != s.end())
        {
            cout << "DUPLICATED" << '\n';
        }
        else
        {
            cout << "OK" << '\n';
            s.insert(temp);
        }
    }

    return 0;
}