/*
    문제 : 주어진 길이 n의 int 배열 arr에서 합이 100인 서로 다른 위치의
    두 원소가 존재하면 1을, 존재하지 않으면 0을 반환하는 함수 func2(int arr[], int N)
    을 작성하라. arr의 각 수는 0 이상 100 이하고, n은 1000 이하이다.
*/
#include <stdio.h>

/*
    풀이:
    1. 노가다 -> 시간복잡도: O(n^2)
    2. 배열을 생성해 1~100 까지 들어온 값을 저장.
        - b 가 들어왔으면, checkArr[b] 에 값이 있는지 확인. 있다면, 1반환
        - 들어온 임의의 값이 a 라면, 100-a 에 1 저장.
        시간복잡도 : O(n)
        
*/
int func2(int arr[], int n){

    int checkArr[101] = {0,};       // 배열을 0으로 초기화.
    for(int i=0; i<n; i++){
        if(checkArr[arr[i]] == 1){
            return 1;
        }
        checkArr[100-arr[i]] = 1;
    }
    return 0;
}
int main(){
    int arr1[3] = {1,52,48};
    int arr2[2] = {50, 42};
    int arr3[4] = {4,13,63,87};
    printf("%d", func2(arr1, 3));
    printf("%d", func2(arr2, 2));
    printf("%d", func2(arr3, 4));
    return 0;
}