/* 92 - Steganografia
Crear un directorio para almacenar el programa con su imagen.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Variable global
char nomRutaArch[255];

void ocultaMensaje(FILE *imagen, FILE *salida, const char *mensaje){
	int c;
	unsigned int i = 0;
	unsigned int longitud = strlen(mensaje)+1; //+1 por el fin de la cadena
	
	//Leer datos del archivo (como no se cuantos, uso while)
	while ((c = fgetc(imagen))!= EOF){
		if (i < longitud * 8){
			//Limpiamos el ultimo bit (menos significativo)
			c = c & 254; //El valor del 2^0
			c = c | (mensaje[i / 8]) >> (i % 8) & 1; //Tomar primer bit de primer byte y desplazarlo
			i++;
		}
		
		//Agregar el elemento tomado a la salida
		fputc(c, salida);
	}
	
	if (i < longitud * 8){
		printf("\nAdvertencia: Imagen muy pequenia para ocultar el mensaje.");
	} else {
		printf("\nEl mensaje se ha ocultado con exito.");
	}
}

//Funcion que extrae mensaje de imagen
void extraeMensaje(FILE *imagen){
	int c, indice = 0;
	char caracter = 0;
	
	//Recorrer los 54 bytes de memoria del encabezado
	fseek(imagen, 54, SEEK_SET);
	
	//Ver contenido del archivo
	while ((c = fgetc(imagen)) != EOF){
		caracter = caracter | (c & 1) << indice;
		indice++;
		
		//Verificar longitud de caracteres con indice
		if (indice == 8){
			if (caracter == '\0') break;
			printf("%c", caracter);
			caracter = 0;
			indice = 0;
		}
	}
	
	printf("\n\n");
}

int main(){
	//Definir punteros y variables
	char mensaje [120];
	FILE *origen, *salida;
	
	//Dar ruta y nombre del archivo (imagen)
	printf("\nDar ruta y nombre de archivo de la imagen.BMP: ");
	fflush(stdin);
	gets(nomRutaArch);
	printf("\nDar el mensaje a ocultar: ");
	gets(mensaje);
	
	//Abrir archivos
	origen = fopen(nomRutaArch, "rb"),
	salida = fopen("salida.bmp", "wb");
	
	//Se pudieron abrir archivos o no
	if (!origen || !salida){
		printf("\nError en apertura de archivos.");
		getch();
		return 0;
	}
	
	//salto luego de los 54 bytes del encabezado
	for (int i = 0; i < 54; i++){
		fputc(fgetc(origen), salida); //Toma los datos del encabezado y se guardan en arch salida
	}
	
	//Invocar a la funcion para ocultar
	ocultaMensaje(origen, salida, mensaje);
	fclose(origen);
	fclose(salida);
	
	//revelar el contenido de salida
	origen = fopen("salida.bmp", "rb");
	//Se pudo abrir o no
	if (!origen){
		printf("\nError en la apertura de este archivo.");
		getch();
		return 0;
	}
	
	printf("\n\nEl mensaje oculto es: \n");
	extraeMensaje(origen);
	
	return 1;
}
