#include <stdio.h>
#include <stdlib.h>
#include "BidirStack.h"
#define IZONE 12

void ShowMenu(const BidirStack *s)
{
    printf("Current Flag:");
    if(!IsFlag(s)) //front
        printf("front\n");
    else
        printf("rear\n");
    
    printf("front:%2d + rear:%2d \t total: %d/%d\n",
    (s->front_ptr),
    (Capacity(s)-1-s->rear_ptr),
    Size(s),
    Capacity(s));
    printf("(1)Push (2)Pop (3)Peek (4)Print (5)Clear (6)Search (7)Change Flag (0)Exit:");
}

int main()
{
    BidirStack bst;
    int f = 0;
    if(Initialize(&bst, IZONE)== -1)
    {
        printf("fail to call stack.\n");
        printf("shut down program..\n");
        return -1;
    }

    while(f == 0)
    {
        int menu ,x;
        
    
        ShowMenu(&bst);
        scanf("%d", &menu);

        switch (menu)
        {
        case 0:
            printf("program exit.\n");
            f = 9999;
            break;
        //Push
        case 1:
            printf("Push Data:");
            scanf("%d", &x);
            if(Push(&bst, x)==-1)
                printf("stack is Full!\n");
            else
                printf("Success Push.\n");
            break;
        //Pop
        case 2:    
            if(Pop(&bst, &x)==-1)
                printf("stack is Empty!\n");
            else
                printf("Success Pop...%d\n",x);
            break;
        //Peek
        case 3:
            if(Peek(&bst, &x)==-1)
                printf("stack is Empty!\n");
            else
                printf("Success Peek...%d\n",x);
            break;
        //Print
        case 4:
            Print(&bst);
            break;
        //Clear
        case 5:
            Clear(&bst);
            printf("Clear Stack Success.\n");
            break;
        //Search
        case 6:
            printf("search target:");
            scanf("%d", &x);
            if(Search(&bst, x)==-1)
                printf("program can't find %d in stack.\n", x);
            else 
                printf("%d in stack[%d].\n",x, Search(&bst, x));
            break;
        case 7:
            ChangeFlag(&bst);
            printf("Change flag success!\n");
            break;
        default:
            break;
        }
    }
    Terminate(&bst);
    return 0;
}
