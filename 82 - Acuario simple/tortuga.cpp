// 82 - Tortuga
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>

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

	    void Pinta(){
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
				Pinta();
       		}
       		else{
       			x=nx;
       			y=ny;
       		}
		}
}tortuga;

main(){
	int pantalla=DETECT, modo;
	initgraph(&pantalla, &modo, "\\TC\\BGI");
		
	tortuga tlamachi;
	
	tlamachi.Pinta();
	
	for(int i=0; i<800; i++){
		tlamachi.MueveTortuga(200+i,100);
		delay(20);
	}
	getch();
	tlamachi.volteaIzq();
	tlamachi.Pinta();
	
	
	
	getch();
	
	closegraph();
}
