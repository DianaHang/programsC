//63. Cajonera-punteros-struct

#include<stdio.h>
#include<stdlib.h>

typedef struct cajonera{
	int *st1;
	int st2;
}stca;

int main(){
	
	//Crear puntero
	stca *st;
	
	//Memoria dinamica
	st = (stca *)malloc(sizeof(stca));
	
	//crear liga 
	st -> st1 = (int *)malloc(sizeof(int));
	st -> st2 = (char *)malloc(sizeof(char));
	
	//Valores (*)
	*st -> st1 = 100;
	*st -> st2 = 'W';
	
	//Impresion de valores
	printf("\n st -> |%d|", st->st1);
	printf("\n st -> |%c|", st->st2);
	
	//Liberar memoria
	free(st->st1);
	free(st->st2);
	free(st);
	
	return 5;
}
