#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<int> v;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
    {
        printf("%d\n", *iter);
    }

    return 0;
}