//14 - for
#include <stdio.h>

int main(){
	int edad;
	char respuesta;
	char nombre[80];
	
	do{
		printf("\n Nombre: ");
		fflush(stdin);
		gets(nombre);
		printf("\n Edad(anios cumplidos):");
		scanf("%d",&edad);
		for(int cuenta = 1;cuenta <= edad;cuenta++){
			printf("\n %d - %s",cuenta,nombre);
		}
		printf("\n Deseas continuar con la ejecucion?[s--> si, o cualquier caracter en caso contrario]");
		fflush(stdin);
		scanf("%c",&respuesta);
	}while(respuesta == 's'|| respuesta == 'S');
	
	return 0;
}
