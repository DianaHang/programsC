// 71. control_de_usuarios

#include <stdio.h>
#include <conio.h>

typedef enum opciones{
	alta = 1,
	listar,
	salir
}opci;

typedef struct usuario{
	int idUsuario;
	char nombre[100];
	char user[10];
	char passw[9];
}usu;

void alto(){
	printf("\n[Pulse tecla para continuar]");
	getch();
}

void imprime_regis(usu x){
	printf("\n\nIdentificador: %d", x.idUsuario);
	printf("\nNombre: %s", x.nombre);
	printf("User: %s", x.user);
	printf("\nPassword: %s", x.passw);
}

void altaUsuario(){
	usu datos;
	FILE *arch;
	arch = fopen("c:/borrame_2251/usuarios.txt", "a");
	if(arch == NULL){
		printf("\nError en apertura de archivo\n");
		alto();
		return;
	}
	
	printf("\nIdentificador del usuario: ");
	scanf("%d", &datos.idUsuario);
	printf("\nNombre: ");
	fflush(stdin);
	gets(datos.nombre);
	printf("\nUsuario: ");
	fflush(stdin);
	scanf("%s", &datos.user);
	printf("\nPassword: ");
	fflush(stdin);
	scanf("%s", &datos.passw);
	
	fprintf(arch, "\n%d", datos.idUsuario);
	fprintf(arch, "\n%s", datos.nombre);
	fprintf(arch, "\n%s", datos.user);
	fprintf(arch, "\n%s", datos.passw);
	
	fclose(arch);
	printf("\nLos datos del usuario fueron almacenados con exito");
	alto();
}

void listaUsuarios(){
	FILE *f;
	usu datos;
	f = fopen("c:/borrame_2251/usuarios.txt", "r");
	if(f == NULL){
		printf("\nError en apertura de archivo\n");
		alto();
		return;
	}
	while(!feof(f)){
		fscanf(f, "%d", &datos.idUsuario);
		fflush(stdin);
		fgets(datos.nombre, 100, f);
		fgets(datos.nombre, 100, f);
		fscanf(f, "%s", &datos.user);
		fscanf(f, "%s", &datos.passw);
		imprime_regis(datos);
	}
	fclose(f);
	alto();
}

int main(){
	opci selec;
	do{
		printf("\n1. Alta de usuario");
		printf("\n2. Listar a todos los usuarios");
		printf("\n3. Salir");
		printf("\nElija: ");
		scanf("%d", &selec);
		switch(selec){
			case alta:
				altaUsuario();
				break;
			case listar:
				listaUsuarios();
				break;
			case salir:
				printf("\nFIN");
				break;
			default:
				printf("\nNo existe esa opcion :[");
		}
	}while(selec != salir);
}
