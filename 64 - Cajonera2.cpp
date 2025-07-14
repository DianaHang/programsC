//64. Cajonera-puntero-estructura2

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

//Definicion de tipos de datos

typedef struct nodo1{
	int n1;
	char nom[7];
	struct nodo1 *pt;
}nod1;

typedef struct nodo2 {
	int n2;
	float prom;
	char let;
	struct nodo2 *pt2;
}nod2;

typedef struct nodo3{
	nod1 *a;
	nod2 *e;
}nod3;

int main(){
	//Crear  puntero principal
	nod3 *u;
	
	//Tomar memoria dinamica
	u = (nod3 *)malloc(sizeof(nod3));
	
	//Puntero u apunta a a que crea un nodo
	u->a = (nod1 *)malloc(sizeof(nod1));
	
	//Valores del nodo a
	u->a->n1 = 10;
	strcpy(u->a->nom, "Juan");
	
	//Crear otro nodo
	u->a->pt = (nod1 *)malloc(sizeof(nod1));
	
	//Llenar nuevo nodo
	u->a->pt->n1 = 9;
	strcpy(u->a->pt->nom, "Carlos");
	u->a->pt->pt = NULL;
	
	//Puntero u apunta a e que crea un nodo
	u->e = (nod2 *)malloc(sizeof(nod2));
	
	//Valores del nodo e
	u->e->n2 = 8;
	u->e->prom = 10.5;
	u->e->let = 'P';
	
	//Crear otro nodo
	u->e->pt2 = (nod2 *)malloc(sizeof(nod2));
	
	//Llenar nuevo nodo
	u->e->pt2->n2 = 9;
	u->e->pt2->prom = 7.6;
	u->e->pt2->let = 'Q';
	u->e->pt2->pt2 = NULL;
	
	//Impresion de valores
	printf("\n u-> a -> |%d|%s| -> |%d|%s| -> NULL", u->a->n1, u->a->nom, u->a->pt->n1, u->a->pt->nom);
	printf("\n u-> e -> |%d|%.2f|%c| -> |%d|%.2f|%c|-> NULL", u->e->n2, u->e->prom, u->e->let, u->e->pt2->n2, u->e->pt2->prom, u->e->pt2->let);
	
	//Liberar memoria
	free(u->a->pt);
	free(u->e->pt2);
	free(u->a);
	free(u->e);
	free(u);
	
	return 5;
}
