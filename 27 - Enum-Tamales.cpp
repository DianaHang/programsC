// 27 - enum-tamales
#include <stdio.h>

enum tamales{
	rojos,
	verdes
};

int main(){
	tamales resp;
	printf("\nEsta pregunta define nuestra amistad");
	printf("\nQue chilaquiles te gustan? [1-verdes o 0-rojos]:");
	scanf("%d", &resp);
	
	if(resp==rojos){
		printf("\n No podemos seguir siendo amigos ");
	}
	else if(resp==verdes){
		printf("\nPuedes seguir siendo mi amigo, vamos por unos");
	}
	else{
		printf("\nEntonces que prefieres?");
		scanf("%d",&resp);
	}	
	return 1;
}
