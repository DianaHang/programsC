// 88 - Bits

#include <stdio.h>
#include <conio.h>

void revelaBits(int num){
	for (int i = 128; i > 0; i = i/2){
		if (num & i){
			printf("1");
		} else {
			printf("0");
		}
	}
}

int main(){
	int numero;
	char resp;
	
	do {
		printf("\nDar un numero entero: ");
		scanf("%f", &numero);
		revelaBits(numero);
		
		printf("\nDeseas continuar? [S-> SI]: ");
		fflush(stdin);
		scanf("%c", &resp);
	} while (resp == 's' || resp == 'S');
}
