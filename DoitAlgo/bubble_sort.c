#include <stdio.h>
#define swap(type, x, y) do{ type t = x ; x = y ; y = t ;}while(0)

void basic_bubble_sort(int a[], int n)  //기본적인 버블 정렬
{
    int i;
    int j;
    for(i=0; i<n-1; i++)    //PASS
    {
        for(j=n-1; j>i; j--)
        	if(a[j]<a[j-1])
            	swap(int, a[j], a[j-1]);
    }
}

void improve_bubble_sort(int a[], int n)
{
    int i;
    int j;
    for(i=0; i<n-1; i++)
    {
        int exchange = 0;
        for(j=n-1; j>i; j--)
        {
        	if(a[j]<a[j-1])
            {
                swap(int, a[j], a[j-1]);
                exchange++;
            }
        }
        if(exchange==0)     // 교환 횟수가 0이면, 
            break;          // 정렬이 완료되었다고 볼 수 있다.
    }
}

void improve_bubble_sort_2(int a[], int n)
{
    int k = 0;
    int j;
    while(k<n-1)
    {
        int last = n-1;         //배열의 뒤부터 정렬을 시작하면, 항상 최근 위치는 n-1이 된다
        for(j= n-1; j>k; j--)   
        {
            if(a[j]<a[j-1])
            {
                swap(int, a[j], a[j-1]);
                last = j;       //교환을 한 가장 최근의 위치를 나타냄
            }
        }
        k = last;              //교환을 한번도 안했으면, last = n-1이므로 종료됨.
    }
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
    int array1[10] = {7, 10, 5, 2, 3, 9, 1, 8, 6, 4};
    int array2[15] = {11,12,15,7, 10, 5, 2, 3, 9,14, 1, 8,13, 6, 4};
    int array3[20] = {11,18,20,12,15,7, 10, 5,16, 2,19, 3, 9,14, 1, 8,17,13, 6, 4};
    
    printf("array1[10]:");
    show_array(array1, 10);
    basic_bubble_sort(array1, 10);
    printf("basic bubble sort:");
    show_array(array1, 10);
    printf("array2[15]:");
    show_array(array2,15);
    printf("improve bubble sort:");
    improve_bubble_sort(array2, 15);
    show_array(array2,15);
    printf("array3[20]:");
    show_array(array3,20);
    improve_bubble_sort_2(array3,20);
    printf("improve bubble sort2:");
    show_array(array3,20);

	

    return 0;    
}
