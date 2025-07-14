// 58- Punteros 3
#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
	char let;
	int num;
}nodi;

int main(){
	
	nodi *r;
	r = (nodi *)malloc(sizeof(nodi));
	r->let= 'A';
	r->num= 80;
	
	printf("\n r->|%c||%d|", r->let,r->num);
	free(r);
	
	return 10;
	
}
