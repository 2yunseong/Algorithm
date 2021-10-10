#include <stdio.h>
#include <stdlib.h>
#define NUMBER 8

int sorted[8];

void merge(int a[], int m, int mid, int n){
    int i = m;
    int j = mid+1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while(i<= mid && j<=n){
        if(a[i] <= a[j]){
            sorted[k] = a[i++];    
        }
        else {
            sorted[k] = a[j++];
        }
        k++;
    }

    // 남은 데이터 삽입
    if(i > mid){
        int t;
        for(t = i; i<= mid; i++){
            sorted[k] = a[t];
            k++;
        }
        for(t = j; j<= n; j++){
            sorted[k] = a[t];
            k++;
        }
    }

    // 정렬된 배열을 삽입
    int idx;
    for(idx = m; idx <=n; idx++){
        a[idx] = sorted[idx];
    }
}

void mergeSort(int a[], int m, int n){
    if(m<n){
        int mid = (m+n)/2;
        mergeSort(a, m, mid);
        mergeSort(a, mid+1, n);
        merge(a, m, mid, n);
    }
}
int main(){
    int arr[8] = {7,6,5,8,3,5,9,1};
    int i;
    mergeSort(arr, 0, NUMBER-1);
    for(i=0; i<NUMBER; i++){
        printf("%d ", arr[i]);
    }

    system("pause");
    return 0;
}