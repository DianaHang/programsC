//85- Graficos diversos
#include <graphics.h>
#include <conio.h>
#include <time.h>

int main(){
	int p = DETECT, m;
	initgraph(&p, &m, "\\TC\\BGI");
	
	srand(time(NULL));
	
	//FONDO
	setbkcolor(LIGHTGRAY);
	cleardevice();
	//Texto
	setcolor(GREEN);
	settextstyle(5, 0, 10);
	outtextxy(300, 100, "Usa funcion arc");
	//ARCOS
	for (int radio = 1; radio < 400; radio+=25){
		setcolor(rand()%16);
		//   x    y   °i  °f    radio del arco
		arc(700, 450, 90, 270, radio);
	}
	setcolor(LIGHTRED);
	arc(850, 600, 0, 180, 200);
	getch();
	
	setbkcolor(LIGHTGREEN);
	cleardevice();
	//TEXTO
	setcolor(BLUE);
	settextstyle(4, 0, 8);
	outtextxy(300, 100, "BARRAS");
	//BARRAS
	for(int i = 0; i < 12; i++){
		bar3d(25*i, 200, 10+25*i, 500, 10, 10);	
	}
	getch();
	
	closegraph();
	return 1;
}
