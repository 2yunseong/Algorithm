#include <iostream>
#include <string>

using namespace std;

int main()
{
    int alphabet_check_array[26]={0};
    string str;
    cin>>str;

    for(int i=0; i<(int)str.size(); i++)
        alphabet_check_array[(str[i]-97)]++;

    for(int i=0; i<26; i++)
        cout<<alphabet_check_array[i]<<' ';
    
    return 0;

}