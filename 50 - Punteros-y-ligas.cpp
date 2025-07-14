// 50- Intercambio de valores con punteros a traves de ligas

#include<stdio.h>
#include<conio.h>

int main(){
	//Declarar variables
	float var1, var2;
	float *ptr1, *ptr2, *ptr3;
	
	//Se crean las ligas
	ptr1 = &var1;
	ptr2 = &var2;
	ptr3 = NULL; //Asigna a una constante vacia
	
	//Lectura de datos
	printf("\nIngrese un numero decimal: ");
	scanf("%f", &(*ptr1));
	printf("\nIngrese otro numero decimal: ");
	scanf("%f", &(*ptr2));
	
	//Imprimir las asignaciones
	printf("\n\n --------PRIMERA ESCENA--------\n\n");
	printf("\n\n ptr1 -> |%.2f|", *ptr1);
	printf("\n ptr2 -> |%.2f|", *ptr2);
	getch(); //Para que se detenga

	//Intercambiar punteros a traves de ligas
	ptr3 = ptr2; //No se ponen * ni &, para que se muevan las ligas
	ptr2 = ptr1;
	ptr1 = ptr3;
	
	printf("\n\n ---------SEGUNDA ESCENA---------\n\n");
	printf("\nIntercambio de contenidos a traves de punteros\n");
	printf("\n\n ptr1 -> |%.2f|", *ptr1);
	printf("\n\n ptr2 -> |%.2f|", *ptr2);
	printf("\n\n ptr3 -> |%.2f|", *ptr3);
	
	
	return 1;
}
