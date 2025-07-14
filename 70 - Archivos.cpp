// 70 - Archivos
#include <stdio.h>
#include <conio.h>

typedef enum opciones{
	alta=1, 
	listar, 
	salir
}op;

typedef struct alumnado{
	int nocuenta;
	char nombre[80];
	float prom;
}datos;

void guarda_archivo(){
	FILE *archi;
	datos alum;
	archi=fopen("c:/borrame-2251-2025/alumnos.txt","a");
	
	if(archi==NULL){
		printf("\nError en apertura de archivos\nPulsar tecla para continuar");
		getch();
		return;
	}
	printf("\nNo. cuenta: ");
	scanf("%d",&alum.nocuenta);
	printf("\nNombre: ");
	fflush(stdin);
	gets(alum.nombre);
	printf("\nPromedio: ");
	scanf("%f",&alum.prom);
	fprintf(archi,"\n%d",alum.nocuenta);
	fprintf(archi,"\n%s",alum.nombre);
	fprintf(archi,"\n%f",alum.prom);
	fclose(archi);
}

void leeRegistrosArchivo(){
	FILE *arch;
	datos regis;
	arch=fopen("c:/borrame-2251-2025/alumnos.txt","r");
	
	if(arch==NULL){
		printf("\nError en apertura de archivos\nPulsar tecla para continuar");
		getch();
		return;
	}
	
	while(!feof(arch)){
		fscanf(arch,"\n%d",&regis.nocuenta);
		fscanf(arch,"\n%s",&regis.nombre);
		fscanf(arch,"\n%f",&regis.prom);
		printf("\n\nNo. Cuenta: %d",regis.nocuenta);
		printf("\nNombre: %s",regis.nombre);
		printf("\nPromedio: %.2f",regis.prom);
	}
	fclose(arch);
}

int main(){
	op opc;
	do{
		printf("\n1. Alta de registro");
		printf("\n2. Listar registros");
		printf("\n3. Salir");
		printf("\nElija: ");
		scanf("%d",&opc);
		switch(opc){
			case alta:
				guarda_archivo();
				break;
			case listar:
				leeRegistrosArchivo();
				break;
			case salir:
				printf("\nFin de ejecucion");
				break;
			default:
				printf("\nOpcion incorrecta");
				
		}
	}while(opc!=salir);
}
