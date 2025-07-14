//78 Muestrario de gráficos
#include <graphics.h>
#include <conio.h>

int main(){
	//inicializar graficos
	int driver = DETECT; //Deafault valor 0
	int modo;
	
	initgraph(&driver, &modo, "\\TC\\BGI");
	//Color de linea (3: CYAN)
	setcolor(3);
	
	//Funcion para graficar circulo
	circle(200, 300, 150);
	   //   x    y   radio
	getch();
	
	//Graficar un pixel
	setcolor(14);
	putpixel(250, 400, YELLOW);
	getch();
	
	//Graficar una linea
	setcolor(RED);
	line(300, 200, 800, 300);
	getch();
	
	//Graficar una elipse
	setcolor(2);
	ellipse(600, 350, 0, 360, 180, 80);
	getch();
	
	//Graficar una elipse con colores y lineas
	setfillstyle(1, 5);
	fillellipse(800, 400, 90, 110);
	//posicion   x   y  radio x  radio y
	getch(); 
	
	//Diferentes tramas
	for (int i=0; i<12; i++){
		setfillstyle(i, 10);
		fillellipse(1200, 300, 180, 90);
		getch();
	}
	
	//Graficar un rectangulo
	setcolor(12);
	rectangle(200, 500, 200+180, 500+40);
	getch();
	
	//Texto
	setcolor(2);
	settextstyle(1, 0, 4);
	  //  tipo fuente, orientacion , tamaño
	outtextxy(200, 450, "Programacion II");
	getch();
	
	//Graficar un poligono: Sentido opuesto de las manecillas
	int vect[8];
	vect[0]=600;
	vect[1]=200;
	vect[2]=400;
	vect[3]=500;
	vect[4]=800;
	vect[5]=560;
	vect[6]=vect[0];
	vect[7]=vect[1];
	
	setfillstyle(1, 13);
	fillpoly(4, vect);
	getch();
	
	int vec[18];
	vec[0]=600; //x1
	vec[1]=100; //y1
	vec[2]=400; //x2
	vec[3]=400; //y2
	vec[4]=600; //x3
	vec[5]=400; //y3
	vec[6]=600; //x4
	vec[7]=800; //y4
	vec[8]=800; //x5
	vec[9]=800; //y5
	vec[10]=800; //x6
	vec[11]=400; //y6
	vec[12]=1000; //x7
	vec[13]=400; //y7
	vec[14]=800; //x8
	vec[15]=100; //y8
	vec[16]=vec[0];
	vec[17]=vec[1];
	
	
	
	setfillstyle(1, 13);
	fillpoly(9, vec);
	getch();
	
	closegraph();
	return 0;
}
