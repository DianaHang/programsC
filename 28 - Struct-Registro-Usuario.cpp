//28 - Struct-registro-usuario
#include <stdio.h>
#include <conio.h>

typedef struct usuario{
	int idusuario;
	char nombrecompleto[80];
	char user[9];
	char passw[9];
}stu;

void leeRegistro(stu &reg){
	printf("\nIdentificador: ");
	scanf("%d",&reg.idusuario);
	printf("\nNombre completo: ");
	fflush(stdin);
	gets(reg.nombrecompleto);
	printf("\nUser: ");
	scanf("%s",&reg.user);
	printf("\nPassword: ");
	scanf("%s",&reg.passw);
}

void imprimeRegistro(stu reg){
	printf("\nIdentificador: %d",reg.idusuario);
	printf("\nNombre completo: %s",reg.nombrecompleto);
	printf("\nUser: %s",reg.user);
	printf("\nPassword: %s",reg.passw);
}

int main(){
	stu  u1,u2,u3;
	leeRegistro(u1);
	imprimeRegistro(u1);
	leeRegistro(u2);
	imprimeRegistro(u2);
	leeRegistro(u3);
	imprimeRegistro(u3);
	return 10;
}
