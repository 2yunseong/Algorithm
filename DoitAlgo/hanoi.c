#include <stdio.h>

#define START 1
#define MID 2
#define END 3


//1. h(n-1)  start -> mid
//2. n       start -> end
//3. h(n-1)  mid   -> end


int count = 0;

void move(int n, int start, int to)
{
    printf("move disk [%d] %d -> %d \n",n,start,to);
}
void hanoi(int n, int from, int to)
{	
    if(n>1)
        hanoi(n-1,from,6-from-to);
    printf("move disk [%d] %d -> %d \n",n, from ,to);
    count++;
    if(n>1)
        hanoi(n-1,6-from-to,to);
}

void hanoi2(int n, int start, int to, int via)
{
    if(n==1)
        move(1,start,to);
    else
    {
        hanoi2(n-1,start,via,to);
        move(n,start,to);
        hanoi2(n-1,via,to,start);
    }  
}

int main()
{
    int n;
    printf("n:");
    scanf("%d", &n);
    hanoi(n,START,END);
    printf("hanoi2:\n");
    hanoi2(n,START,END,MID);
	printf("count:%d", count);
    return 0;
}
