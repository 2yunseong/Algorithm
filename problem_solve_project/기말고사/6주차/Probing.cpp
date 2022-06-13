#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        temp %= n;
        while (1)
        {
            if (v[temp] == 0)
            {
                v[temp] = 1;
                cout << temp << '\n';
                break;
            }
            else
            {
                temp++;
            }
        }
    }
    

    return 0;
}