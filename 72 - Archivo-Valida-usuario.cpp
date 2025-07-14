// 72. valida_usuario_con_archivo

#include <stdio.h>
#include <conio.h>
#include <string.h>

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

int main(){
	char usuarioDado[10], passwDado[9], resp;
	FILE *mac;
	usu datos;
	mac = fopen("c:/borrame_2251/usuarios.txt", "r");
	int bandera = 0;
	if(mac == NULL){
		printf("\nError en apertura de archivo\n");
		alto();
		return 0;
	}
	
	printf("\nDar usuario: ");
	scanf("%s", &usuarioDado);
	printf("\nIngresa el password: ");
	scanf("%s", &passwDado);
	
	while(!feof(mac)){
		fscanf(mac, "%d", &datos.idUsuario);
		fflush(stdin);
		fgets(datos.nombre, 100, mac);
		fgets(datos.nombre, 100, mac);
		fscanf(mac, "%s", &datos.user);
		fscanf(mac, "%s", &datos.passw);
		if((strcmp(usuarioDado, datos.user) == 0) && (strcmp(passwDado, datos.passw) == 0)){
			bandera = 1;
		}
	}
	fclose(mac);
	if(bandera != 1){
		printf("\nAcceso denegado :[");
		alto();
		return 0;
	}
	do{
		printf("\nBienvenido");
		printf("\nDeseas continuar? ");
		fflush(stdin);
		scanf("%c", &resp);
	}while(resp == 's' || resp == 'S');
	
	return 6;
}
