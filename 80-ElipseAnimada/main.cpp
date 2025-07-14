// 80- Elipse animada
#include <graphics.h>
#include <conio.h>
#include <dos.h>

typedef struct elipseAnimada {
	int x, y; //Se trabajan los pixeles
	int radiox, radioy, vis;
	//etiqueta:
	public:
		//Etiqueta: constructor
	    elipseAnimada(int x1, int y1, int radiox1, int radioy1){
			x= x1;
			y = y1;
			radiox = radiox1;
			radioy = radioy1;
			vis=0;
		}
	//funciones miembro
	void pintar(){
		setfillstyle(1, 12);
		fillellipse(x, y, radiox, radioy);
		vis = 1; //centinela para hacer visible
	}
	//Funcion miembro ocultar
	void ocultar(){
		unsigned int guardaColor = getcolor();
		if (vis){
			setcolor (getbkcolor()); //Camuflaje
			setfillstyle(1, getbkcolor());
			fillellipse(x, y, radiox, radioy);
			vis = 0;
			setcolor(guardaColor); //se activa el color guardado
		}
	}
	
	//Funcion trasladar
	void trasladar(int nx, int ny){
		if (vis){
			ocultar();
			//Cambiar valores de posicion
			x = nx;
			y = ny;
			pintar();
		} else {
			x = nx;
			y = ny;
		}
	}
	
}elipse;

int main(){
	elipse e1(100, 200, 180, 90); //Se invoca al constructor
	elipse e2(800, 600, 150, 230);
	
	int driver = DETECT, modo;
	
	initgraph(&driver, &modo, "\\TC\\BGI");
	
	e1.pintar();
	e2.pintar();
	getch();
	
	for (int i = 0; i<600; i++){
		e1.trasladar(100+i, 200);
		e2.trasladar(800-i, 600-i);
		delay(5);
	}
	getch();
	
	closegraph();
	return 22;
}
