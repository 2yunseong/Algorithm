#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}Point;

double get_distance(Point t1, Point t2){
    double dx = (double)t1.x - t2.x;
    double dy = (double)t1.y - t2.y;
    double distance = sqrt(dx*dx + dy*dy);
    return distance;
}

int main(){
    Point p1 = {1,2};
    Point p2 = {9,8};
    double ans = get_distance(p1, p2);
    printf("distance:%f", ans);
    system("pause");
    return 0;
}