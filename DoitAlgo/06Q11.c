#include <stdio.h>
#include <string.h>


void show_array(const int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

void show_cursor(int size, int idx)
{
    int i=0;
    for(i=0; i<size; i++)
    {
        if(i==idx)
        {
            printf(" * \n");
            break;
        }
        else
            printf("   ");
        
    }
}

void straight_insertion_sort(int a[], int n)
{
    int i,j;
    
    for(i=1; i<n; i++)
    {
        printf("pass[%d]----------------------\n", i);
        show_array(a,n);
        show_cursor(n,i);
        int tmp = a[i];
        for(j=i; j>0 && a[j-1]>tmp; j--)
        {
        	memmove(a+j, a+j-1, sizeof(int));	
        	show_array(a,n);
        }
        a[j] = tmp;
        show_array(a,n);
    }
}

int main()
{
    int array[20] = {20,7, 10, 5,14, 2,12, 17,3,16, 9,19, 11, 8,15, 6,18, 4,13, 1};
    printf("array[20]:");
    show_array(array, 20);
    straight_insertion_sort(array, 20);

    return 0 ;
}
