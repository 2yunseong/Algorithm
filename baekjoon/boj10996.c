#include <stdio.h>

/*
1 -> *          

2->  *          2Set 2reps
      *
     *
      * 

*/
int main()
{
    int num ;
    int i,j;
    scanf("%d", &num);

    for(i=0; i<num*2; i++)    //Set
    {
        if(i%2==0)
        {
        	for(j=0; j<num; j++)
        	{
        		if(j%2==0)
        			printf("*");
        		else
        			printf(" ");
			}
			printf("\n");
		}
		else
		{
			for(j=0; j<num; j++)
        	{
        		if(j%2==0)
        			printf(" ");
        		else
        			printf("*");
			}
			printf("\n");
		}
        
    }

    return 0;
}
