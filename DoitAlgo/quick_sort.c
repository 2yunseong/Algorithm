#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) \
    do                   \
    {                    \
        int t = x;       \
        x = y;           \
        y = t;           \
    } while (0)

void quick(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int pivot = a[(pl + pr) / 2];

    do
    {
        while (a[pl] < pivot)
            pl++;
        while (a[pr] > pivot)
            pr--;
        if(pl<=pr)
        {
        swap(int, a[pl], a[pr]);
        pl++;
        pr--;
    	}
    } while (pl <= pr);
    //seperate group
    if (left < pr)
        quick(a, left, pr);
    if (right > pl)
        quick(a, pl, right);
}

void show_quicksort(int a[], int left, int right)
{
    int pl = left;
    int pr = right;
    int pivot = a[(pl + pr) / 2];

    int i;
    printf("a[%d]~a[%d] :{",left, right);
    for(i = left; i<right; i++)
        printf("%d ", a[i]);
    printf("%d}\n", a[right]);

    do{
        while(a[pl]<pivot)pl++;
        while(a[pr]>pivot)pr--;
        if(pl<= pr)
        {
        swap(int, a[pl], a[pr]);
        pl++;
        pr--;
    	}
    }while(pl<=pr);
    
    if(left<pr) show_quicksort(a, left, pr);
    if(right>pl) show_quicksort(a,pl,right);
}

void show_array(const int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

    int main()
    {
        int *m_array = malloc(sizeof(int) * 10);
        int i;
        for(i=0; i<10; i++)
            scanf("%d", &m_array[i]);
        show_array(m_array,10);
        show_quicksort(m_array, 0,9);
        show_array(m_array,10);
        free(m_array);
        return 0;
    }
