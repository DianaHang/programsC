// 39 - Rectangulo con graficos

#include<graphics.h>
#include <conio.h>

int main(){
	//Inicializar variables
	int pantalla = DETECT; //constante definida en grafics.h
	int modo;
	
	//Inicializar los graficos
	initgraph(&pantalla, &modo, "c://TC//BGI");
	
	/*funcion de rectangulo en graphics.h
	rectangle(x, y, contraesquina: x+base, y+altura); */
	rectangle(800, 300, 800+200, 300+100);
	
	//getch para dar tiempo al usuario de ver el grafico
	getch();
	
	//cerrar los graficos
	closegraph();
	
	return 2;
}
