// 87 - Vectores-ejercicio
#include <stdio.h>
#define n 4 
typedef struct persona{
	char nom_alumno[80];
	float promedio;
	float estatura;
}pers;

void leevector(pers [n]);
void imprimevector(pers [n]);

int main(){
	pers vector[n];
	leevector(vector);
	imprimevector(vector);
		
	return 1;
}

void leevector(pers vect[n]){
	for(int i=0; i<n; i++){
		fflush(stdin);
		printf("\nNombre: ");
		gets(vect[i].nom_alumno);
		printf("\nPromedio: ");
		scanf("%f", &vect[i].promedio);
		printf("\nEstatura: ");
		scanf("%f", &vect[i].estatura);
	}
	
}

void imprimevector(pers vect[n]){
	for(int i=0; i<n; i++){
		printf("\nNombre: %s", vect[i].nom_alumno);
		printf("\nPromedio: %.2f", vect[i].promedio);
		printf("\nEstatura: %.2f", vect[i].estatura);
		
	}
}
