//35-struct carro funcion devuelve estructura
#include<stdio.h>

typedef struct carro{
	char placa[7];
	int modelo;
	char marca[50];
	int puertas;
} car;

car leer_registros();
void imprime_registro(car *);

int main()
{
	char resp;
	car carrito;
	do{
		carrito = leer_registros();
		imprime_registro(&carrito);
		printf("\nDesea continuar [S/N]: ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp=='s' || resp=='S');
	return 6;
}

car leer_registros(){
	car c;
	printf("\nPlaca: ");
	scanf("%s", &c.placa );
	printf("\nModelo: ");
	scanf("%d", &c.modelo);
	printf("\n Marca: ");
	fflush(stdin);
	gets(c.marca);
	printf("\nNumero de puertas: ");
	scanf("%d", &c.puertas);
	return c;
}

void imprime_registro(car *c){
	printf("\nPlaca: %s ", c->placa);
	printf("\nModelo: %d ", c->modelo);
	printf("\nMarca: %s ", c->marca);
	printf("\nNumero de puertas: %d ", c->puertas);
}
