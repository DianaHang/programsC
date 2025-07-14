// 7 - Suma_Revelador

#include <stdio.h>

int main(){
	//Inicializar variables
	char resp;
	int a, b;
	
	do {
		printf("\nDar un valor entero a: ");
		scanf("%d", &a);
		printf("\nDar un valor entero b: ");
		scanf("%d", &b);
		
		printf("\n%d + %d = %d", a, b, a+b);
		
		printf("\nDeseas continuar con la ejecucion? [S--> Si, cualquier tecla en caso contrario: ");
		fflush(stdin);
		scanf("%c", &resp);
	} while (resp == 's' || resp == 'S');
	
	printf("\nFIN DE LA EJECUCION.");
	return 0;
}
