// 26 - struct-producto
#include <stdio.h>

struct producto {
	int idProducto;
	char nombre[60];
	float precio;
	int existencias;
};

int main() {
	struct producto p;
	printf("\nIdentificador: ");
	scanf("%d",&p.idProducto);
	printf("\nNombre: ");
	fflush(stdin);
	gets(p.nombre);
	printf("\nPrecio: $");
	scanf("%f",&p.precio);
	printf("\nExistencias: ");
	scanf("%d",&p.existencias);
	
	printf("\nID: %d",p.idProducto);
	printf("\nNombre: %s",p.nombre);
	printf("\nPrecio: $%.2f",p.precio);
	printf("\nExistencias: %d",p.existencias);
	
	return 0;
}
