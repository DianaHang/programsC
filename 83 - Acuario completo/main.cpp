// 83 -Acuario
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

typedef struct Tortuga{
	int tam;
	int x;
	int y;
	int vertices[30];
	int cola[30];
	int color;
	int vis;
	int capX;
	int capY;
	int ojoiX;
	int ojoiY;
	int ojodX;
	int ojodY;
	int diam;
	int sentinela;

	public:
		Tortuga(int otroX=200,int otroY=100,int otroTam=120,int otroColor=LIGHTGREEN){
			x=otroX;
			y=otroY;
			tam=otroTam;
			vis=0;
			volteaDer();
			sentinela=0;
			color=otroColor;
			diam=tam/30;
    	}

	    void pintaTortug(){
   			setfillstyle(1,color);
			fillpoly(15,vertices);
			fillpoly(12,cola);
   			setfillstyle(1,GREEN);
   			fillellipse(capX,capY,(tam-tam/3),(tam-tam/2));
   			setfillstyle(1,WHITE);
   			fillellipse(ojoiX,ojoiY,diam,diam);
			fillellipse(ojodX,ojodY,diam,diam);
			vis=1;
		}

		void volteaDer(){
			OcultaTortuga();
			cola[0]=x-tam;
			cola[1]=y+tam/2;
			cola[2]=x-(tam+tam/5);
			cola[3]=y+(tam-tam/5-tam/5);
			cola[4]=x-(tam+tam/5);
			cola[5]=y+(tam-tam/5);
			cola[6]=x-(tam-tam/5);
			cola[7]=y+(tam-tam/20);
			cola[8]=x-tam;
			cola[9]=y+tam;
			cola[10]=x-(tam-tam/5);
			cola[11]=y+(tam+tam/20);
			cola[12]=x-(tam+tam/5);
			cola[13]=y+(tam+tam/5);
			cola[14]=x-(tam+tam/5);
			cola[15]=y+(tam+tam/5+tam/5);
			cola[16]=x-tam;
			cola[17]=y+(tam+tam/2);
			cola[18]=x-(tam-tam/5-tam/5);
			cola[19]=y+(tam+tam/4);
			cola[20]=x-(tam-tam/5-tam/5);
			cola[21]=y+(tam-tam/4);
			cola[22]=cola[0];
			cola[23]=cola[1];
			vertices[0]=x;
			vertices[1]=y;
			vertices[2]=x+tam/10;
			vertices[3]=y+tam/2;
			vertices[4]=x;
			vertices[5]=y+tam;
			vertices[6]=x+tam/10;
			vertices[7]=y+(tam+tam/2);
			vertices[8]=x;
			vertices[9]=y+2*tam;
			vertices[10]=x+tam/5;
			vertices[11]=y+(2*tam-tam/5);
			vertices[12]=x+(tam/5+tam/5);
			vertices[13]=vertices[7];
			vertices[14]=x+tam/5;
			vertices[15]=y+(tam+tam/10);
			vertices[16]=x+(tam/2+tam/10);
			vertices[17]=y+(tam+tam/10);
			vertices[18]=x+(tam/2+tam/5);
			vertices[19]=y+tam;
			vertices[20]=x+(tam/2+tam/10);
			vertices[21]=y+(tam-tam/10);
			vertices[22]=x+tam/5;
			vertices[23]=y+(tam-tam/10);
			vertices[24]=x+(tam/5+tam/5);
			vertices[25]=y+tam/2;
			vertices[26]=x+tam/5;
			vertices[27]=y+tam/5;
			vertices[28]=x;
			vertices[29]=y;
			capX=x-tam/4;
			capY=y+tam;
			ojoiX=vertices[20];
			ojoiY=vertices[21];
			ojodX=vertices[16];
			ojodY=vertices[17];
			sentinela=0;
		}
		void volteaIzq(){
			OcultaTortuga();
			cola[0]=x+tam;
			cola[1]=y+tam/2;
			cola[2]=x+(tam-tam/5-tam/5);
			cola[3]=y+(tam/2+tam/5);
			cola[4]=x+(tam-tam/5-tam/5);
			cola[5]=y+(tam+tam/2-tam/5);
			cola[6]=x+tam;
			cola[7]=y+(tam+tam/2);
			cola[8]=x+(tam+tam/5);
			cola[9]=y+(tam+tam/5+tam/5);
			cola[10]=x+(tam+tam/5);
			cola[11]=y+(tam+tam/5);
			cola[12]=x+(tam-tam/5);
			cola[13]=y+(tam+tam/20);
			cola[14]=x+tam;
			cola[15]=y+tam;
			cola[16]=x+(tam-tam/5);
			cola[17]=y+(tam-tam/20);
			cola[18]=x+(tam+tam/5);
			cola[19]=y+(tam-tam/5);
			cola[20]=x+(tam+tam/5);
			cola[21]=y+(tam/2+tam/10);
			cola[22]=cola[0];
			cola[23]=cola[1];
			vertices[0]=x;
			vertices[1]=y;
			vertices[2]=x-tam/5;
			vertices[3]=y+tam/5;
			vertices[4]=x-(tam/5+tam/5);
			vertices[5]=y+tam/2;
			vertices[6]=x-tam/5;
			vertices[7]=y+(tam-tam/10);
			vertices[8]=x-(tam/2+tam/10);
			vertices[9]=y+(tam-tam/10);
			vertices[10]=x-(tam/2+tam/5);
			vertices[11]=y+(tam);
			vertices[12]=vertices[8];
			vertices[13]=y+(tam+tam/10);
			vertices[14]=x-tam/5;
			vertices[15]=vertices[13];
			vertices[16]=vertices[4];
			vertices[17]=y+(tam+tam/2);
			vertices[18]=x-tam/5;
			vertices[19]=y+(2*tam-tam/5);
			vertices[20]=x;
			vertices[21]=y+2*tam;
			vertices[22]=x-tam/7;
			vertices[23]=y+(tam+tam/2);
			vertices[24]=x;
			vertices[25]=y+tam;
			vertices[26]=x-tam/7;
			vertices[27]=y+tam/2;
			vertices[28]=x;
			vertices[29]=y;
			setfillstyle(1,color);
   			fillpoly(15,vertices);
   			setfillstyle(1,GREEN);
   			capX=x+tam/4;
			capY=y+tam;
			ojoiX=vertices[12];
			ojoiY=vertices[13];
			ojodX=vertices[8];
			ojodY=vertices[9];
			fillellipse(capX,capY,(tam-tam/3),(tam-tam/2));
   			sentinela=1;
		}
		void OcultaTortuga(){
			unsigned int guardaColorActivo=getcolor();
          	if(vis){
          		setcolor (getbkcolor());
          		setfillstyle(1,getbkcolor());
          		fillpoly(12,cola);
  				setfillstyle(1,getbkcolor());
          		fillellipse(capX,capY,(tam-tam/3),(tam-tam/2));
          		setfillstyle(1,getbkcolor());
          		fillpoly(15,vertices);
          		setfillstyle(1,getbkcolor());
          		fillellipse(ojoiX,ojoiY,diam,diam);
          		setfillstyle(1,getbkcolor());
          		fillellipse(ojodX,ojodY,diam,diam);
  				vis=0;
          		setcolor(guardaColorActivo);
          	}
		}	

		void MueveTortuga(int nx,int ny){
			if(vis){
       			OcultaTortuga();
				x=nx;
       			y=ny;
       
		        if(sentinela==0)
			        volteaDer();
       			else
					volteaIzq();
				pintaTortug();
       		}
       		else{
       			x=nx;
       			y=ny;
       		}
		}
		void volteatortuga(){
			if(sentinela==0){
				OcultaTortuga();
				volteaIzq();
				pintaTortug();
			}
			else{
				OcultaTortuga();
				volteaDer();
				pintaTortug();
			}
		}
}mac_tortuga;


