// 81 - Tapete aleatorio
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>

#define total 150

typedef struct cuarteto{
	int x;
	int y;
	int radio;
	int color;
}cuarteto;

void creaCirculo(cuarteto &circulo){
	circulo.x=rand()% 1500;
	circulo.y=rand()% 700;
	circulo.radio= rand()%200;
	circulo.color= rand()%16;
}

void guardaCirculos(){
	FILE *f;
	cuarteto aux;
	
	f=fopen("c:/borrame/circulos.txt","w");
	if(f==NULL){
		printf("\nError en apertura de archivos.");
		getch();
		return;
	}
	
	for(int i=0; i<total; i++){
		creaCirculo(aux);
		fprintf(f,"%d\n", aux.x);
		fprintf(f,"%d\n", aux.y);
		fprintf(f,"%d\n", aux.radio);
		fprintf(f,"%d\n", aux.color);
	}
	fclose(f);
}

void dibujaTapete(){
	FILE *f;
	cuarteto aux;
	
	f=fopen("c:/borrame/circulos.txt","r");
	if(f==NULL){
		printf("\nError en apertura de archivos.");
		getch();
		return;
	}
	
	while(!feof(f)){
		fscanf(f,"%d\n", &aux.x);
		fscanf(f,"%d\n", &aux.y);
		fscanf(f,"%d\n", &aux.radio);
		fscanf(f,"%d\n", &aux.color);
		
		setfillstyle(1,aux.color);
		fillellipse(aux.x, aux.y, aux.radio, aux.radio);
	}
	
	fclose(f);
}

main(){
	
	int pantalla=DETECT, modo;
	initgraph(&pantalla, &modo, "\\TC\\BGI");
		
	srand((unsigned)time(NULL));
	
	guardaCirculos();
	
	dibujaTapete();
	getch();
	
	closegraph();
}
