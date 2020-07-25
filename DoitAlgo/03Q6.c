#include <stdio.h>
#include <stdlib.h>

int int_cmp(const long *a, const long *b)
{
    if(*a < *b)
        return 1;
    else if(*a > *b)
        return -1;
    else
        return 0;
}

int main()
{
    int nx = 10;
    int key =2045;
    long *p;
    long array[10] = {
        1000000000,
        930684511,
        34304567,
        9999999,
        235086,
        23596,
        2045,
        100,
        10,
        1};
    p = bsearch(
        &key, 
        array, 
        nx, 
        sizeof(long),
        (int(*)(const void*, const void*))int_cmp);
    
    printf("%d in array[%d]\n",*p, (int)(p-array));
    
    return 0;
}
