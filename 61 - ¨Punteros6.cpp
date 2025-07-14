// 61 - Punteros 6
#include <stdio.h>
typedef struct nodo{
	int num;
	struct nodo *ptr;
}nodi;

int main(){
	nodi *pt;
	pt = new nodi;
	pt->num = 10;
	pt->ptr= new nodi;
	pt->ptr->num=20;
	pt->ptr->ptr=NULL;
	
	printf("\npt->|%d|->|%d|->NULL",pt->num,pt->ptr->num);
	delete(pt->ptr);
	delete(pt);
	return 0;
}
