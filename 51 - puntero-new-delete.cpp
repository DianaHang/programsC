// 51 - puntero-new-delete
#include<stdio.h>

int main(){
	int *pt;
	pt = new int;
	
	*pt = 800;
	
	printf("\n pt -> |%d|", *pt);
	
	delete(pt);
	
	return 10;
}
