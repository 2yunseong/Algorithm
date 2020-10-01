#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    int testcase;
    cin >> testcase;
    while (testcase)
    {
        char arr[1001];
        char cmp_arr[1001];

        cin >> arr >> cmp_arr;
        
		sort(arr, arr+strlen(arr));
		sort(cmp_arr, cmp_arr+strlen(cmp_arr));
        
        bool isSame = true;
        for (int i = 0; i < strlen(arr); i++)
        {
            if (arr[i] != cmp_arr[i])
                isSame = false;
        }
        if (isSame)
            cout << "Possible\n";
        else
        {
            cout << "Impossible\n";
        }
        testcase--;
    }

    return 0;
}
