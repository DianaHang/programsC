// 82 - Peces
#include <graphics.h>
#include <conio.h>

typedef struct pez{
	int x, y;
	int tam;
	int cuerpopez[16];
	int color;
	int vis;
	int ojox, ojoy;
	int centi;
	
	public:
		pez(int otx, int oty, int ottam, int otcolor){
			x = otx;
			y = oty;
			tam = ottam;
			color = otcolor;
			pezLadoDerecho();
			vis = 0;
		}
		void pezLadoDerecho(){
			//vertice 1
			cuerpopez[0]=x;
			cuerpopez[1]=y;
			//vertice 2
			cuerpopez[2]=x;
			cuerpopez[3]=y+tam;
			//vertice 3
			cuerpopez[4]=x-(tam/2);
			cuerpopez[5]=y+(tam/2);
			//vertice 4
			cuerpopez[6]=x-(tam/2);
			cuerpopez[7]=y+((3*tam)/2);
			//verice 5
			cuerpopez[8]=x;
			cuerpopez[9]=y+tam;
			//vertice 6
			cuerpopez[10]=x;
			cuerpopez[11]=y+(2*tam);
			//vertice 7
			cuerpopez[12]=x+tam;
			cuerpopez[13]=y+tam;
			//vertice 8
			cuerpopez[14]=x;
			cuerpopez[15]=y;
			//ojo
			ojox=x+(tam/2);
			ojoy=y+tam;
			centi=0;
		}
		void pezLadoIzquierdo(){
			//vertice 1
			cuerpopez[0]=x;
			cuerpopez[1]=y;
			//vertice 2
			cuerpopez[2]=x-tam;
			cuerpopez[3]=y+tam;
			//vertice 3
			cuerpopez[4]=x;
			cuerpopez[5]=y+(2*tam);
			//vertice 4
			cuerpopez[6]=x;
			cuerpopez[7]=y+tam;
			//verice 5
			cuerpopez[8]=x+(tam/2);
			cuerpopez[9]=y+((3*tam)/2);
			//vertice 6
			cuerpopez[10]=x+(tam/2);
			cuerpopez[11]=y+(tam/2);
			//vertice 7
			cuerpopez[12]=x;
			cuerpopez[13]=y+tam;
			//vertice 8
			cuerpopez[14]=x;
			cuerpopez[15]=y;
			//ojo
			ojox=x-(tam/2);
			ojoy=y+tam;
			centi=1;
		}
		void pintapez(){
			setcolor(color);
			setfillstyle(1,color);
			fillpoly(8,cuerpopez);
			setfillstyle(1,BLACK);
			fillellipse(ojox,ojoy,10,10);
			vis=1;
		}
		void ocultapez(){
			unsigned int guardacolor=getcolor();
			if(vis){
				setcolor(getbkcolor());
				setfillstyle(1,getbkcolor());
				fillpoly(8,cuerpopez);
				setfillstyle(1,getbkcolor());
				fillellipse(ojox,ojoy,10,10);
				vis=0;
				setcolor(guardacolor);
			}
		}
		void traslada(int nx, int ny){
			if(vis){
				ocultapez();
				x=nx;
				y=ny;
				if(centi==0){
					pezLadoDerecho();
				}
				else{
					pezLadoIzquierdo();
				}
				pintapez();
			}
			else{
				x=nx;
				y=ny;
			}
		}
		void volteapez(){
			if(centi==0){
				ocultapez();
				pezLadoIzquierdo();
				pintapez();
			}
			else{
				ocultapez();
				pezLadoDerecho();
				pintapez();
			}
		}
}macpez;

int main(){
	int pantalla=DETECT;
	int modo;
	initgraph(&pantalla,&modo,"\\TC\\BGI");
	macpez dory(200,300,150,BLUE), nemo(400,100,80,LIGHTRED), marlin(500,350,100,LIGHTRED);
	macpez pezx(150,600,50,GREEN);
	dory.pintapez();
	nemo.pintapez();
	marlin.pintapez();
	pezx.pintapez();
	getch();
	for(int i=0;i<1000;i++){
		dory.traslada(200+i,300);
		marlin.traslada(500+i,350);
		nemo.traslada(400+i,100+i);
		pezx.traslada(150+i,600-i);
		delay(5);
	}
	dory.volteapez();
	marlin.volteapez();
	nemo.volteapez();
	pezx.volteapez();
	for(int i=0;i<1000;i++){
		dory.traslada(1200-i,300);
		marlin.traslada(1500-i,350);
		nemo.traslada(1400-i,1100-i);
		pezx.traslada(1150-i,-400+i);
		delay(5);
	}
	getch();
	
	closegraph();
}
