#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> fibo;
    fibo.push_back(0); // 0
    fibo.push_back(0); // 1
    fibo.push_back(1); // 2
    int tc;
    int ptr = 3;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int temp;
        cin >> temp;
        for (; ptr <= temp; ptr++)
        {
            int fnum = (fibo[ptr - 1] + fibo[ptr - 2]) % 100000000;
            fibo.push_back(fnum);
        }
        cout << fibo[temp] << '\n';
    }

    return 0;
}