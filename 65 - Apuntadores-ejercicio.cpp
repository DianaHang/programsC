#include<stdio.h>
#include<stdlib.h>

//Definicion de tipos de datos
typedef struct cajonera1{
	int entero;
	struct cajonera1 *nd1;
}caja1;

typedef struct cajonera2{
	char letra;
	struct cajonera2 *nd21;
	struct cajonera2 *nd22;
}caja2;

typedef struct cajonera3{
	float flotante;
	struct cajonera3 *nd31;
	struct cajonera3 *nd32;
}caja3;

typedef struct cajoneraVacia{
	caja1 *a;
	caja2 *b;
	caja3 *c;
}cajaVacia;

int main(){
	
	//Crear puntero principal
	cajaVacia *ptr;
	
	//Tomar memoria dinamica
	ptr = (cajaVacia *)malloc(sizeof(cajaVacia));
	
	//Crear nodo de ptr a caja1
	ptr->a = (caja1 *)malloc(sizeof(caja1));
	
	//Valores de caja 1
	ptr->a->entero = 10;
	//Crear siguiente nodo
	ptr->a->nd1 = (caja1 *)malloc(sizeof(caja1));
	
	//Llenar nueva caja
	ptr->a->nd1->entero = 20;
	ptr->a->nd1->nd1 = NULL;
	
	//Crear nodo de ptr a caja2
	ptr->b = (caja2 *)malloc(sizeof(caja2));
	
	//Valor primer caja2
	ptr->b->letra = 'P';
	
	//Crear nodo a segunda caja 2
	ptr->b->nd21 = (caja2 *)malloc(sizeof(caja2));
	
	//Valor primer caja2
	ptr->b->nd21->letra = 'Q';
	
	//Crear nodo a tercer caja2
	ptr->b->nd22 = (caja2 *)malloc(sizeof(caja2));
	
	//Valor tercer caja2
	ptr->b->nd22->letra = 'R';
	ptr->b->nd22->nd22 = NULL;
	
	//Crear nodo de ptr a caja3
	ptr->c = (caja3 *)malloc(sizeof(caja3));
	
	//Valor primer caja3
	ptr->c->flotante = 9.5;
	
	//Crear nodo a segunda caja3
	ptr->c->nd31 = (caja3 *)malloc(sizeof(caja3));
	
	//Valor segunda caja3
	ptr->c->nd31->flotante = 90.5;
	
	//Crear nodo a tercer caja3
	ptr->c->nd32 = (caja3 *)malloc(sizeof(caja3));
	
	//Valor segunda caja3
	ptr->c->nd32->flotante = 900.5;
	ptr->c->nd32->nd32 = NULL;
	
	//Impresion de valores
	printf("\n ptr-> a -> |%d| -> |%d| -> NULL", ptr->a->entero, ptr->a->nd1->entero);
	printf("\n ptr-> b -> |%c| ->|%c|-> |%c|-> NULL", ptr->b->letra, ptr->b->nd21->letra, ptr->b->nd22->letra);
	printf("\n ptr-> c -> |%.2f|-> |%.2f|-> |%.2f| -> NULL", ptr->c->flotante, ptr->c->nd31->flotante, ptr->c->nd32->flotante);
	
	//Liberar memoria
	free(ptr->a->nd1);
	free(ptr->b->nd21);
	free(ptr->b->nd22);
	free(ptr->c->nd31);
	free(ptr->c->nd32);
	free(ptr->a);
	free(ptr->b);
	free(ptr->c);
	free(ptr);
	
	return 5;
}
