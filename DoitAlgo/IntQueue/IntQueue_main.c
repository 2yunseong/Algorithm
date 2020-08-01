#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

int main()
{
    IntQueue iq;
    int menu;
    int flag = 0;
    int input;
    int output;
    int search_idx;

    Initialize(&iq, 15);

    while (flag == 0)
    {
        printf("current data : %d/%d \n",Size(&iq), Capacity(&iq));
        printf("(1)Enque (2)Deque (3)PeekData (4)Clear (5)Search (6)Print (0)Exit :");
        scanf("%d", &menu);

        switch (menu)
        {
        //Exit
        case 0:
            flag = -1;
            break;
        //Enque
        case 1:
        if(IsFull(&iq))
            {
                printf("Queue is Full!\n");
                break;
            }
        else
        {
            printf("Enque data:");
            scanf("%d", &input);
            if(Enque(&iq , input)==-1)
                printf("fail Enque!\n");
            else       
                printf("success Enque.\n");
            break;
        }
        //Deque
        case 2:
            if(Deque(&iq, &output)==-1)
            {
                printf("que is empty!\n");
                break;
            }
            else
                printf("success Deque : %d", output);
            break;
        //Peek 
        case 3:
            if(Peek(&iq, &output)==-1)
            {
                printf("queue is empty!\n");
                break;
            }
            else
                printf("success peek : %d\n", output);
            break;
        //Clear
        case 4:
            Clear(&iq);
            printf("Clear success.\n");
            break;
        //Search
        case 5:
            printf("want search:");
            scanf("%d", &input);
            search_idx = Search(&iq, input);
            if(search_idx == -1)
            {
                printf("search fail!\n");
                break;
            }   
            else
            {
                printf("%d in queue[%d].\n", input, search_idx);
                break;
            }
        //Print
        case 6:
            Print(&iq);
            break;
        default:
            break;
        }
    }

    Terminate(&iq);
    return 0;
}
