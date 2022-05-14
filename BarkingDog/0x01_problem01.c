#include <stdio.h>
/*
    문제 : n이하의 자연수 중에서 3의 배수이거나 5의 배수인 수를
    모두 합한 값을 반환하는 함수 func1(int n)을 작성하라.
    n은 10만 이하의 자연수이다.
*/

/*
    1. 3의 배수를 더한다.
    2. 5의 배수를 더하는데, 15의 배수면 거른다.(이미 3의 배수에서 더해졌으므로)
*/
int func1(int n){
    int sum = 0; // 답으로 return 될 값.
    for(int i=1; i<n+1; i++){
        // 3의 배수
        if(i % 3 == 0){
            sum+=i;
        }
    }
    for(int i=1; i<n+1; i++){
        // 15의 배수는 중복이므로 건너 뜀.
        if(i%15 == 0) continue;
        else if(i%5==0) sum+=i;
    }
    return sum;
}

/* 
    3의 배수 또는 5의 배수면 더한다.
    위 코드보다 더 효율적임.
*/
int answer(int n){
    int sum = 0;
    for(int i=1; i<n+1; i++){
        if(i%3 == 0 || i%5==0) sum += i;
    }
    return sum;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", func1(n));
    return 0;
}