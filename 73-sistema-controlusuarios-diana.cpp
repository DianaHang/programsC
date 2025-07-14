// 73 - sistema control de usuarios

#include <stdio.h>
#include <conio.h>

//Crear estructura de usuarios
typedef struct usuario{
	int idUser;
	char nombre[50];
	char pApellido[50];
	char sApellido[50];
	char usuario[9];
	char password[9];
}user;

//funcion stop para detener el programa
void stop(){
	printf("\n\t[Pulse tecla para continuar: ]");
	getch();
}

//funcion para leer el registro dinamico
void leeRegistro(user &mac_usuario){
	printf("\nIdentificador: ");
	scanf("%d", &mac_usuario.idUser);
	
	printf("\nNombre: ");
	fflush(stdin);
	gets(mac_usuario.nombre);
	
	printf("\nPrimer apellido: ");
	gets(mac_usuario.pApellido);
	printf("\nSegundo apellido: ");
	gets(mac_usuario.sApellido);
	
	printf("\nUsuario: ");
	scanf("%s", &mac_usuario.usuario);

	
	printf("\nPassword: ");
	scanf("%s", &mac_usuario.password);
}

//funcion que imprima los registros
void imprimeRegistro(user &mac_usuario){
	printf("\n\nIdentificador: %d", mac_usuario.idUser);
	printf("\nNombre: %s", mac_usuario.nombre);
	printf("\nPrimer apellido: %s", mac_usuario.pApellido);
	printf("\nSegundo apellido: %s", mac_usuario.sApellido);
	printf("\nUsuario: %s", mac_usuario.usuario);
	printf("\nPassword: %s", mac_usuario.password);
}
//Funcion para guardar registro
void almacenaRegistro(user &mac_usuario){
	FILE *arch;
	arch = fopen("C:/Borrame-2251-diana/usuarios.dat", "a");
	if (arch == NULL){
		printf("\nError en apertura del archivo; C:/Borrame-2251-diana/usuarios.dat");
		stop();
		return;
	}
	
	//Si si se pudo abrir el archivo, lo abrimos para escribir
	fwrite(&mac_usuario, sizeof(user), 1, arch);
	//Cerrar el archivo
	fclose(arch);
	printf("\nRegistro almacenado con exito.");
	stop();
}

//funcion que lea los archivos y los presente en pantalla, que enliste registros almacenados
void listaRegistrosAlmacenados(){
	FILE *arch;
	//Variable que reciba los datos
	user aux;
	
	//Modo de solo lectura
	arch = fopen("C:/Borrame-2251-diana/usuarios.dat", "r");
	//Validar si se puede abrir
	if (arch == NULL){
		printf("\nError en apertura del archivo; C:/Borrame-2251-diana/usuarios.dat");
		stop();
		return;
	}
	
	//While porque no sabemos cuantos registros estan almacenados en el archivo
	while (fread(&aux, sizeof(user),1, arch)){
		imprimeRegistro(aux);
	}
	fclose(arch);
	stop();
}

int main(){
	//Variable de tipo USER
	user registro;
	
	//Invocar las funciones:
	leeRegistro(registro);
	imprimeRegistro(registro);
	stop();
	almacenaRegistro(registro);
	listaRegistrosAlmacenados();
	
	return 1;
}
