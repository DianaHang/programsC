// 75 - Apertura de archivos

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(int argc, char *argv[]){
	FILE *f1, *f2;
	if(argc!=3){
		printf("\nNumero de archivos en la linea de comandoes incorrecta");
		getch();
		exit(0);
	}
	if((f1=fopen(argv[1],"r"))==NULL){
		printf("\nError en apertura del archivo origen");
		getch();
		exit(0);
	}
	if((f2=fopen(argv[2],"w"))==NULL){
		printf("\nError en apertura del archivo destino");
		getch();
		exit(0);
	}
	while(!feof(f1)){
		putc(getc(f1),f2);
	}
	fclose(f1);
	fclose(f2);
}
