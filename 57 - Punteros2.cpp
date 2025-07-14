// 57 - Punteros 2
#include <stdio.h>

int main(){
	
	int *pt1;
	pt1= new int;
	*pt1=10;
	printf("\npt1->|%d|",*pt1);
	
	float *pt2;
	pt2= new float;
	*pt2=3.5;
	printf("\npt2->|%.2f|",*pt2);
	
	char *pt3;
	pt3= new char;
	*pt3='Z';
	printf("\npt3->|%c|",*pt3);
	
	delete(pt1);
	delete(pt2);
	delete(pt3);
	
	return 0;

}
