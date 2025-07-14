// Casa
#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
    int driver = DETECT;
    int modo;
    initgraph(&driver, &modo, "\\TC\\BGI");
    
    int pared[10] = {200, 400, 800, 400, 800, 900, 200, 900};
    pared[8] = pared[0];
    pared[9] = pared[1];
    setfillstyle(1, LIGHTGRAY);
    fillpoly(4, pared);
	
	int techo[8] = {100, 400, 900, 400, 500, 100};
    techo[6] = techo[0];
    techo[7] = techo[1];
    setfillstyle(1, BROWN);
    fillpoly(4, techo);
	
	int ventanam[10] = {300, 500, 500, 500, 500, 700, 300, 700};
    ventanam[8] = ventanam[0];
    ventanam[9] = ventanam[1];
    setfillstyle(1, DARKGRAY);
    fillpoly(4, ventanam);
	
	int ventana1[10] = {320, 520, 390, 520, 390, 590, 320, 590};
    ventana1[8] = ventana1[0];
    ventana1[9] = ventana1[1];
    setfillstyle(1, CYAN);
    fillpoly(4, ventana1);
	
	int ventana2[10] = {410, 520, 410, 590, 480, 590, 480, 520};
    ventana2[8] = ventana2[0];
    ventana2[9] = ventana2[1];
    setfillstyle(1, CYAN);
    fillpoly(4, ventana2);
	
	int ventana3[10] = {320, 610, 320, 680, 390, 680, 390, 610};
    ventana3[8] = ventana3[0];
    ventana3[9] = ventana3[1];
    setfillstyle(1, CYAN);
    fillpoly(4, ventana3);
	
	int ventana4[10] = {410, 610, 410, 680, 480, 680, 480, 610};
    ventana4[8] = ventana4[0];
    ventana4[9] = ventana4[1];
    setfillstyle(1, CYAN);
    fillpoly(4, ventana4);
    
    int puerta[10] = {600, 900, 600, 700, 700, 700, 700, 900};
    puerta[8] = puerta[0];
    puerta[9] = puerta[1];
    setfillstyle(1, BROWN);
    fillpoly(4, puerta);
    
    setcolor(DARKGRAY);
    circle(680,810,5);
    getch();
    
    closegraph();

    return 0;
}
