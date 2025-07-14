//92 - Encriptacion de archivos de texto
//Clave : 2251

#include <stdio.h>
#include <conio.h>

char nomArchivo[255];

void imprimeArchivo();

void encriptaArchivo(){
	int clave;
	char c;
	FILE *arch;
	FILE *f;
	
	printf("\nDar nombre y ruta del archivo: \n");
	fflush(stdin);
	gets(nomArchivo);
	
	arch = fopen(nomArchivo, "r");
	if (arch == NULL){
		printf("\nError en la apertura del archivo");
		getch();
		return;
	}
	
	f = fopen("auxiliar.txt", "w");
	if (f == NULL){
		printf("\nError en la apertura del archivo");
		getch();
		return;
	}
	
	printf("\nIngresar la clave de encriptacion: ");
	scanf("%d", &clave);
	
	while (!feof(arch)){
		// fgetc: Funcion para leer caracteres
		c = fgetc(arch); //Se leyo el caracter
		
		//Encriptado
		c = c^clave;
		//Mandar al archivo auxiliar
		fprintf(f, "%c", c);
		//printf("%c", c);
	}
	
	fclose(arch);
	fclose(f);
	
	//Borrar archivo original y renombrar al archivo auxiliar
	remove(nomArchivo);
	rename("auxiliar.txt", nomArchivo);
	
	imprimeArchivo();
}

void imprimeArchivo(){
	FILE *arch;
	char c;
	
	arch = fopen(nomArchivo, "r");
	
	if (arch = NULL){
		printf("\nError en la apertura del archivo");
		getch();
		return;
	}
	
	while (!feof(arch)){
		//Funcion para leer caracteres
		c = fgetc(arch);
		
		printf("%c", c);
	}
	
	fclose(arch);
}

void desencriptaArchivo(){
	encriptaArchivo();
}

int main(){
	int opc;
	
	do {
		printf("\n1. Encriptar archivo de texto");
		printf("\n2. Desencriptar archivo de texto");
		printf("\n3. Salir");
		printf("\nElija su opcion: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:
				encriptaArchivo();
				break;
			case 2:
				desencriptaArchivo();
				break;
			case 3:
				printf("\nFin de la ejecucion.");
				break;
			default:
				printf("\nOpcion incorrecta.");
		}
		
		
	} while(opc != 3);
	
	return 0;
}
