// 91 - Encripta-Palabra
#include <stdio.h>
#include <conio.h>
#include <string.h>

void encriptar(char *frase, int tam, int clave){
	for ( int i = 0; i < tam; i++){
		frase[i] ^= clave;
	}
}

void desencriptar(char *frase, int tam, int clave){
	encriptar(frase, tam, clave);
}

void stop(){
	char resp;
	printf("\nPulse tecla para continuar: ");
	fflush(stdin);
	getch();
}

typedef enum opciones{
	encripta = 1,
	desencripta,
	salir
}opc;

int main(){
	char frase[255];
	int opc, clave, tam;
	
	do{
		printf("\n***ENCRIPTACION***");
		printf("\n1. Encripta frase. \n2. Desencripta frase. \n3. Salir.");
		printf("\nQue deseas realizar? ");
		scanf("%d", &opc);
		
		switch(opc){
			case encripta:
				printf("\nDar una frase para encriptar: ");
				fflush(stdin);
				gets(frase);
				printf("\nDar una clave de encriptacion: ");
				scanf("%d", &clave);
				//Calcular longitud de la cadena
				tam = strlen(frase);
				//Invocamos la encriptacion
				encriptar(frase, tam, clave);
				printf("\nLa frase encriptada es: \n%s ", frase);
				stop();
				break;
			case desencripta:
				//Invocar la frase original
				desencriptar(frase, tam, clave);
				printf("\nLa frase desencriptada es: \n%s ", frase);
				stop();
				break;
			case salir:
				printf("\FIN DE LA EJECUCION.");
				break;
			default:
				printf("\nError: Valor desconocido, vuelva a intentar. \n");
		}	
	} while(opc != 3);
	
	return 1;
}
