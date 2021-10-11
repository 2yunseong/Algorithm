#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int xpos;
    int ypos;
}point;

typedef struct 
{
    double radius;
    point * center;
}circle;

int main()
{
    point pos1 = {1,2};
    point pos2 = {3,4};
    point *pptr = &pos1;
    circle *cir = malloc(sizeof(circle));
    
    (*pptr).xpos += 4;
    (*pptr).ypos += 4;
    printf("%d %d\n", pptr->xpos, pptr->ypos);

    cir->radius = 10.0;
    cir->center = &pos2;

    printf("center: %d %d\n", cir->center->xpos, cir->center->ypos);
    system("pause");
    return 0;
}

