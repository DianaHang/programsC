//69 uso_de_realloc
#include<stdio.h>
#include<stdlib.h>
void imprimeLista(int *, int );
int main(){
	int *nvo;
	int *lista;
	int num_elementos=0;
	char resp;
	do{
		if(num_elementos==0){
			nvo=(int *)malloc(sizeof(int));
		}
		else{
			nvo=(int *)realloc(lista,(num_elementos +1)*sizeof(int));
		}
		if(nvo==NULL){
			if(num_elementos>0){
				free(lista);
				printf("\nSe ha liberado la memoria");
			}
			exit(0);
		}
		lista=nvo;
		printf("\nDato: ");
		scanf("%d",&lista[num_elementos]);
		num_elementos++;
		imprimeLista(lista,num_elementos);
		printf("\nDireccion en donde se almacena lista: %d",lista);
		printf("\nDeseas agregar otro dato[s->Si,otra tecla->no]: ");
		fflush(stdin);
		scanf("%c",&resp);
	}while(resp=='s'||resp=='S');
	free(lista);
	printf("\nSe ha liberado la memoria ocupada por la lista");
}
void imprimeLista(int *lis, int n){
	for(int i=0;i<n;i++){
		printf("\nLista[%d]=%d",i,lis[i]);
	}
}