int main(){
	int pantalla=DETECT;
	int modo;
	initgraph(&pantalla,&modo,"\\TC\\BGI");
	macpez dory(200,300,150,BLUE), nemo(400,100,80,LIGHTRED), marlin(500,350,100,LIGHTRED);
	macpez pezx(350,600,50,GREEN);
	mac_tortuga tortuguita(700, 250, 50), t1(100, 550, 100);
	
	setbkcolor(CYAN);
	cleardevice();
	
	dory.pintapez();
	nemo.pintapez();
	marlin.pintapez();
	pezx.pintapez();
	
	tortuguita.pintaTortug();
	t1.pintaTortug();
	
	getch();
	for(int i=0;i<1000;i++){
		dory.traslada(200+i,300);
		marlin.traslada(500+i,350);
		nemo.traslada(400+i,100+i);
		pezx.traslada(350+i,600-i);
		tortuguita.MueveTortuga(700+i,250);
		t1.MueveTortuga(100+i,550-i);
		delay(5);
	}
	dory.volteapez();
	marlin.volteapez();
	nemo.volteapez();
	pezx.volteapez();
	tortuguita.volteatortuga();
	t1.volteatortuga();
	
	for(int i=0;i<1000;i++){
		dory.traslada(1200-i,300);
		marlin.traslada(1500-i,350);
		nemo.traslada(1400-i,1100-i);
		pezx.traslada(1350-i,-400+i);
		tortuguita.MueveTortuga(1700-i,250);
		t1.MueveTortuga(1100-i,-450+i);
		delay(5);
	}
	getch();
	
	closegraph();
}
