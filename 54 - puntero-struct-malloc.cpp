// 54 -puntero-struct-malloc

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Definir estructura
typedef struct libros{
	int id_book;
	char title[120];
	int num_Pag;
	int exist;
	float price;
} lib; //Typedef


int main(){
	//Apuntadores
	lib *r;
	r = (lib *)malloc(sizeof(lib));
	
	r -> id_book = 10; // _< Para acceder a valor con puntero	r -> title = "El Principito
	strcpy(r -> title, "El Principito"); //Para que la máquina pueda acceder al valor en ese esp. de memoria"
	r -> num_Pag = 120;
	r -> exist = 200;
	r -> price = 250.70;
	
	//Imprimir datos de librería
	printf("\n r -> |%d|%s|%d|%d|%.2f", r -> id_book, r->title, r->num_Pag, r-> exist, r->price );
	
	//Liberar memoria
	free(r);
	
	return 10;
}
