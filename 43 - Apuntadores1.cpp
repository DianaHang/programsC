//43 - Apuntadores_1

#include<stdio.h>

int main(){
	int varx = 100;
	int *ptr;
	ptr = &varx;
	printf("\n ptr -> |%d|", *ptr); //ptr -> |100|
	
	printf("\n\n ptr = %d", ptr);  // direccion de la variable
	printf("\n\n *ptr = %d", *ptr); //accede al contenido de la variable
	printf("\n\n &ptr = %d", &ptr); // direccion del puntero
	
	
}
