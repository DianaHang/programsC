//64-Grafica seno y coseno
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main(){
	//Enteros para los graficos
	int p= DETECT, m;
	initgraph(&p, &m, "\\TC\\BGI");
	//Fondo
	setbkcolor(WHITE);
	cleardevice();
	//Texto
	setcolor(BLACK);
	settextstyle(4, 0, 7);
	outtextxy(300, 100, "Grafica seno y coseno");
	//Lineas de ejes
	line(100, 500, 1200, 500);
	line(100, 250, 100, 750);
	//Texto ejes
	settextstyle(10, 0, 4);
	outtextxy(1250, 500, "EJE X");
	
	settextstyle(10, 1, 4);
	outtextxy(80, 450, "EJE Y");
	
	//Funcion seno y coseno
	for (int x = 100; x < 1250; x++){
		putpixel(x, 500 + 100*sin(2*3.1416 * (float)x/120), BLUE);
		putpixel(x, 500 + 110*cos(2*3.1416*(float)x/120), RED);
	}
	
	getch();
	closegraph();
	
	return 1;
}
