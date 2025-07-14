// 59 - Punteros 4
#include <stdio.h>

typedef struct numeros{
	float n1;
	int n2;
}num;

int main(){
	num *s;
	s = new num;
	s->n1 = 9.8;
	s->n2 = 6;
	printf("\ns->|%.2f|%d|",s->n1,s->n2);
	
	delete(s);
    return 15;
}
