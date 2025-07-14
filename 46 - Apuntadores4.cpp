//46.- Apuntadores 4

#include <stdio.h>

int main()
{
    int varx;
    int *a;
    a = &varx;
    *a = 80;
    
    float vary;
    float *b;
    b = &vary;
    *b = 9.9;
    
    char varz;
    char *c;
    c = &varz;
    *c = 'W';
    
    printf("\na -> |%d|", *a);
    printf("\na -> %d", a);
    printf("\n*a -> %d", *a);
    printf("\n&a -> %d", &a);
    printf("\n\n__________\n");
    
    printf("\nb -> |%.2f|", *b);
    printf("\nb -> %d", b);
    printf("\n*b -> %.2f", *b);
    printf("\n&b -> %d", &b);
    printf("\n\n__________\n");
    
    printf("\nc -> |%c|", *c);
    printf("\nc -> %d", c);
    printf("\n*c -> %c", *c);
    printf("\n&c -> %d", &c);

    return 0;
}
