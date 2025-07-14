//Corregido 
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

char nomRutaArch[255];

void ocultaMensaje(FILE *imagen, FILE *salida, const char *mensaje){
	int c;
	unsigned int i = 0, longitud = strlen(mensaje) + 1;
	while((c = fgetc(imagen)) != EOF){
		if(i < longitud * 8){
			c = c & 254;
			c = c | (mensaje[i / 8] >> (i % 8)) & 1;
			i++;
		}
		fputc(c, salida);
	}
	
	if(i < longitud * 8){
		printf("\nAdvertencia: Imagen muy pequeña para ocultar el mensaje");
	}
	else{
		printf("\nEl mensaje fue ocultado con exito");
	}
}

// Función que extrae mensaje de imagen
void extraeMensaje(FILE *imagen){
	int c, indice = 0;
	char caracter = 0;
	
	fseek(imagen, 54, SEEK_SET);
	
	while((c = fgetc(imagen)) != EOF){
		caracter = caracter | (c & 1) << indice;
		indice++;
		
		if(indice == 8){
			if(caracter == '\0') break;
			printf("%c", caracter);
			caracter = 0;
			indice = 0;
		}
	}
	
	printf("\n\n");
}

int main(){
	FILE *origen, *salida;
	char mensaje[120];
		
	printf("\nDar ruta y nombre de archivo de la imagen .BMP: ");
	fflush(stdin);
	gets(nomRutaArch);
	printf("\nDar el mensaje a ocultar: ");
	gets(mensaje);
	
	origen = fopen(nomRutaArch, "rb");
	salida = fopen("salida.bmp", "wb");
	
	if(!origen || !salida){
		printf("\nError en apertura de archivos");
		getch();
		return 0;
	}
	
	for(int i = 0; i < 54; ++i){
		fputc(fgetc(origen), salida);
	}
	
	ocultaMensaje(origen, salida, mensaje);
	
	fclose(origen);
	fclose(salida);
	
	// Revela el mensaje oculto de salida
	origen = fopen("salida.bmp", "rb");
	if(!origen){
		printf("\nError en apertura de archivo");
		getch();
		return 0;
	}
	
	printf("\n\nEl mensaje oculto es: \n");
	extraeMensaje(origen);
	
	return 1;
}
