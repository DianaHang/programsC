// 9 - Area y volumen de cilindro

#include <stdio.h>
#include <time.h>
#include <math.h>
#define pi 3.1416

float volumenCilindro(float, float);

typedef enum cilindro {
	area = 1,
	volumen,
	salir
}c;

void caratula(){
	printf("\nUniversidad Nacional Autonoma de Mexico" 
			"\n Facultad de Estudios Superiores Acatlan"
			"\nMatematicas Aplicadas y Computacion"
			"\nProgramacion 2 \t Grupo 2251");
}

void stop(){
	char x;
	printf("\nPulse tecla para continuar: ");
	fflush(stdin);
	scanf("%c", &x);
}

float areaCilindro(float radio, float altura){
	return (2 * pi * radio *(altura + radio));
}

float volumenCilindro(float radio, float altura){
	return (pi * (pow(radio, 2))*altura);
}

int main(){
	//Inicializar tiempo de ejecucion y variables
	time_t tinic, tfin;
	int opc;
	float rad, altura;
	
	tinic = time(NULL);
	caratula();
	stop();
	
	do {
		printf("\n1. Calculo de area del cilindro");
		printf("\n2. Calculo del volumen del cilindro");
		printf("\n3. Salir");
		printf("\nElegir opcion: ");
		scanf("%d", &opc);
		
		switch(opc){
			case area:
				printf("\nArea de un cilindro.");
				printf("\nIngresa el radio: ");
				scanf("%f", &rad);
				printf("\nIngresa la altura: ");
				scanf("%f", &altura);
				printf("\nEl area del cilindro es: %.2f unidades cuadradas", areaCilindro(rad, altura));
				stop();
				break;
			case volumen:
				printf("\nVolumen de un cilindro: ");
				printf("\nIngresa el radio: ");
				scanf("%f", &rad);
				printf("\nIngresa la altura: ");
				scanf("%f", &altura);
				printf("\nEl volumen del cilindro es: %.2f unidades cubicas", volumenCilindro(rad, altura));
				stop();
				break;
			case salir:
				printf("\nFin de la ejecucion.");
				break;
			default: 
				printf("\nOpcion incorrecta, escoja de nuevo.");
				stop();
		}
	} while (opc != salir);
	
	tfin = time(NULL);
	printf("\nLa hora de entrada es: %s", asctime(localtime(&tinic)));
	printf("\nLa hora de salida es: %s", asctime(localtime(&tfin)));
	printf("\nTiempo de permanencia: %4.2f seg", difftime(tfin, tinic));
	
	return 0;
}
