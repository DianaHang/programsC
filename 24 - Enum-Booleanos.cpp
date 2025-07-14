// 24 - enum-booleanos
#include <stdio.h>

enum booleanos {
	falso,
	verdadero
};

int main(){
	enum booleanos resp;
	printf("\nLlueve? [1-Si, 0-No] ");
	scanf("%d",&resp);
	
	if(resp==falso)
		printf("\nNo esta lloviendo");
	else if(resp==verdadero)
		printf("\nEsta lloviendo");
	else
		printf("\nEntrada incorrecta");
		
	return 0;
}
