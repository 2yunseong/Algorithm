#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int Initialize(IntQueue *q, int m)
{
    if((q->que = calloc(m,sizeof(int)))==NULL)
        return -1;
    q->max = m;
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    return 0;
}

int Enque(IntQueue *q, int x)
{
    if(IsFull(&q))
        return -1;
    else
    {
        q->que[q->rear++]=x;
        q->num++;
        if(q->rear >= q->max)
            q->rear = 0;
        return 0;
    }
}

int Deque(IntQueue *q, int *x)
{
    if(IsEmpty(&q))
        return -1;
    else
    {
        *x = q->que[q->front++];
        q->num--;
        if(q->front >= q->max)
            q->front =0;
        return 0;
    }
}

int Peek(const IntQueue *q, int *x)
{
    if(IsEmpty(&q))
        return -1;
    *x = q->que[q->front];
    return 0;
}

void Clear(IntQueue *q)
{
    int i;
    q->num = 0;
    q->front = 0;
    q->rear = 0; 
    
    for(i=0; i<q->max; i++)
        q->que[i]=NULL;
}

int Capacity(const IntQueue *q)
{
    return q->max;
}

int Size(const IntQueue *q)
{
    return q->num;
}

int IsEmpty(const IntQueue *q)
{
    if(q->num==0)
        return 1;
    else 
        return 0;
}

int IsFull(const IntQueue *q)
{
    if(q->num == q->max)
        return 1;
    else
        return 0;
}

int Search(const IntQueue *q, int x)
{
    int i;
    for(i=0; i<q->max; i++)
    {
        if(q->que[i]==x)
            return i;
    }
    return -1;
}

void Print(const IntQueue *q)
{
    int i;
    for(i=0; (i>=q->front) || (i>=q->rear); i++)
        printf(" | %d | \n", q->que[i]);
}

void Terminate(IntQueue *q)
{
    if(q->que != NULL)
    free(q->que);
    q->max = 0;
    q->front = 0;
    q->rear = 0;
    q->num = 0;
}










