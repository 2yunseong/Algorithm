#include <stdio.h>

//
int* seqsearch(
    const int* key, 
    const int *base,
    size_t nmemb,
    size_t size,
    int(*compar)(const int*, const int*))
{
	int i;
	for(i=0; i<nmemb; i++)
    {
    	int *temp;
    	*temp = base[i];
        if(compar(*key, *temp)==0)
            return *temp;
    }
    return NULL;
}

int int_cmp(const int *a, const int *b)
{
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}

int main()
{
    int array[5]={1,2,3,4,5};
    int n = 5;
    int key = 3;
    int *p;
    p = seqsearch(
        &key,
        array,
        n,
        sizeof(int),
        (int(*)(const int*, const int*))int_cmp);
    if(p==NULL)
        printf("search fail!\n");
    else
        printf("%d is in x[%d]\n", key, (int)(p-array));
    
    return 0;
}
