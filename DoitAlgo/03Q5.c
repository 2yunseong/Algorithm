#include <stdio.h>

//배열에서 맨 앞의 요소를 찾는 이진검색

int bin_search2(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n-1;
    int pc =(n-1)/2;
    do{
        pc = (pl+pr) / 2;
        if(a[pc]==key)
        {
            while(1)
            {
                if(a[pc-1]!=key)
                    return pc;
                else
                    pc--;
            }
        }
        if(a[pc]>key)
            pr = pc-1;
        if(a[pc]<key)
            pl = pc+1;
    }while(pl<=pr);
    return -1;
}
int main()
{
    int array[11]={1,3,5,7,7,7,7,8,8,9,9};
    int test1[10]={1,1,1,1,1,1,1,1,1,1};
    
    printf("key : %d array idx:%d \n",8, bin_search2(array,11,key));
    printf("key : %d test  idx:%d \n",1, bin_search2(test1,10,1));

    return 0 ;
}
