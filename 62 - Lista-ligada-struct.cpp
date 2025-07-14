//62-list_ligada_estructura
#include <stdio.h>

typedef struct nodo
{
	char c;
	int ne;
	float nf;
	struct nodo *ptr;
}nod;

int main()
{
	nod *t;
	t = new nod;
	t -> c = 'A';
	t -> ne = 10;
	t -> nf = 4.5;
	t -> ptr = new nod;
	t -> ptr -> c = 'B';
	t -> ptr -> ne = 20;
	t -> ptr -> nf = 5.6;
	t -> ptr -> ptr = NULL;
	
	printf("\nt -> |%c| |%d| |%.2f| -> |%c| |%d| |%.2f| -> NULL",t->c,t->ne,t->nf,t->ptr->c,t->ptr->ne,t->ptr->nf);
	delete(t->ptr);
	delete(t);
	
	return 5; 
}
