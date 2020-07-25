#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b)
{
    if (*a > *b)
        return 1;
    else if (*a < *b)
        return -1;
    else
        return 0;
}

void show_array(const int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int num, money, i, j, k;
    int count = 0;
    int flag;
    scanf("%d %d", &num, &money);
    int *x = calloc(num, sizeof(int));
    for (i = 0; i < num; i++)
        scanf("%d", &x[i]);

    qsort(x, num, sizeof(int), (int (*)(const void *, const void *))int_cmp);

    do
    {
        flag = -1;
        for (i = 0; i < num; i++)
        {
            if (money < x[i])
            {
                if(flag!=-1)
                {
                    if(i==0)
                        flag = 0;
                    else
                        flag = i-1;
                }
            }
        }
        money -= x[flag];
        count++;

    } while (money <= 0);

    printf("%d", count);
    free(x);
    return 0;
}
