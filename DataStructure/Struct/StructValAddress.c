#include <stdio.h>
#include <stdlib.h>

/* 
    구조체 변수의 주소 값은 
    구조체 변수의 첫 번째 멤버의 주소 값과 같다.
*/

typedef struct 
{
    int xpos;
    int ypos;
}point;

typedef struct
{
    char name[20];
    char phoneNum[20];
    int age;
}person;

int main(){
    point pos = {10,20};
    person man = {"이윤성", "010-0000-0000", 23};
    
    
    printf("%p %p\n", &pos, &pos.xpos);
    printf("%p %p\n", &man, man.name);
    system("pause");
    return 0;
}