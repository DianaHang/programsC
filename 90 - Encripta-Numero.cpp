// 90 - Principio de encriptacion
#include <stdio.h>
#include <conio.h>

int main(){
	char resp;
	int dato, clave;
	
	do{
		
		printf("\nDar un dato entero para encriptar: ");
		scanf("%d", &dato);
		printf("\nDar una clave de encriptacion: ");
		scanf("%d", &clave);
		
		//Primer or exclusivo ^
		dato = dato^clave; // dato ^= clave
		printf("\nEl dato encriptado es: %d", dato);
		
		//Segundo or excusivo ^
		dato ^= clave;
		printf("\nEl dato desencriptado es: %d", dato);
		
		printf("\nDeseas continuar? [SI -> S / NO -> Cualquier tecla]: ");
		fflush(stdin);
		scanf("%c", &resp);
	} while(resp == 'S' || resp =='s');
	
	return 1;
}
