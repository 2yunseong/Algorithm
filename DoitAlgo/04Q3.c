#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayIntQueue
{
    int max;
    int num;
    int *que;
}ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int m)
{
    if((q->que = calloc(m, sizeof(int)))==NULL)
        return -1;
    q->max = m ;
    q->num = 0;
}

int EnQueue(ArrayIntQueue *q, int x)
{
    if(q->max == q->num)
        return -1;
    
    q->que[q->num++]=x;
    return 0;
}

int DeQueue(ArrayIntQueue *q, int* x)
{
    int i;
    if(q->num==0)
        return -1;
    
    *x = q->que[0];
    for(i=0; i<q->num-1; i++)
        q->que[i] = q->que[i+1];
    
    q->num--;
    return 0;
}

void Print(const ArrayIntQueue *q)
{
    int i;
    for(i=0; i<q->num; i++)
        printf("%d ", q->que[i]);
    
    printf("\n");
}

int main()
{
    ArrayIntQueue aiq;
    int menu,temp;
    int flag =0;
    
    Initialize(&aiq, 10);
    while(flag ==0)
    {
        printf("(1) EnQueue (2)Dequeue (3)Print (0)Exit:");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Enqueue number:");
            scanf("%d", &temp);
            InQueue(&aiq,temp);
            break;
        case 2:
            DeQueue(&aiq, &temp);
            printf("dequeue : %d\n", temp);
        case 3:
            Print(&aiq);
            break;
        case 0:
            flag = 1;
            break;
        default:
            break;
        }
    }

    return 0 ;
}
