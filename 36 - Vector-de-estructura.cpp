//36-vector de estructura car
#include<stdio.h>
#define tam 3
typedef struct carro{
	char placa[7];
	int modelo;
	char marca[50];
	int puertas;
} car;

void leer_registros(car [tam]);
void imprime_registro(car [tam]);

int main()
{
	char resp;
	car carros[tam];
	do{
	    leer_registros(carros);
		imprime_registro(carros);
		printf("\nDesea continuar [S/N]: ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp=='s' || resp=='S');
	return 6;
}

void leer_registros(car vect[tam]){
	for(int i=0; i<tam; i++){
		printf("\nPlaca: ");
		scanf("%s", &vect[i].placa );
		printf("\nModelo: ");
		scanf("%d", &vect[i].modelo);
		printf("\n Marca: ");
		fflush(stdin);
		gets(vect[i].marca);
		printf("\nNumero de puertas: ");
		scanf("%d", &vect[i].puertas);
	}
}

void imprime_registro(car vect[tam]){
	for (int i=0; i<tam; i++){
		printf("\nPlaca: %s ", vect[i].placa);
		printf("\nModelo: %d ", vect[i].modelo);
		printf("\nMarca: %s ", vect[i].marca);
		printf("\nNumero de puertas: %d ", vect[i].puertas);
	}	
}
