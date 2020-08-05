#include <stdio.h>
#define swap(type, x, y) do{ type t = x ; x = y ; y = t ;}while(0)

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

void show_change(int size, int left_idx)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(left_idx==i)
        {
            printf("<-  -> \n");
            break;
        }
        else
        {
            printf("   ");
        }
    }
}

void improve_bubble_sort_2(int a[], int n)
{
    int k = 0;
    int j;
    int pass = 1;
    int i;
    while(k<n-1)
    {
        printf("[pass %d]", pass);
        for(i=0; i<n; i++)
            printf("---");
        printf("\n");
        int last = n-1;         //배열의 뒤부터 정렬을 시작하면, 항상 최근 위치는 n-1이 된다
        for(j= n-1; j>k; j--)   
        {
            show_array(a,n);

            if(a[j]<a[j-1])
            {
                show_change(n,j-1);
                swap(int, a[j], a[j-1]);
                last = j;       //교환을 한 가장 최근의 위치를 나타냄
            }
            else
            {
                show_cursor(n,j);
            }
            
        }
        pass++;
        k = last;              //교환을 한번도 안했으면, last = n-1이므로 종료됨.
    }
}

int main()
{
    
    int array[20] = {11,18,20,12,15,7, 10, 5,16, 2,19, 3, 9,14, 1, 8,17,13, 6, 4};
    
   
    printf("array[20]:");
    show_array(array,20);
    improve_bubble_sort_2(array,20);

    return 0;    
}