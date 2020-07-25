#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"
#define STACK_MAX 64
int main()
{
    IntStack it;
    int flag = 0;
    if(Initialize(&it, STACK_MAX)== -1)
    {
        printf("fail to call stack.\n");
        printf("shut down program..\n");
        return -1;
    }

    while(flag == 0)
    {
        int menu ,x;
        
        printf("data count:%02d/%d\n", Size(&it), Capacity(&it));
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear (6)Search (0)Exit:");
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            printf("program exit.\n");
            flag = 9999;
            break;
        //Push
        case 1:
            printf("Push Data:");
            scanf("%d", &x);
            if(Push(&it, x)==-1)
                printf("stack is Full!\n");
            else
                printf("Success Push %d in stack[%d].\n", x, (it.ptr)-1);
            break;
        //Pop
        case 2:    
            if(Pop(&it, &x)==-1)
                printf("stack is Empty!\n");
            else
                printf("Success Pop %d in stack[%d].\n",x, (it.ptr));
            break;
        //Peek
        case 3:
            if(Peek(&it, &x)==-1)
                printf("stack is Empty!\n");
            else
                printf("Success Peek %d in stack[%d].\n",x, (it.ptr)-1);
            break;
        //Print
        case 4:
            Print(&it);
            break;
        //Clear
        case 5:
            Clear(&it);
            printf("Clear Stack Success.\n");
            break;
        //Search
        case 6:
            printf("search target:");
            scanf("%d", &x);
            if(Search(&it, x)==-1)
                printf("program can't find %d in stack.\n", x);
            else 
                printf("%d in stack[%d].\n",x, Search(&it, x));
            break;
        default:
            break;
        }
    }
    Terminate(&it);
    return 0;
}
