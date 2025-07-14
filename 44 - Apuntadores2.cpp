//44.- Apuntadores2
#include <stdio.h>

int main()
{
    float pi=3.14159;
    float *r;
    r = &pi;
    printf("\nr -> |%.2f| ", *r); 
    printf("\nr -> %d", r); //dir
    printf("\n*r -> %.2f", *r); 
    printf("\n&r -> %d", &r); //dir

    return 0;
}
