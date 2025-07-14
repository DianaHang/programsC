// 11-Procedimientos 
#include <stdio.h>

//Prototipo
void caratula();

enum opciones {
	suma = 1,  // 1
	resta,  // 2
	multiplica,  // 3
	divide,  // 4
	modulo,  // 5
	salir  // 6
};

// Procedimiento
void stop(){
	char w;
	printf("\n[PULSAR TECLA PARA CONTINUAR]\n");
	fflush(stdin);
	scanf("%c",&w);
}

int main()
	int opc;
	float x, y;
	
	caratula();
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
				stop();
				break;
			case resta:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%f - %f = %f",x,y,x-y);
				stop();
				break;
			case multiplica:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%f * %f = %f",x,y,x*y);
				stop();
				break;
			case divide:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				if(y==0){
					printf("\nDivision entre cero");
					stop();
					break;
				}
				printf("\n%f / %f = %f",x,y,x/y);
				stop();
				break;
			case modulo:
				printf("\nDar un valor: ");
				scanf("%f",&x);
				printf("\nDar otro valor: ");
				scanf("%f",&y);
				printf("\n%d %% %d = %d",(int)x,(int)y,(int)x%(int)y);
				stop();
				break;
			case salir:
				printf("\nGudbai");
				stop();
				break;
			default:
				printf("\nOpcion incorrecta. Vuelva a elegir");
				stop();
		}
	}while(opc!=salir);
	return 0;
}

void caratula(){
	printf("\nUniversidad Nacional Autonoma de Mexico"
			"\nFacultad de Estudios Superiores Acatlan"
			"\nLicenciatura en Matematicas Aplicadas y Computacion"
			"\nProgramacion 2"
			"\nGrupo 2251");
}
