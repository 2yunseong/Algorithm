#include <stdio.h>
#define START_ 1
#define VIA_ 2
#define TO_ 3

void hanoi(int n,int start, int to, int via)
{
    if(n==1)
        move(1,start,to);
    else
    {
        hanoi(n-1,start,via,to);
        move(n,start,to);
        hanoi(n-1,via,to,start);
    }
    
}

void move(int n, int start, int to)
{  
    char arr[5] ={'n','A','B','C'};
    printf("disk %d: %c -> %c\n ", n, arr[start], arr[to]);
}

int main()
{
    int num;
    printf("num:");
    scanf("%d", &num);
 
    hanoi(num,START_,TO_ ,VIA_);

    return 0;
}
