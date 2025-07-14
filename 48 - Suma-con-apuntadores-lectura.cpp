//48 Suma_con_apuntadores_lectura
#include <stdio.h>

int main()
{   int *pt1,x;
    int *pt2,y;
    int *pt3,z;

    pt1 = &x;//a es igual a la direcciion de x
    pt2 = &y;
    pt3 = &z;

    printf("\nDar un entero: ");
    scanf("%d",&(*pt1));
    printf("\nDar otro entero: ");
    scanf("%d",&(*pt2));
    *pt3 = *pt1 + *pt2;

    printf("\n\n pt1 -->|%d|",*pt1);
    printf("\n\n pt2 -->|%d|",*pt2);
    printf("\n\n pt3 -->|%d|",*pt3);


return 0;

}
