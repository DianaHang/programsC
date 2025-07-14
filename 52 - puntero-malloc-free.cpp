//52 - puntero-malloc-free
#include<stdio.h>
#include<stdlib.h>

int main(){
	//Creación del puntero
	int *pt;
	
	//. Se crea liga y espacio de memoria:
	// Tipo de dato con malloc
	pt = (int *)malloc(sizeof(int));
	
	*pt = 800;
	
	printf("\n pt -> |%d|", *pt);
	
	//Liberar la memoria dinámica
	free(pt);
	
	return 0;
}
