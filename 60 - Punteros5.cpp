// 60- Punteros 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct registro {
	int num;
	char cad[6];
	float dec;
}regis;

int main(){
	regis *a1, *a2;
    a1=(regis *)malloc(sizeof(regis));
    a1->num=10;
    strcpy(a1->cad, "Julio");
    a1->dec = 9.5;
	
	a2=(regis *)malloc(sizeof(regis));
    a2->num=20;
    strcpy(a2->cad, "Rosa");
    a2->dec = 10.0;
    
    printf("\na1->|%d|%s|%.2f|", a1->num, a1->cad, a1->dec);
    printf("\na2->|%d|%s|%.2f|", a2->num, a2->cad, a2->dec);
    free(a1);
    free(a2);
    
	return 16;
}
