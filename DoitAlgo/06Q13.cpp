#include <iostream>
#include <stack>
#define swap(type,x,y) do{ type t = x; x = y ; y = t; }while(0)

using namespace std;

void quick(int a[], int left, int right)
{
    stack<int> lstack_idx;
    stack<int> rstack_idx;
    int left_ = left;
    int right_ = right;
    lstack_idx.push(left);
    rstack_idx.push(right);

     while(false==lstack_idx.empty())
    {
        left_ = lstack_idx.top();
        right_ = rstack_idx.top();
        int pl = lstack_idx.top();
        int pr = rstack_idx.top();
        int pivot = a[(pl+pr)/2];
        lstack_idx.pop();
        rstack_idx.pop();
      
        do
        {
            while(a[pl]<pivot)pl++;
            while(a[pr]>pivot)pr--;
            //pl<=pr 일때만 교환이 성립한다.
            if(pl<=pr)
            {
                swap(int,a[pl],a[pr]);
                pl++;
                pr--;
            }
        } while (pl<=pr);
      
        if (left_ < pr)
        {
            lstack_idx.push(left_);
            rstack_idx.push(pr);
        }
        if(right_>pl)
        {
            lstack_idx.push(pl);
            rstack_idx.push(right_);
        }
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
    int array[8]={4,7,5,64,12,2,3,1};

    show_array(array,8);
    quick(array,0,7);
    show_array(array,8);

    return 0;
}
