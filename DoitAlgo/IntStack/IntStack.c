#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL)
    {
        printf("fail to allocate memory!\n");
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int data)
{
    if (s->ptr >= s->max) 
        return -1;
    
    s->stk[s->ptr++] = data;
    return 0;
}

int Pop(IntStack *s, int *x)
{
    if (s->ptr <= 0)
    {
        printf("stack is empty!\n");
        return -1;
    }
    *x = s->stk[s->ptr--];
}

int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0)
        return -1;
    *x = s->stk[s->ptr-1];
    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0;
    return 0;
}

int Capacity(const IntStack *s)
{
    return s->max;
}

int Size(const IntStack *s)
{
    return s->ptr;
}

int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0; 
}

int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int key)
{
    int i;
        if(IsEmpty(s))
            printf("Stack is Empty!\n");
        else
        for(i=0; i<s->ptr; i++)
        {
            if(s->stk[i]==key)
                return i;
        }
        return -1;    
}

void Print(const IntStack *s)
{
    int i;
    if(IsEmpty(s))
        printf("stack is Empty!\n");
    else 
    for(i=s->ptr-1; i>=0; i--)
        printf("s[%2d]:|%3d|\n",i, s->stk[i]);
       printf("       --- \n");    
}

void Terminate(IntStack *s)
{
    if(s->stk!=NULL)
        free(s->stk);
    s->max =NULL;
    s->ptr =NULL;
}



