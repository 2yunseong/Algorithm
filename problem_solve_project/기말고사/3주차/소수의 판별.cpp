#include <iostream>
#include <cmath>
using namespace std;

void solve(int tc, int num)
{
    cout << "Case #" << tc << '\n';
    bool isPrime = true;
    if (num <= 1)
    {
        cout << "NO" << '\n';
        return;
    }
    if (num == 2)
    {
        cout << "YES" << '\n';
        return;
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    cout << (isPrime ? "YES" : "NO") << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++)
    {
        int temp;
        cin >> temp;
        solve(i + 1, temp);
    }

    return 0;
}