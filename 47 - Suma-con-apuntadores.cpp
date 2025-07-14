//47 Suma_con_apuntadores
#include <stdio.h>

int main()
{   int *pt1,x;
    int *pt2,y;
    int *pt3,z;

    pt1 = &x;//a es igual a la direcciion de x
    pt2 = &y;
    pt3 = &z;

    *pt1 = 200;//contenido de a igual a 80
    *pt2 = 300;
    *pt3 = *pt1 + *pt2;

    printf("\n\n pt1 -->|%d|",*pt1);//
    printf("\n\n pt2 -->|%d|",*pt2);//
    printf("\n\n pt3 -->|%d|",*pt3);//


return 0;

}
