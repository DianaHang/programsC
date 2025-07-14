//Pollitos animados
#include <graphics.h>
#include <conio.h>
#include <dos.h>

typedef struct animaEllipse {
	int x, y, radiusx, radiusy;
	int vis = 0;
	int fill, color;

	public:
	animaEllipse(int x1, int y1, int radiusx1, int radiusy1) {
		x = x1;
		y = y1;
		radiusx = radiusx1;
		radiusy = radiusy1;
		vis = 0;
	}

	void paint(int fillStyle, int fillColor) {
		fill = fillStyle;
		color = fillColor;
		setfillstyle(fill, color);
		fillellipse(x, y, radiusx, radiusy);
		vis = 1;
	}

	void hide() {
		if (vis == 1) {
			setfillstyle(SOLID_FILL, getbkcolor());
			fillellipse(x, y, radiusx, radiusy);
			vis = 0;
		}
	}

	void move(int newx, int newy) {
		bool prevVis = vis; //Bandera para guardar visibilidad
		if (vis == 1) hide();
		x = newx;
		y = newy;
		if (prevVis) paint(fill, color);
	}
} ellip;

typedef struct animaTriangle {
	int dot[8];
	int vis;
	int fill, color;

	public:
	animaTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		dot[0] = x1; dot[1] = y1;
		dot[2] = x2; dot[3] = y2;
		dot[4] = x3; dot[5] = y3;
		dot[6] = x1; dot[7] = y1;
		vis = 0;
	}

	void paint(int fillStyle, int fillColor) {
		fill = fillStyle;
		color = fillColor;
		setfillstyle(fill, color);
		fillpoly(4, dot);
		vis = 1;
	}

	void hide() {
		if (vis == 1) {
			setfillstyle(SOLID_FILL, getbkcolor());
			fillpoly(4, dot);
			vis = 0;
		}
	}

	void move(int dx, int dy) {
		bool prevVis = vis;
		if (vis) hide();
		for (int i = 0; i < 8; i += 2) {
			dot[i] += dx;
			dot[i + 1] += dy;
		}
		dot[6] = dot[0];
		dot[7] = dot[1];
		if (prevVis) paint(fill, color);
	}
} trian;

typedef struct animaLeftLeg{
	int vis, color;
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	
	public:
		animaLeftLeg(int lx1, int ly1, int lx2, int ly2, int lx3, int ly3, int lx4, int ly4, int lx5, int ly5, int lx6, int ly6){
					x1 = lx1; y1 = ly1;
					x2 = lx2; y2 = ly2;
					x3 = lx3; y3 = ly3;
					x4 = lx4; y4 = ly4;
					x5 = lx5; y5 = ly5;
					x6 = lx6; y6 = ly6;
					vis = 0;
				  }
	
	void paint(int c){
		color = c;
		setcolor(color);
		line(x1, y1, x2, y2);
		line(x3, y3, x4, y4);
		line(x5, y5, x6, y6);
		vis = 1;
	}
	
	void hide(){
		if (vis==1){
			setcolor(getbkcolor());
			line(x1, y1, x2, y2);
			line(x3, y3, x4, y4);
			line(x5, y5, x6, y6);
			vis = 0;
		}
	}
	
	void move(int newx, int newy){
		bool prevVis = vis;
		if (vis==1){
			hide();
		} 
		x1 = newx;
		y1 = newy;
		x2 = newx;
		y2 = newy;
		x3 = newx;
		y3 = newy;
		x4 = newx;
		y4 = newy;
		x5 = newx;
		y5 = newy;
		x6 = newx;
		y6 = newy;
		if (prevVis){
			paint(color);
		}
	}
}left;

typedef struct animaRightLeg{
	int vis, color;
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
	
	public:
		animaRightLeg(int rx1, int ry1, int rx2, int ry2, int rx3, int ry3, int rx4, int ry4, int rx5, int ry5, int rx6, int ry6){
					x1 = rx1; y1 = ry1;
					x2 = rx2; y2 = ry2;
					x3 = rx3; y3 = ry3;
					x4 = rx4; y4 = ry4;
					x5 = rx5; y5 = ry5;
					x6 = rx6; y6 = ry6;
					vis = 0;
				  }
	
	void paint(int c){
		color = c;
		setcolor(color);
		line(x1, y1, x2, y2);
		line(x3, y3, x4, y4);
		line(x5, y5, x6, y6);
		vis = 1;
	}
	
	void hide(){
		if (vis==1){
			setcolor(getbkcolor());
			line(x1, y1, x2, y2);
			line(x3, y3, x4, y4);
			line(x5, y5, x6, y6);
			vis = 0;
		}
	}
	
	void move(int newx, int newy){
		bool prevVis = vis;
		if (vis==1){
			hide();
		}
		x1 = newx;
		y1 = newy;
		x2 = newx;
		y2 = newy;
		x3 = newx;
		y3 = newy;
		x4 = newx;
		y4 = newy;
		x5 = newx;
		y5 = newy;
		x6 = newx;
		y6 = newy;
		if (prevVis){
			paint(color);
		}
	}
}right;

int main(){
	ellip head1(300, 260, 80, 80);
	ellip eye1(340, 240, 15, 15);
	ellip shine1(345, 240, 6, 6);
	ellip body1(200, 400, 120, 90);
	trian beak1(370, 240, 370, 300, 420, 270);
	trian wing1(220, 350, 180, 440, 260, 420);
	trian tail1(110, 350, 30, 330, 85, 420);
	left legl1(220, 470, 220, 570, 220, 550, 200, 570, 220, 550, 240, 570);
	right legr1(260, 470, 260, 570, 260, 550, 240, 570, 260, 550, 280, 570);
	
	int driver = DETECT, mode;
	
	initgraph(&driver, &mode, "\\TC\\BGI");
	
	legl1.paint(LIGHTRED);
	legr1.paint(LIGHTRED);
	tail1.paint(5, YELLOW);
	body1.paint(2, YELLOW);
	head1.paint(2, YELLOW);
	eye1.paint(1, BLACK);
	shine1.paint(1, WHITE);
	beak1.paint(2, LIGHTRED);
	wing1.paint(4, YELLOW);
	getch();
	
	//Invocar el traslado simultaneo
	for (int i=0; i<800; i++){
		//legs1.move();
		head1.move(300+i, 260);
		eye1.move(340+i, 240);
		shine1.move(345, 240);
		body1.move(200+i, 400);
		beak1.move(370+i, 240);
		wing1.move(220+i, 350);
		tail1.move(110+i, 350);
		legl1.move(220+i, 470);
		legr1.move(260+i, 470);
		delay(5);
	}
	
	closegraph();
	
	return 1;
}
