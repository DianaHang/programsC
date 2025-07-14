// 38 - Circulo con graficos

#include <graphics.h>
#include<conio.h>

int main(){
	
	//Inicializar variables
	int pantalla = DETECT;
	int modo;
	
	//Inicializar los graficos con la direccion de pantalla, modo y "direcciones BGI"
	initgraph(&pantalla, &modo, "c://TC/BGI");
	
	/*Funcion para graficar circulos en graphics.h
	circle(x, y, radio); */
	circle(300, 200, 150);
	
	//Para dar tiempo de ver el circulo ejecutado
	getch();
	
	//Cerrar los graficos
	closegraph();
	
	return 1;
}
