//55 - puntero-simple
#include <stdio.h>

int main(){
	
	float A, *ptr;
	ptr = &A;
	*ptr = 987.2; //A=987.2
	
	printf("\nptr->|%.2f|",*ptr);
	
	return 20;
}4
