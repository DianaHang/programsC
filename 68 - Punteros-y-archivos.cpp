/*  68 - Punteros y archivos

	1. Incluir bibliotecas <stdio.h>
	2. Definir un puntero de tipo FILE
	3. Generar la corriente o flujo con fopen
		(Validar si fue posible abrirlo)
	4. Manipular el archivo: agregar, borrar, modificar, busquedas y consultar
	5. Cerrar el archivo */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main(){

	FILE *archivo;
	char cadena[40], resp;
	//archivo = fopen("datos.txt","w");
	archivo = fopen("c:/borrame-2251-2025/datos.txt","a");
	
	if(archivo == NULL){
		printf("\nError en apertura de archivo\n Pulse tecla para continuar");
		getch();
		return 0;
	}
	
	do{
		printf("\nDar una cadena: ");
		fflush(stdin);
		gets(cadena);
		fprintf(archivo,"\n%s",cadena);
		printf("\nDeseas continuar? [s-->SI cualquier tecla-->NO]");
		scanf("%c",&resp);
	}while(resp=='s'||resp=='S');
	
	fclose(archivo);
}
