#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<time.h>
#include<conio.h>
#include<locale.h>

#define T 30

void llenarMatriz(int f,int c,float mat[T][T]);
void mostrarMatriz(int f,int c,float mat[T][T]);
void transpuesta(float mat1[T][T],float mat2[T][T],int f, int c);
void sumaMatriz(int f,int c,float mat1[T][T],float mat2[T][T],float mat3[T][T]);
void restarMatriz(int f,int c,float mat1[T][T],float mat2[T][T],float mat3[T][T]);
void llenarMult(float mat1[T][T],float mat2[T][T],int f,int c,int f2,int c2);
void operacionMult(float mat1[T][T],float mat2[T][T],float mat3[T][T],int f,int c2,int c);
void multiplicaEscalar(int f,int c,float escalar,float mat1[T][T],float mat2[T][T]);
void llenarInversa(int f,float mat1[T][T],float mat2[T][T]);
void reduccionRenglones(int f,float mat1[T][T],float mat2[T][T],float pivote,float aux);
void eliminacionGauss(int Dim,float matrz[T][T]);
void mostrarDeter(int n,float matrz[T][T]);

//configuración al idioma español
void ConfiguraIdioma(){
	//Cambia al idioma Español   
	struct lconv *lcPtr;
	setlocale(LC_ALL, "spanish");
	lcPtr = localeconv();

	//Configura cantidades para México
	lcPtr->decimal_point = ".";
	lcPtr->thousands_sep = ",";
	lcPtr->grouping = "3";	
}

