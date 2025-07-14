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

int main(){
	char resp;
	char frase[255];
	int clave, tam;
	
	do{
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
		
		//Invocar la frase original
		desencriptar(frase, tam, clave);
		printf("\nLa frase desencriptada es: \n%s ", frase);
		
		printf("\nDeseas continuar? [SI -> S / NO -> Cualquier tecla]: ");
		fflush(stdin);
		scanf("%c", &resp);
	} while(resp == 'S' || resp =='s');
	
	return 1;
}
