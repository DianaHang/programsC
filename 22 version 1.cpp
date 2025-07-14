//22- Sistema-aritmetico-matrices

#include <stdio.h>
#include <conio.h>
#include <time.h>

#define n 3
#define m 3

enum opciones{
	leerArreglo = 1,
	sumaArreglo,
	restaArreglo,
	multiplicaArreglo,
	transpuestaArreglo,
	salir
};

void stop(){
	printf("\nPulse para continuar")
	fflush(stdin);
	getch();  //
}



int main(){
	time_t tinic, tfin;
	int opc;
	tinic = time(NULL);
	stop();
	
	do{
		printf("\n 1. Leer arreglos");
		printf("\n 2. Leer arreglos");
		printf("\n 1. Leer arreglos");
		printf("\n 1. Leer arreglos");
		printf("\n 1. Leer arreglos");
		printf("\n 6. Inversa del arreglo");
		printf("\n 7. Salir");
		printf("\n Elegir opcion: ");
		sacnf("%d", &opc);
		
		switch(oc){
			case leerArreglo:
				printf("\n Lectura de arreglos\n");
				stop();
				break;
			case sumaArreglo:
				printf("\n Suma de arreglos\n");
				stop();
				break;
			case restaArreglo:
				printf("\n Resta de arreglos\n");
				stop();
				break;
			case multiplicaArreglo:
				printf("\n Multiplicacion de arreglos\n");
				stop();
				break;
			case transpuestaArreglo:
				printf("\n Transpuesta de arreglos\n");
				stop();
				break;
			case inversaArreglo:
				printf("\n Inversa de arreglos\n");
				stop();
				break;
			case salir:
				printf("\n Lectura de arreglos\n");
				stop();
				break;
		}
	}
	
	return 0;
}
