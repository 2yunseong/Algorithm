#include <stdio.h>
#include <stdlib.h>
#include "BidirStack.h"

int Initialize(BidirStack *s, int n)
{
    if((s->stk = calloc(n, sizeof(int)))==NULL)
        return -1;
    s->front_ptr = 0;
    s->rear_ptr = n-1;
    s->max = n;
    s->flag = 0 ;
    return 0;
}

void ChangeFlag(BidirStack *s)
{
    if(s->flag ==0)
        s->flag = 1;
    else if(s->flag==1)
        s->flag = 0;
}

int IsFlag(const BidirStack *s)
{
    return s->flag;
}

int IsFull(const BidirStack *s)
{
    return s->front_ptr > s->rear_ptr ;
}

int IsEmpty(const BidirStack *s)
{
    return (s->front_ptr==0) && (s->rear_ptr == s->max-1);
}


int Push(BidirStack *s, int data)
{
    if(!IsFlag(s))   //front
    {
        if(IsFull(s))
            return -1;
        else
        {
            s->stk[s->front_ptr++] = data;
            return 0;
        }        
    }
    else    //rear
    {
        if (IsFull(s))
            return -1;
        else
        {
            s->stk[s->rear_ptr--] = data;
            return 0;
        }
    }
    return -1;
}

int Pop(BidirStack *s, int *x)
{
    if(!IsFlag(s))  //front
    {
        if(IsEmpty(s))
            return -1;
        else
        {
            *x = s->stk[s->front_ptr--];
            return 0;     
        }
        
    }
    else
    {
        if (IsEmpty(s))
        {
            return -1;
        }
        else
        {
            *x = s->stk[s->rear_ptr++];
            return 0;
        }
    }
    return -1;
}

int Peek(const BidirStack *s, int *x)
{
    if (!IsFlag(s))
    {
        if (IsEmpty(s))
        {
            return -1;
        }
        else
        {
            *x = s->stk[s->front_ptr-1];
            return 0;
        }
    }
    else
    {
        if (IsEmpty(s))
        {
            return -1;
        }
        else
        {
            *x = s->stk[s->rear_ptr+1];
            return 0;
        }        
    }
    return -1;
}

void Clear(BidirStack *s)
{
    int i;
    s->front_ptr = 0;
    s->rear_ptr = s->max-1;
    s->flag = 0;
}

int Capacity(const BidirStack *s)
{
    return s->max;
}

int Size(const BidirStack *s)
{
    return (s->max-1-s->rear_ptr)+(s->front_ptr) ;
}

int Search(const BidirStack *s, int x)
{
    int i;
    if(IsEmpty(s))
        return -1;
    for(i=0; i<Capacity(s); i++)
    {
        if(s->stk[i]==x)
            return i;
    }
    return -1;
}

void Print(const BidirStack *s)
{
    int i;
    for(i=0; i<Capacity(s); i++)
    {
        if((s->front_ptr<=i)&&(i<=s->rear_ptr))
        	printf("X ");
        else
        {
            printf("%d ", s->stk[i]);
        }
    }
    printf("\n");
}

void Terminate(BidirStack *s)
{
    free(s->stk);
}





