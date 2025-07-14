// 89 - Operadores-Nivel-Bits
#include<stdio.h>
#include<conio.h>

void revelaBits(int num){
	for(int i=128;i>0;i=i/2){  //1073741824
		if(num & i){
			printf("1");
		}
		else
		  printf("0");
	}
	
}

int main(){
	int x,y,z,nb;
	char resp;
	do
	{
		printf("\nDar un numero entero x:");
		scanf("%d",&x);
		printf("\nDar un numero entero y:");
		scanf("%d",&y);
		z=x&y;
		printf("\nx= %d",x);
		printf("\ny= %d",y);
		printf("\n%d & %d= %d",x,y,z);
		printf("\nRepresentacion con bits\n");
		revelaBits(x);
		printf(" & ");
		revelaBits(y);
		printf(" = ");
		revelaBits(z);
		getch();
		
		z=x|y;
		printf("\n\nx= %d",x);
		printf("\ny= %d",y);
		printf("\n%d | %d= %d",x,y,z);
		printf("\nRepresentacion con bits\n");
		revelaBits(x);
		printf(" | ");
		revelaBits(y);
		printf(" = ");
		revelaBits(z);
		getch();
		
		z=x^y;
		printf("\n\nx= %d",x);
		printf("\ny= %d",y);
		printf("\n%d ^ %d= %d",x,y,z);
		printf("\nRepresentacion con bits\n");
		revelaBits(x);
		printf(" ^ ");
		revelaBits(y);
		printf(" = ");
		revelaBits(z);
		getch();
		
		z=~x;
		printf("\n\nx= %d",x);
		printf("\n~x= %d",z);
		printf("\nRepresentacion con bits\n");
		printf(" ~ ");
		revelaBits(x);
		printf(" = ");
		revelaBits(z);
		getch();
		
		
		z=~y;
		printf("\n\ny= %d",y);
		printf("\n~y= %d",z);
		printf("\nRepresentacion con bits\n");
		printf(" ~ ");
		revelaBits(y);
		printf(" = ");
		revelaBits(z);
		getch();
		
		printf("\nCuantos bits a la derecha desea recorrer para x?: ");
		scanf("%d",&nb);
		z=x>>nb;
		printf("\n\n %d >> %d =%d",x,nb,z);
		printf("\nRepresentacion con bits\n");
		revelaBits(x);
		printf(" >> %d= ",nb);
		revelaBits(z);
		getch();
		
		printf("\nCuantos bits a la izquierda desea recorrer para y?: ");
		scanf("%d",&nb);
		z=y<<nb;
		printf("\n\n %d >> %d =%d",y,nb,z);
		printf("\nRepresentacion con bits\n");
		revelaBits(y);
		printf(" >> %d= ",nb);
		revelaBits(z);
		getch();
		
		printf("\nDesea continuar?->S:si ");
		fflush(stdin);
		scanf("%c",&resp);
	}
	while(resp=='S'||resp=='s');
	
	return 0;
}
