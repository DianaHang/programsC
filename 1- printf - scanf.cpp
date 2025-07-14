// 1-Scanf - Printf

#include <stdio.h>

int main(){
	short int edad; // short: ocupa 2 bytes de memoria
	char nombre[80];
	
	//printf: es para hacer un prompt, esperandoque el usuario responda 
	printf("\nDar un nombre: ");
	fflush(stdin); //limpiar el buffer en caso de info. guardada
	gets(nombre); //Función gets: Para traer y almacenar el dato dado por el usuario
	
	printf("\nEdad: ");
	scanf("%hd", &edad);
	
	printf("\nConclusion: " "\nEres %s y tienes %d anios.", nombre, edad);
	
	return 0;

}

