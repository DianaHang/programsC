// 4 - Sumatoria

#include<stdio.h>

int main(){
	//declarar variables
	float n, multi;
	
	//Entrada de datos
	printf("Dame el numero de la sumatoria: ");
	scanf("%f", &n);
	
	//Operación sumatoria
	multi = ((n * (n+1))/2);
	
	//Salida de datos
	printf("La sumatoria es: %.2f\n", multi);
	
	return 0;
}
