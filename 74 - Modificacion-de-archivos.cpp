// 74 - Modificacion-de-archivos

#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<string.h>
typedef enum opciones{
	alta=1,
	baja,
	buscar,
	modificar,
	listar,
	salir
}opcion;
void ConfiguraIdioma(){
	//Cambia al idioma Español   
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para México
	strcmp(lcPtr->decimal_point, ".");
	strcmp(lcPtr->thousands_sep, ",");
	strcmp(lcPtr->grouping, "3");	
}
void portada(){
	ConfiguraIdioma();
    printf("\nUniversidad Nacional Autónoma de México\n"
     	   "Facultad de Estudios Superiores Acatlán\n"
    	   "Programación II. \n"
    	   "Grupo:2251. \n\n");
}
typedef struct usuario{
	int idUsuario;
	char nombre[50];
	char primerApellido[50];
	char segundoApellido[50];
	char usuario[9];
	char password[9];
} user;
void alto(){
	printf("\n\t[Pulse tecla para continuar]");
	getch();
}
void leeRegistro(user &mac_usuario){
	printf("\nIdentificador: ");
	scanf("%d", &mac_usuario.idUsuario);
	printf("\nNombre: ");
	fflush(stdin);
	gets(mac_usuario.nombre);
	printf("\nPrimer apellido: ");	
	gets(mac_usuario.primerApellido);
	printf("\nSegundo apellido: ");
	gets(mac_usuario.segundoApellido);
	printf("\nUsuario: ");
	scanf("%s", &mac_usuario.usuario);
	printf("\nPassword (clave): ");
	scanf("%s", &mac_usuario.password);
}
void imprimeRegistro(user &mac_usuario){
	printf("\n\nIdentificador: %d",mac_usuario.idUsuario);
	printf("\nNombre: %s", mac_usuario.nombre);
	printf("\nPrimer apellido: %s", mac_usuario.primerApellido);	
	printf("\nSegundo apellido: %s",mac_usuario.segundoApellido);
	printf("\nUsuario: %s",mac_usuario.usuario);
	printf("\nPassword (clave): %s", mac_usuario.password);
}
void almacenarRegistro(user &mac_usuario){
	FILE *arch;
	arch=fopen("c:/borrame2251/usuarios.dat","ab");
	if(arch == NULL){
		printf("\nError en apertura del alchivo; c:/borrame2251/usuarios.dat");
		alto();
		return;
	}
	fwrite(&mac_usuario,sizeof(user),1,arch);
	fclose(arch);
	printf("\nRegistro almacenado con exito");
	alto();
}
void listaRegistrosAlmacenado(){
	FILE *arch;
	user aux;
	arch=fopen("c:/borrame2251/usuarios.dat","rb");
	if(arch==NULL){
		printf("\nError en apertura del alchivo; c:/borrame2251/usuarios.dat");
		alto();
		return;
	}
	while(fread(&aux,sizeof(user),1,arch)){
		imprimeRegistro(aux);
	}
	fclose(arch);
	alto();
}
int buscaRegis(int idBuscar){
	FILE *f;
	user aux;
	int centinela=0;
	f=fopen("c:/borrame2251/usuarios.dat","rb");
	if(f==NULL){
		printf("\nError en apertura del archivo: c:/borrame2251/usuarios.dat");
		alto();
		return -1;
	}
	while(fread(&aux,sizeof(user),1,f)){
		if(idBuscar==aux.idUsuario){
			printf("\nRegistro encontrado\n");
			imprimeRegistro(aux);
			alto();
			centinela=1;
			break;
		}
	}
	if(centinela==0){
		printf("\nRegistro no almacenado en el Base de Datos\n");
		alto();
	}
	fclose(f);
	return centinela;
}

void borrarRegis(int idBorrar){
	FILE *f, *f2;
	user aux;
	int centinela=0;
	f=fopen("c:/borrame2251/usuarios.dat","rb");
	if(f==NULL){
		printf("\nError en apertura del archivo: c:/borrame2251/usuarios.dat");
		alto();
		return;
	}
	centinela=buscaRegis(idBorrar);
	if(centinela==0){
		fclose(f);
		return;
	}
	f2=fopen("c:/borrame2251/borraArch.dat","wb");
	if(f2==NULL){
		printf("\nError en apertura del archivo: c:/borrame2251/borraArch.dat");
		alto();
		return;
	}
	
	while(fread(&aux,sizeof(user),1,f)){
		if(idBorrar==aux.idUsuario){
			printf("\nSe eliminará el registro\n");
			alto();
			centinela=1;
			continue;
		}
		else{
			fwrite(&aux,sizeof(user),1,f2);
		}
	}
	fclose(f);
	fclose(f2);
	
	remove("c:/borrame2251/usuarios.dat");
	rename("c:/borrame2251/borraArch.dat","c:/borrame2251/usuarios.dat");
}

