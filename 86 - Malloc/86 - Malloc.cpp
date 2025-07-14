// 86 - Malloc
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	char x;
	int y;
	struct nodo *z;
}nod;

int main(){
	nod *ptr;
	ptr = (nod *)malloc(sizeof(nod));
	ptr->x= 'a';
	ptr->y= 50;
	ptr->z=(nod *)malloc(sizeof(nod));
	ptr->z->x= 'b';
	ptr->z->y= 60;
	ptr->z->z= NULL;
	
	printf("\nptr->|%c|%d|->|%c|%d|->NULL", ptr->x, ptr->y, ptr->z->x, ptr->z->y);
	free(ptr->z);
	free(ptr);
	return 11;
}
