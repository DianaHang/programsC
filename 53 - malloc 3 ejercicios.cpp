// 53 - 3 malloc 

#include<stdio.h>
#include<stdlib.h>

int main(){
	//Declarar variables
	int pt;
	float pr;
	char ps;
	
	//Memoria del montículo con malloc
	pt = (int *)malloc(sizeof(int));
	pr = (float *)malloc(sizeof(float));
	ps = (char *)malloc(sizeof(char));
	
	//Tomar los valores de las variables
	*pt = 500;
	*pr = 3.1416;
	*ps = 'A';
	
	//Imprimir valores
	printf("\n pt -> |%d|", *pt);
	printf("\n pr -> |%.2f|", *pr);
	printf("\n ps -> |%c|", *ps);
	
	//Liberar la memoria
	free(pt);
	free(pr);
	free(ps);
	
	return 10;
}
