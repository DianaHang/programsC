//45 apuntadores 3
#include <stdio.h>

int main()
{   char varx;
    char*w;
    w = &varx;//se crea la liga
    *w= 'M';

    printf("\n\n w -->|%c|",*w);//

    printf("\n\n w = %d",w);// direccion de varx
    printf("\n\n w = %c",*w);//puntero da el valor guardado en varx
    printf("\n\n w = %d",&w);//direccion delpuntero
    return 0;
}