void modificarRegis(int idModificar){
	FILE *f, *f2;
	user aux;
	int centinela=0, op;
	f=fopen("c:/borrame2251/usuarios.dat","rb");
	if(f==NULL){
		printf("\nError en apertura del archivo: c:/borrame2251/usuarios.dat");
		alto();
		return;
	}
	centinela=buscaRegis(idModificar);
	if(centinela==0){
		fclose(f);
		return;
	}
	f2=fopen("c:/borrame2251/borraArch.dat","wb");
	if(f2==NULL){
		printf("\nError en apertura del archivo: c:/borrame2251/borraArch.dat");
		alto();
		return;
	}
	
	while(fread(&aux,sizeof(user),1,f)){
		if(idModificar==aux.idUsuario){
			printf("\nMódulo de modificación de registro\n");
	
			do{
				printf("\n1.Modificar identificador ");
				printf("\n2.Modificar nombre ");
				printf("\n3.Modificar primer apellido ");
				printf("\n4.Modificar segundo apellido ");
				printf("\n5.Modificar usuario ");
				printf("\n6.Modificar password ");
				printf("\n7.Continuar ");
				printf("\nElija opcion: ");
				scanf("%d",&op);
				switch(op){
					case 1:
						printf("\nEl identificador actual es %d", aux.idUsuario);
						printf("\nDar el nuevo: ");
						scanf("%d", &aux.idUsuario);
						break;
					case 2:
						printf("\nEl nombre actual es %s", aux.nombre);
						printf("\nDar el nuevo: ");
						fflush(stdin);
						gets(aux.nombre);
						break;
					case 3:
						printf("\nEl primer apellido actual es %s", aux.primerApellido);
						printf("\nDar el nuevo: ");
						fflush(stdin);
						gets(aux.primerApellido);
						break;
					case 4:
						printf("\nEl segundo apellido actual es %s", aux.segundoApellido);
						printf("\nDar el nuevo: ");
						fflush(stdin);
						gets(aux.segundoApellido);
						break;
					case 5:
						printf("\nEl usuario actual es %s", aux.usuario);
						printf("\nDar el nuevo: ");
						scanf("%s",&aux.usuario);
						break;
					case 6:
						printf("\nEl password actual es %s", aux.password);
						printf("\nDar el nuevo: ");
						scanf("%s",&aux.password);
						break;
					case 7:
						fwrite(&aux,sizeof(user),1,f2);
						printf("\nRegistro modificado con éxito");
						alto();
						break;
					default:
						printf("\nOpción incorrecta");
						alto();
				}
				
			}while(op!=7);
			centinela=1;
			continue;
		}
		else{
			fwrite(&aux,sizeof(user),1,f2);
		}
	}
	fclose(f);
	fclose(f2);
	
	remove("c:/borrame2251/usuarios.dat");
	rename("c:/borrame2251/borraArch.dat","c:/borrame2251/usuarios.dat");
}


int main(){
	user regis;
	opcion opci;
	int idBuscar, x;
	portada();
	do{
		printf("\n\t1.Dar de alta un registro");
		printf("\n\t2.Borrar un registro");
		printf("\n\t3.Buscar un registro");
		printf("\n\t4.Modificar un registro");
		printf("\n\t5.Listar un registro");
		printf("\n\t6.Salir");
		printf("\n\tElija opcion: ");
		scanf("%d", &opci);
		switch(opci){
			case alta:
				leeRegistro(regis);
				printf("\nSe dará de alta el registro: ");
				imprimeRegistro(regis);
				alto();
				almacenarRegistro(regis);
				break;
			case baja:
				printf("\nDar el identificador del registro a borrar: ");
				scanf("%d", &idBuscar);
				borrarRegis(idBuscar);
				break;
			case buscar:
				printf("\nDar el identificador del registro a buscar: ");
				scanf("%d", &idBuscar);
				x=buscaRegis(idBuscar);
				break;
			case modificar:
				printf("\nDar el identificador del registro a modificar: ");
				scanf("%d", &idBuscar);
				modificarRegis(idBuscar);
				break;
			case listar:
				listaRegistrosAlmacenado();
				break;
			case salir:
				printf("\nFin de jecución");
				alto();
				break;
			default:
				printf("\nOpción incorrecta");
				alto();
		}
	}while(opci!=salir);
	return 1;
}
