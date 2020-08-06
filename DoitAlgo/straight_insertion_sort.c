#include <stdio.h>

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
    for(i=1; i<n; i++)      //pass
    {
        printf("pass[%d]----------------------\n", i);
        int tmp = a[i];
        show_array(a, n);
        show_cursor(n,i);
        for(j=i; j>0 && a[j-1]>tmp; j--)
        {
            a[j] = a[j-1];
            show_array(a,n);
        }
        a[j] = tmp;   
    }
}

int main()
{
    int array[10] = {4,3,8,6,1,5,9,7,2,10};
    printf("array[10]:");
    show_array(array, 10);
    straight_insertion_sort(array, 10);
    printf("sorted:");
    show_array(array, 10);
    return 0;
}