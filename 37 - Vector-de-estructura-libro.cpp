//37-vector de estructura libro
#include<stdio.h>
#define tam 5
typedef struct libro{
	char titulo[120];
	int idlib;
	int pags;
	int ano;
} libro;

void leer_registros(libro [tam]);
void imprime_registro(libro [tam]);

int main()
{
	char resp;
	libro lib[tam];
	do{
	    leer_registros(lib);
		imprime_registro(lib);
		printf("\nDesea continuar [S/N]: ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp=='s' || resp=='S');
	return 6;
}

void leer_registros(libro vect[tam]){
	for(int i=0; i<tam; i++){
		printf("\nId libro: ");
		scanf("%d", &vect[i].idlib );
		printf("\nTitulo: ");
		fflush(stdin);
		gets(vect[i].titulo);
		printf("\nAño de publicacion: ");
		scanf("%d", &vect[i].ano );
		printf("\nNumero de paginas: ");
		scanf("%d", &vect[i].pags);
	}
}

void imprime_registro(libro vect[tam]){
	for (int i=0; i<tam; i++){
		printf("\nId libro: %d ", vect[i].idlib);
		printf("\nTitulo: %s ", vect[i].titulo);
		printf("\nAño de publicacion: %d ", vect[i].ano);
		printf("\nNumero de paginas: %d ", vect[i].pags);
	}	
}
