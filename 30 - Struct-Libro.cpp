// 30 struct-libro
#include <stdio.h>
typedef struct libro{
	int idLibro;
	char tituloLibro[110];
	float precio;
	int existencias;
	char ISBN[15];
	
}stl;

void leeLibro(stl &);
void imprimeLibro(stl &);

int main (){
	stl a;
	leeLibro(a);
	imprimeLibro(a);
	
	
	return 0;		
}

void leeLibro(stl &r){
	printf("\nIdentificador: ");
	scanf("%d", &r.idLibro);
	printf("\nTitulo del Libro: ");
	fflush(stdin);
	gets(r.tituloLibro);
	printf("\nPrecio:$ ");
	scanf("%f", &r.precio);
	printf("\nExistencias: ");
	scanf("%d", &r.existencias);
	printf("\nISBN: ");
	scanf("%s", &r.ISBN);
}

void imprimeLibro(stl &r){
	printf("\nIdentificador: %d", r.idLibro);
	printf("\nTitulo: %s", r.tituloLibro);
	printf("\nPrecio:$ %.2f", r.precio);
	printf("\nExistencias: %d", r.existencias);
	printf("\nISBN: %s", r.ISBN);
	
}
