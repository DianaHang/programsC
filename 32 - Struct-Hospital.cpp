//31-struct-hospital
#include<stdio.h>

struct Mac_Hospital{
	int idHospital;
	char nombre[80];
	char direccion[110];
	char telefono[12];
	int numero_camas;
	char director[80];
};

int main(){
	struct Mac_Hospital x;
	
	printf("\n Identificador: ");
	scanf("%d", &x.idHospital);
	
	printf("\nNombre:");
	fflush(stdin);
	gets(x.nombre);

	printf("\nDireccion:");
	fflush(stdin);
	gets(x.direccion);
	
	printf("\nNumero de telefono:");
	scanf("%s", &x.telefono);
	
	printf("\nNumero de camas: ");
	scanf("%d", &x.numero_camas);
	
	printf("\nNombre del director:");
	fflush(stdin);
	gets(x.director);
	
	printf("\nIdentificador: %d", x.idHospital);
	printf("\nNombre: %s", x.nombre);
	printf("\nDireccion: %s", x.direccion );
	printf("\nNumero de telefono: %s", x.telefono);
	printf("\nNumero de camas: %d", x.numero_camas);
	printf("\nNombre del dirtector: %s", x.director);
	
	return 1;
}
