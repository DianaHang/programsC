// 10 - enum-switch
#include<stdio.h>

enum opciones {
	suma = 1,  // 1
	resta,  // 2
	multiplica,  // 3
	divide,  // 4
	modulo,  // 5
	salir  // 6
};

int main(){
	int opc;
	float x, y;
	
	do{
		printf("\n1. Sumar"
				"\n2. Restar"
				"\n3. Multiplicar"
				"\n4. Dividir"
				"\n5. Modulo"
				"\n6. Salir");
				
		printf("\nElija opcion [1,2,3,4,5,6]: ");
		scanf("%d",&opc);
		
		switch(opc){
			case suma:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%f + %f = %f",x,y,x+y);
				break;
			case resta:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%f - %f = %f",x,y,x-y);
				break;
			case multiplica:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%f * %f = %f",x,y,x*y);
				break;
			case divide:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				if(y==0){
					printf("\nDivision entre cero");
					break;
				}
					
				printf("\n%f / %f = %f",x,y,x/y);
				break;
			case modulo:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%d %% %d = %d",(int)x,(int)y,(int)x%(int)y);
				break;
			case salir:
				printf("\nGudbai");
				break;
			default:
				printf("\nOpcion incorrecta. Vuelva a elegir");
		}
	}while(opc!=salir);
	
	return 0;
}
