//31-struct-ropa
#include <stdio.h>
#include <stdlib.h>

struct ropa{
    int idPrenda;
    char nombrePrenda[60];
    int talla;
    float precio;
    int existencias;
};

int main (){
    struct ropa i;
    printf("\nIdentificador: ");
    scanf("%d",&i.idPrenda);
    printf("\nNombre de la prenda: ");
    scanf("%s",&i.nombrePrenda);
    printf("\nTalla: ");
    scanf("%s",&i.talla);
    printf("\nPrecio:$");
    scanf("%f",&i.precio);
    printf("\nTotal en Existencias: ");
    scanf("%d",&i.existencias);
    
    printf("\nIdentificador:%d ",i.idPrenda);
    printf("\nNombre de la Prenda: %s", i.nombrePrenda);
    printf("\nPrecio: $ %.2f", i.precio);
    printf("\nExistencias %d\n", i.existencias);

	return 0;
}
