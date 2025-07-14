// 3- tipos de datos

#include <stdio.h>

int main(){
	//Declarar variables
	int a;        // 4 bytes
	float b;      // 4 bytes
	double d;     // 1 bit para el signo, 11 bits para exponente
	char c;       // 1 byte
	char s[10];   // 10 bytes
	
	//Entrada de datos
	printf("\nDar un valor entero: ");
	scanf("%d", &a);
	
	printf("\nDar un valor flotante b: ");
	scanf("%f", &b);
	
	printf("\nDar un valor double d: ");
	scanf("%lf", &d);
	
	printf("\nDar un caracter c: ");
	scanf(" %c", &c);
	
	printf("\nDar una cadena s: ");
	scanf("%9s", &s);
	
	//Salida de datos
	printf("\n Entero a: %d", a);
	printf("\n Flotante b: %.4f", b);
	printf("\n Double d: %.2lf", d);
	printf("\n Caracter c: %c", c);
	printf("\n Cadena s: %s", s);
	
	return 0;
}

