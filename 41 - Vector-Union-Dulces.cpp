// 41 - Vector-union-dulces

#include <stdio.h>
#include <conio.h>
#define  pal 10
#define  cho 1.50
#define  chi 5
#define  sor 100

enum dulces{
	paletas=1,
	chocolates,
	chicles,
	Sorpresa,
	salir
};

typedef union tipos{
	int i;
	float f;
	char c;
}azucar;


void precioPaletas(azucar &a, azucar &b){
	
	b.i=a.i * pal;
}

void precioChocolates(azucar &a, azucar &b){
	
	b.f=a.f * cho;
}

void preciochiles(azucar &a, azucar &b){
	
	b.i=a.i * chi;
}

void precioSorpresa(azucar &a, azucar &b){
	
	b.c=sor;
}


int main()
{
	azucar o, p, q, r;
	int opc;
	
	
	do{
		printf("\n");
		printf("\n1.Paletas");
		printf("\n2.Chocolates");
		printf("\n3.Chicles");
		printf("\n4.Caja sorpresa");
		printf("\n5.Salir");
		printf("\nElija una opcion [1,2,3,4,5]--> ");
		scanf("%d",&opc);
		
		switch(opc){
			case paletas:
				printf("\nQue cantidad deseas: ");
				scanf("%d",&p.i);
				precioPaletas(p, q);
				printf("\nPor %d paletas es: $%d\n",p.i,q.i);
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");
				getch();
				break;
			case chocolates:
				printf("\nQue cantidad deseas en gramos: ");
				scanf("%f",&p.f);
				precioChocolates(p, q);
				printf("\nPor %.2f gramos de chocolates es: $%.2f\n",p.f,q.f);
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");
				getch();
				break;
			case chicles:
				printf("\nQue cantidad deseas: ");
				scanf("%i",&p.i);
				preciochiles(p, q);
				printf("\nPor %d chicles es: $%d\n",p.i,q.i);
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");
				getch();
				break;
			case Sorpresa:
				printf("\nElija que caja desea: \nCaja A): \nCaja B): \nCaja C): ");
				fflush(stdin);
				scanf(" %c",&p.c);
				if(p.c=='a'||p.c=='A'){
				printf("\nElejiste la caja A: Contiene 3 paletas, 50 gramos de chocolate y 1 chicle.\n");
				}
				else if (p.c=='b'||p.c=='B'){
				printf("\nElejiste la caja B: Contiene 4 paletas, 30 gramos de chocolate y 5 chicles.\n");
				}
				else if (p.c=='c'||p.c=='C'){
				printf("\nElejiste la caja C: Contiene 1 paleta, 60 gramos de chocolate y 2 chicles.\n");
				}
				else if (p.c=='d'||p.c=='D'){
				printf("\nELEJISTE LA CAJA SUPER HIPER MEGA SORPESA: Contiene 1 paleta, 1 gramo de chocolate y -3 chicles.\n");
				}
				else{
				printf("\nOpcion incorrecta\n");	
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");	
				getch();
				break;
				}
				precioSorpresa(p,q);
				printf("\nEl precio de la caja sorpresa es $%d \n",q.c);			
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");
				getch();
				break;
			case salir:
				printf("\nNos vemos wero\n");
				break;
			default:
				printf("\nOpcion incorrecta\n");
				printf("\n[PRESIONE CUALQUIER TECLA PARA CONTINUAR] ");
				getch();
		}
		
		
	}while(opc!=salir);
}
