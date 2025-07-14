// 79 - Circulo animado
#include <graphics.h>
#include <conio.h>
#include <dos.h>

typedef struct circuloAnimado {
	int x, y; //Se trabajan los pixeles
	int radio, vis;
	//etiqueta:
	public:
		//constructor
		circuloAnimado(int x1, int y1, int radio1){
			x= x1;
			y = y1;
			radio = radio1;
			vis=0;
		}
	//funciones miembro
	void pintar(){
		//variable con dos posibles valores
		circle(x, y, radio);
		vis = 1; //centinela para hacer visible
	}
	//Funcion miembro ocultar
	void ocultar(){
		//Guardar en una variable el color activo
		unsigned int guardaColor = getcolor();
		if (vis){
			setcolor (getbkcolor());
			circle(x, y, radio); //Camuflaje
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
	
}circ;

int main(){
	circ c1(100, 200, 80); //Se invoca el constructor
	circ c2(800, 600, 150);
	
	int driver = DETECT, modo;
	
	initgraph(&driver, &modo, "\\TC\\BGI");
	
	c1.pintar();
	c2.pintar();
	getch();
	
	for (int i = 0; i<600; i++){
		c1.trasladar(100+i, 200);
		c2.trasladar(800-i, 600-i);
		delay(5);
	}
	
	/*Invocar funcion ocultar
	c1.ocultar();
	getch(); */
	
	//Invocar funcion trasladar
	c1.trasladar(600, 400);
	getch();
	
	closegraph();
}
