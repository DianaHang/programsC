// 8 - Evaluacion de expresion matematica

#include <stdio.h>

int main(){
	char resp;
	int a, b, c;
	
	do{
		printf("\nDar un valor entero a: ");
		scanf("%d", &a);
		printf("\nDar un valor entero b: ");
		scanf("%d", &b);
		printf("\nDar un valor entero c: ");
		scanf("%d", &c);
		
		printf("\n (%d + %d * %d)&& !%d || %d*5 = %d ", a, b, c, c, a, (a+b*c)&& !c || a*5);
		
		printf("\nDeseas continuar con la ejecucion?\n[s-> SI, cualquier tecla en caso contrario]: ");
		fflush(stdin);
		scanf("%c", &resp);
		
	} while (resp == 's' || resp == 'S');
	
	printf("\nFIN DE LA EJECUCION.");
	return 0;
}
