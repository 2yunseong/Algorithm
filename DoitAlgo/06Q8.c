#include <stdio.h>

void show_array(const int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%2d ", a[i]);
    printf("\n");
}

int show_cursor_s_insert_sort(int n, int idx_target, int idx_temp)
{
    int k;
    if (idx_target == idx_temp)
    {
        for (k = 0; k < n; k++)
        {
            if (idx_target == k)
            {
                printf(" + ");
                break;
            }
            else
                printf("   ");
        }
    }
    else
    {
        for (k = 0; k < n; k++)
        {
            if (idx_target == k)
                printf("^--");
            else if (idx_target < k && idx_temp > k)
                printf("---");
            else if (idx_temp == k)
                printf("-+ ");
            else
                printf("   ");
        }
    }
    printf("\n");
}

void straight_insertion_sort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++) //pass
    {
        printf("pass[%d]----------------------\n", i);
        int tmp = a[i];
        show_array(a, n);
        for (j = i; j > 0 && a[j - 1] > tmp; j--)
        {
            a[j] = a[j - 1];
        }
        show_cursor_s_insert_sort(n, j, i);
        a[j] = tmp;
    }
}

int main()
{
    int array[10] = {4, 3, 8, 6, 1, 5, 9, 7, 2, 10};
    printf("array[10]:");
    show_array(array, 10);
    straight_insertion_sort(array, 10);
    printf("sorted:");
    show_array(array, 10);
    return 0;
}