int main(){
	
	int opcion,f,c,f2,c2;
	float escalar,A[T][T],B[T][T],C[T][T],aux,pivote;
	time_t TiempoInic, TiempoFinal;
	TiempoInic= time(NULL);
	char nombre[50];
    
	printf("\n Hora de inicio es %s",asctime(localtime(&TiempoInic)));
    printf("\n\nBienvenidos al paquete de aritmetica de Matrices\n\n");
    
	do{
		
	printf("Teclea el numero de la opcion que consideres:\n");
    printf("1.-Sumar dos matrices de dimension NXM\n");
    printf("2.-Restar dos matrices de dimension NXM\n");
    printf("3.-Multiplicar dos matrices de dimension NXM\n");
    printf("4.-Multiplicar una matriz de dimension NXM por un escalar\n");
    printf("5.-Obtener la transpuesta de una matriz de dimension NXM\n");
    printf("6.-Obtener la inversa de una matriz de dimension MXM\n");
    printf("7.-Obtener el determinante de una matriz de dimension MXM\n");
    scanf("%d",&opcion);
    
	if(opcion<1||opcion>7){
		system("cls");
    	printf("\n\nError teclea una opcion de las presentadas\n\n");
	}
	
    }while(opcion<1||opcion>7);
    
    switch(opcion){
    	case 1:
    		printf("\nNumero de filas que contiene la matriz 1:\n");
    		scanf("%d%*c",&f);
    		printf("\nNumero de columnas que contiene la matriz 1:\n");
    		scanf("%d%*c",&c);
    		llenarMatriz(f,c,A);
    		printf("\nNuméro de filas que contiene la matriz 2 a sumar:\n");
    		scanf("%d%*c",&f);
    		printf("\nNumero de columnas que contiene la matriz 2 a sumar:\n");
    		scanf("%d%*c",&c);
    		llenarMatriz(f,c,B);
    		sumaMatriz(f,c,A,B,C);
    		printf("La suma de las matrices es:\n");
    		mostrarMatriz(f,c,C);
    		break;
    	case 2:
    		printf("\nNumero de filas que contiene la matriz 1 :\n");
    		scanf("%d%*c",&f);
    		printf("\nNumero de columnas que contiene la matriz 1:\n");
    		scanf("%d%*c",&c);
    		llenarMatriz(f,c,A);
    		printf("\nNumero de filas que contiene la matriz 2 a restar:\n");
    		scanf("%d%*c",&f);
    		printf("\nNumero de columnas que contiene la matriz 2 a restar:\n");
    		scanf("%d%*c",&c);
    		llenarMatriz(f,c,B);
    		restarMatriz(f,c,A,B,C);
    		printf("La Resta de las matries es:\n");
    		mostrarMatriz(f,c,C);
    		break;
    	case 3:
    		printf("No. de renglones = ?:\n"); 
            scanf("%d%*c",&f);
            printf("No. de columnas = ?:\n");
            scanf("%d%*c",&c);	
    
            system("cls");
            
			do{
            printf("No. de renglones de matriz a multiplicar = ?:\n");
            scanf("%d%*c",&f2);
            printf("No. de columnas de matriz a multiplicar= ?:\n"); 
            scanf("%d%*c",&c2);
            
            if(c!=f2){
            	printf("\nPara multiplicar matrices el numero de columnas de la primer matriz\n");
            	printf("\nDebe coincidir con el numero de filas de la segunda matriz\n");
            	printf("\nVuelve a introducir los datos de la segunda matriz:\n");
			}
			}while(c!=f2);
			
			llenarMult(A,B,f,c,f2,c2);
			operacionMult(A,B,C,f,c2,c);
			printf("\nLa multiplicacion de matrices introducidas es:\n");
            mostrarMatriz(f,c2,C);
            break;
        case 4:
		    
			printf("\nNo. de renglones de matriz a multiplicar por el escalar = ?:\n");
            scanf("%d%*c",&f);
            printf("\nNo. de columnas de matriz a multiplicar por el escalar= ?:\n"); 
            scanf("%d%*c",&c);   
            printf("\nIntroduce el escalar a multiplicar por la matriz:\n");
            scanf("%f%*c",&escalar);
            llenarMatriz(f,c,A);
            multiplicaEscalar(f,c,escalar,A,B);
            printf("\nLa matriz multiplicada por un escalar es:\n");
            mostrarMatriz(f,c,B);
            break;
    	case 5:
    		printf("\nNumero de filas que contiene la matriz:\n");
    		scanf("%d%*c",&f);
    		printf("\nNumero de columnas que contiene la matriz:\n");
    		scanf("%d%*c",&c);
    		llenarMatriz(f,c,A);
    		printf("Matriz introducida por teclado:\n");
    		mostrarMatriz(f,c,A);
    		printf("Iniciando el proceso de obtener la matriz transpuesta:\n");
    		transpuesta(A,B,f,c);
    		printf("Matriz transpuesta obtenida:\n");
    		mostrarMatriz(c,f,B);
    		break;
    	case 6:
    		printf("\nIntroduce el numero de filas y columnas de la matriz a calcular su inversa nxn");
    		scanf("%d%*c",&f);
    		llenarInversa(f,A,B);
    		reduccionRenglones(f,A,B,pivote,aux);
    		printf("\nLa matriz inversa es:\n\n");
    		mostrarMatriz(f,f,B);
    		break;
    	case 7:
    		printf("\nIntroduce el numero de filas y columnas de la matriz a calcular su determinante nxn:\n");
    		scanf("%d%*c",&f);
    		llenarMatriz(f,f,A);
    		eliminacionGauss(f,A);
    		mostrarDeter(f,A);
    		break;
			
    }
    
    
	TiempoFinal=time(NULL);
	//Da formato al tiempo del sistema en formato cadena
	printf("\nHora de salida es %s",asctime(localtime(&TiempoFinal)));
	printf("\n\nResumen: \n");
	printf("\n Hora de inicio: %s",asctime(localtime(&TiempoInic)));
	printf("\n Hora de termino: %s",asctime(localtime(&TiempoFinal)));
	//obtien la diferencia del tiempo final e inicial
	printf("\n Tiempo de permanencia: %4.2f segundos",difftime(TiempoFinal,TiempoInic));
	printf("\n Fin de sesión. Pulse tecla para termínar.  ");
	getch();
	
}

    void llenarMatriz(int f,int c,float mat[T][T]){
    int col,fil;
    printf("teclea los valores componentes de la matriz\n");
	   for(fil=0;fil<f;fil++){
   		for(col=0;col<c;col++){
   			printf("[%d][%d]:",fil,col);
   			scanf("%f%*c",&mat[fil][col]);
   		    printf("\n");	
		   }
	   }
   }
   
   void mostrarMatriz(int f,int c,float mat[T][T]){
   	int col,fil;
	   for(fil=0;fil<f;fil++){
   		for(col=0;col<c;col++){
   			printf("%f\t",mat[fil][col]);
   		    }
   		    printf("\n");
	   }
   	}
   	
   	void transpuesta(float mat1[T][T],float mat2[T][T],int f,int c){
   		int col,fil;
	   for(fil=0;fil<f;fil++){
   		for(col=0;col<c;col++){
   			mat2[col][fil]=mat1[fil][col];
   		    }
	    }
	}
	
	void sumaMatriz(int f,int c,float mat1[T][T],float mat2[T][T],float mat3[T][T]){
		int col,fil;
	   for(fil=0;fil<f;fil++){
   		for(col=0;col<c;col++){
   			mat3[fil][col]=mat1[fil][col]+mat2[fil][col];
   		    }
	   }
	}
	void restarMatriz(int f,int c,float mat1[T][T],float mat2[T][T],float mat3[T][T]){
		int col,fil;
	   for(fil=0;fil<f;fil++){
   		for(col=0;col<c;col++){
   			mat3[fil][col]=mat1[fil][col]-mat2[fil][col];
   		    }
	   }
	}
	
	void llenarMult(float mat1[T][T],float mat2[T][T],int f,int c,int f2,int c2){
	int r,s;
    
	printf("Rellena matriz 1:\n");
    for(r=0;r<f;r++){
     for(s=0;s<c;s++){
       printf("[%d][%d]:",r,s);
       scanf("%f",&mat1[r][s]);	
       }	
    }
    printf("Rellena matriz 2:\n");
    for(r=0;r<f2;r++){
     for(s=0;s<c2;s++){
       printf("[%d][%d]:",r,s);
       scanf("%f",&mat2[r][s]);	
       }			
     }
	}
    void operacionMult(float mat1[T][T],float mat2[T][T],float mat3[T][T],int f,int c2,int c){
    int x,y,acum,cont;
    for(x=0;x<f;x++){
     for(y=0;y<c2;y++){
       acum=0;
        for(cont=0;cont<c;cont++){
          acum=acum+(mat1[x][cont]*mat2[cont][y]);
          mat3[x][y]=acum;
        }
      }	
     }	
    }
    void multiplicaEscalar(int f,int c,float escalar,float mat1[T][T],float mat2[T][T]){
    int x,y;
    for(x=0;x<f;x++){
     for(y=0;y<c;y++){
     	
		 mat2[x][y]=escalar*mat1[x][y];
    		
	  }
	 }
    }
    /*obtener matriz inversa por metodo de Gauss-Jordan*/
    /*llenar matriz a sacar la inversa*/
    void llenarInversa(int f,float mat1[T][T],float mat2[T][T]){
    
	int i,j;
	printf("\nIntroduce los datos componentes de la matriz a convertir en inversa:\n");
    for(i=0;i<f;i++){
    	for(j=0;j<f;j++){
    	printf("\n[%d][%d]:",i,j);
    	scanf("%f%*c",&mat1[i][j]);	
    	mat2[i][j]=0;
		
		if(i==j){
			mat2[i][j]=1;
		}	
	  }
	 }
   }
  void reduccionRenglones(int f,float mat1[T][T],float mat2[T][T],float pivote,float aux){
   		int i,j,k;
   		for(i=0;i<f;i++){
   			pivote=mat1[i][i];
   			//convertir el pivote a 1 y aplicar la operacion sobre toda la fila
   			for(j=0;j<f;j++){
   				mat1[i][j]=mat1[i][j]/pivote;
   				mat2[i][j]=mat2[i][j]/pivote;
			   }
			   
			   for(k=0;k<f;k++){
			   	
			   	if(i!=k){ //no se esta en la diagonal
				  aux=mat1[k][i];
				  for(j=0;j<f;j++){
				  	mat1[k][j]=mat1[k][j]-aux*mat1[i][j];
				  	mat2[k][j]=mat2[k][j]-aux*mat2[i][j];
				  }             
			   }
			   
		   }
	   }
   }
   
   void eliminacionGauss(int Dim,float matrz[T][T]){
	int i,j,k;
	double factor;
	for(k=0;k<Dim-1;k++){
		for(i=k+1;i<Dim;i++){
			factor=matrz[i][k]/matrz[k][k];
			 for(j=k;j<Dim;j++){
			 	matrz[i][j]=matrz[i][j]-factor*matrz[k][j];
			 }
		}
	}
	
}
void mostrarDeter(int n,float matrz[T][T]){
	int i,j;
	float det=1.000;
	for(i=0;i<n;i++){
		det=det*matrz[i][i];
 	}
	printf("El determinante de la matriz es: %f\n",det);
	if(det==0){
		printf("\n\nLa matriz es singular\n");	
	}
}
