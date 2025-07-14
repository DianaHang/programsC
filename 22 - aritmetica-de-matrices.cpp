//22 .- sistema aritmetico matrices

#include <stdio.h>
#include <time.h>
#include <conio.h>
#define n 3
#define m 3
#define p 3
#define q 2

enum opciones 
{
	leerArreglo = 1, 
	sumaArreglo,
	restaArreglo,
	multiplicaArreglo,
	transpuestaArreglo,
	inversaArreglo,
	salir
};
void caratula(){
	printf("\nUniversidad Nacional Autonoma de Mexico");
	printf("\nFacultad de Estudios Superiores Acatlan");
	printf("\nMatematicas Aplicadas y Computacion");
	printf("\nProgramacion 2 \t grupo:2251 ");
}
void stop(){
	printf("\npulse tecla para continuar\n");
	fflush(stdin);
	getch();
}

void leerMatrix1(int mat[n][m])
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("Elemento[%d][%d] : ", i,j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void leerMatrix2(int mat[p][q])
{
	printf("\n");
	for(int i=0; i<p; i++)
	{
		for(int j=0; j<q; j++)
		{
			printf("Elemento[%d][%d] : ", i,j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void imprimeMatrix1(int mat[n][m])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("[%d]\t", mat[i][j]);
		}
		printf("\n");
	}
}

void imprimeMatrix2(int mat[p][q])
{
	for(int i=0; i<p; i++)
	{
		for(int j=0; j<q; j++)
		{
			printf("[%d]\t", mat[i][j]);
		}
		printf("\n");
	}
}

void imprimeMatrix3(int mat[n][q])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<q; j++)
		{
			printf("[%d]\t", mat[i][j]);
		}
		printf("\n");
	}
}


void sumaMatrix(int mat1[n][m], int mat2[p][q], int mat3[n][m])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}

void restaMatrix(int mat1[n][m], int mat2[p][q], int mat3[n][m])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			mat3[i][j] = mat1[i][j] - mat2[i][j];
		}
	}
}

void multiplicaMatrix(int mat1[n][m], int mat2[p][q], int mat3[n][q])
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			int suma = 0;
			for(int k=0; k<m; k++)
			{
				suma = suma + mat1[i][k] * mat2[k][j];
			}
			mat3[i][j] = suma;
		}
	}
}

int main(){
	time_t tinic, tfin;
	int opc;
	int A[n][m], B[p][q], C[n][m], D[n][q];
	tinic = time(NULL);
	caratula();
	stop();
	do{
		printf("\n 1.Leer Arreglos");
		printf("\n 2.Sumar Arreglos");
		printf("\n 3.Restar Arreglos");
		printf("\n 4.Multiplicar Arreglos");
		printf("\n 5.Transpuesta de Arreglos");
		printf("\n 6.Inversa Arreglos");
		printf("\n 7.Salir");
		printf("\n\nelegir opcion: ");
		scanf("%d",&opc);
		switch(opc){
			case leerArreglo: 	
				printf("\nLECTURA DE ARREGLOS\n");
				leerMatrix1(A);
				imprimeMatrix1(A);
				leerMatrix2(B);
				imprimeMatrix2(B);
				stop();
				break;
			case sumaArreglo: 
				printf("\nSUMA DE ARREGLOS\n");
				if(n!=p || m != q)
				{
					printf("\nEL tamaño de las matrices es diferente por lo tanto no es posible sumar");
					break;
				}
				sumaMatrix(A, B, C);
				imprimeMatrix1(A);
				printf("\n+\n\n");
				imprimeMatrix2(B);
				printf("\n=\n\n");
				imprimeMatrix1(C);
				stop();
				break;
			case restaArreglo: 
				printf("\nRESTA DE ARREGLOS\n");
				if(n!=p || m != q)
				{
					printf("\nEL tamaño de las matrices es diferente por lo tanto no es posible restar");
					break;
				}
				restaMatrix(A, B, C);
				imprimeMatrix1(A);
				printf("\n-\n\n");
				imprimeMatrix2(B);
				printf("\n=\n\n");
				imprimeMatrix1(C);
				stop();
				break;
			case multiplicaArreglo: 
				printf("\nMULTIPLICACION DE ARREGLOS\n");
				if(m!=p)
				{
					printf("\nEl numero de renglones de A es diferente de la matriz B");
					break;
				}
				multiplicaMatrix(A, B, D);
				imprimeMatrix1(A);
				printf("\n*\n\n");
				imprimeMatrix2(B);
				printf("\n=\n\n");
				imprimeMatrix3(D);
				stop();
				break;
			case transpuestaArreglo: 
				printf("\nTRANSPUESTA DE ARREGLOS\n");
				stop();
				break;
			case inversaArreglo: 
				printf("\nINVERSA DE ARREGLOS\n");
				stop();
				break;
			case salir:
				printf("\n 3.Salir");
				stop();
				break;
			default:
				printf("\nopcion incorrecta vuelva a elegir");
				stop();
		}
		
	}while(opc != salir);
	tfin = time(NULL);
	printf("\nLa hora de entrada es: %s",asctime(localtime(&tinic)));
	printf("\nLa hora de salida es: %s",asctime(localtime(&tfin)));
	printf("\nTiempo de permanencia: %4.2f",difftime(tfin,tinic));
}
