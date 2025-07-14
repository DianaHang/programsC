//49 intercamnbio de valores con punteros
#include <stdio.h>
#include <conio.h>
int main()
{   //primera escena
    float *ptr1,var1;
    float *ptr2,var2;
    float *ptr3,var3;

    ptr1 = &var1;
    ptr2 = &var2;
    ptr3 = &var3;

    printf("\ingresa un numero decimal: ");
    scanf("%f",&(*ptr1));
    printf("\da otro un numero decimal: ");
    scanf("%f",&(*ptr2));

    printf("\n\n Primer escena: \n\n");
    printf("\n ptr1 -->|%.2f|",*ptr1);
    printf("\n ptr2 -->|%.2f|",*ptr2);
    getch();

    //Segunda escena
    *ptr3 = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = *ptr3;

    printf("\n\n Segunda escena: \n\n");
    printf("\nIntercambio de contenidos a traves de punteros: \n");
    printf("\n ptr1 -->|%.2f|",*ptr1);
    printf("\n ptr2 -->|%.2f|",*ptr2);


return 0;

}
