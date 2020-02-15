#include<iostream>
using namespace std;
/*
first basket : F
second basket: S

case 1: F apple -> S   F:orange 
        S orange-> F   S:apple

case 2: F orange-> S   F:apple 
        S apple -> F   S:orange

-- move count --
case 1:  number of apple in F  + number of orange in S
case 2:  number of orange in F + number of apple  in S

*/
int Min(int a,int b)
{
    return a>b ? b : a; 
}


int main()
{
    int first_apple,first_orange;
    int second_apple,second_orange;

    cin>>first_apple>>first_orange;
    cin>>second_apple>>second_orange;

    int move_case_one = first_apple+second_orange;
    int move_case_two = first_orange+second_apple;

    cout<<Min(move_case_one, move_case_two);

    return 0 ;
}