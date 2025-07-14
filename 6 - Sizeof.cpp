// 6 - Sizeof

#include <stdio.h>

int main(){
	printf("\nLos enteros ocupan %d bytes", sizeof(int));
	printf("\nLos flotantes ocupan %d bytes", sizeof(float));
	printf("\nLos double ocupan %d bytes", sizeof(double));
	printf("\nUn caracter ocupa %c bytes", sizeof(char));
	printf("\nLos short int ocupan %d bytes", sizeof(short int));
	printf("\nLos long int ocupan %d bytes", sizeof(long int));
	printf("\nLos void ocupan %d bytes", sizeof(void));
	printf("\nLos long double ocupan %d bytes", sizeof(long double));
	
	return 0;
}
