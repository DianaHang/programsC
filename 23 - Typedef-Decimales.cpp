// 23 - typedef-decimales
#include <stdio.h>

typedef float decimal;

int main(){
	const decimal pi = 3.1416;
	decimal radio;
	
	printf("\nDar radio: ");
	scanf("%f",&radio);
	
	printf("\nEl area del circulo de radio %.2f es: %.2f",radio, pi*radio*radio);
	return 0;
}
