/*
    문제: n이 제곱수이면 1을 반환하고, 제곱수가 아니면 0을 반환하는 함수 func2(int n)
    을 작성하라. n은 10억 이하의 자연수이다.
*/
#include <stdio.h>

/*
    풀이 : n의 최대가 10억이므로(10^9), 루트를 씌우면 10^4Xsprt10
    따라서 제곱근의 크기는 대략 40000 정도 일 것이다.
    일단 1부터 n까지 모두 나눠서 비교해보는 방향으로 진행
    1. 숫자 a 로 n을 나눈다. q = n/a
    2. 이 때, n 을 a로 나눈 나머지가 0이여야 다음 조건으로 넘어가야한다.
    3. a와 q 가 같다면, 1을 반환하고 종료.
    시간복잡도 : O(n)
*/

int func2(int n){
    int q ; 
    for(int i=1; i<n+1; i++){
        q = n/i;
        if(n%i != 0) continue;
        if(q==i) return 1;
    }
    return 0;
}

/* 해답 시간복잡도:O(sprtN)*/
int func3(int n){
    for(int i =1; i*i < n+1; i++){
        if(i*i == n) return 1;
    }
    return 0;
}

int main(){
    // printf("%d\n", func2(9));
    // printf("%d\n", func2(693953651));
    // printf("%d\n", func2(756580036));

     printf("%d\n", func3(9));
     printf("%d\n", func3(693953651));
     printf("%d\n", func3(756580036));
    
    return 0;
}
