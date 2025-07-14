// 2 - Pregunta datos con printf

#include <stdio.h>

int main(){
	// Declarar variables
	short int semestre;
	char nombre[80];
	char carrera[50];
	char resp[100];
	
	//Prompt paraa preguntar datos
	printf("\nCual es tu nombre? ");
	fflush(stdin);
	gets(nombre);
	
	printf("\nDe que carrera eres? ");
	fflush(stdin);
	gets(carrera);
	
	printf("\nEncantada %s, en que semestre estas? ", nombre);
	scanf("%hd", &semestre); // %letra es para el tipo de dato, &: pointer para direccionar el dato a la variable que se quiere
	getchar(); //funcion para obtener el dato
	
	printf("\nQue opinas de tu carrera? ");
	fflush(stdin);
	gets(resp);
	
	printf("\nMuy interesante, %s, la carrera de %s me parece interesante."
			"\nSigue con la carrera que ya vas en %d semestre y tu opinion (%s) es importante.", nombre, carrera, semestre, resp);
	
	return 0;
}
