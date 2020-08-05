#include <stdio.h>
#define swap(type, x, y) do{ type t = x ; x = y ; y = t ;}while(0)


void show_cursor(int size, int first_idx, int last_idx)
{
    int i=0;
    if(first_idx==last_idx)
    {
        for(i=0; i<size; i++)
        {
            if(i==first_idx)
            {
                printf(" * ");
                break;
            }
            else
            {
                printf("   ");
            }
        }
    }
    else
        for(i=0; i<size; i++)
        {

            if(i==first_idx)
                printf(" * ");
            else if(i==last_idx)
                printf(" * ");
            else
                printf("   ");
        }
    printf("\n");
}

void show_array(const int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%2d ", a[i]);
    printf("\n");
}


void straight_selection_sort(int a[], int n)
{
    int min ;
    int i;
    int j;
    for(i=0; i<n-1; i++)  //pass!
    {
        min = i;
        printf("pass[%d]--------------------------------------\n", i+1);
        for(j=i+1; j<n; j++)
        {
            if(a[min]>a[j])
                min = j;
        }
        show_array(a,n);
        show_cursor(n,i,min);
        swap(int, a[i], a[min]);
    }
}

int main()
{
    int array[20] = {20,7, 10, 5,14, 2,12, 17,3,16, 9,19, 11, 8,15, 6,18, 4,13, 1};
    printf("array[20]:");
    show_array(array, 20);
    straight_selection_sort(array, 20);

    return 0;
}
