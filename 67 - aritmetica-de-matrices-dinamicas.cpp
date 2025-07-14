//65 - Calloc-free

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//Menu para acceder
enum opciones{
	suma = 1,
	salir
};

int row1, row2;
int col1, col2;

//Prototipos para poder invocar antes las funciones void
void stop();
void leeMatriz1(int **);
void imprimeMatriz1(int **);
void leeMatriz2(int **);
void imprimeMatriz2(int **);
void sumaMatriz2(int **, int **, int **);

int main(){
	//Crear liga
	int **mat1, **mat2, **mat3; //Doble apuntador
	enum opciones;
	char ans;
	
		//Lectura matriz 1
		printf("\n -----ARREGLO BIDIMENSIONAL 1----\n");
		printf("\n\tNumero de rengolnes:  ");
		scanf("%d", &row1);
		printf("\n\tNumero de columnass:  ");
		scanf("%d", &col1);
	
		//Crear arreglo con meemoria dinamica 
		mat1 = (int **)calloc(row1, sizeof(int *));
	
		//Crear cajas vacias
		for (int i = 0; i<row1; i++){
			// calloc: (numero de elementos, longitud que necesita)
			mat1[i] = (int *)calloc(col1, sizeof(int));
		}
	
		//Invocar funcion que lea el arreglo
		leeMatriz1(mat1);
		imprimeMatriz1(mat1);
		
		//Lectura matriz 2
		printf("\n -----ARREGLO BIDIMENSIONAL 2----\n");
		printf("\n\tNumero de rengolnes:  ");
		scanf("%d", &row2);
		printf("\n\tNumero de columnass:  ");
		scanf("%d", &col2);
	
		//Crear arreglo con meemoria dinamica 
		mat2 = (int **)calloc(row2, sizeof(int *));
	
		//Crear cajas vacias
		for (int i = 0; i<row2; i++){
			// calloc: (numero de elementos, longitud que necesita)
			mat2[i] = (int *)calloc(col2, sizeof(int));
		}
	
		//Invocar funcion que lea el arreglo
		leeMatriz2(mat2);
		imprimeMatriz2(mat2);
		
		//Tercer arreglo 
		mat3 = (int **)calloc(row2,sizeof(int *));
		for (int i = 0; i<row2; i++){
			// calloc: (numero de elementos, longitud que necesita)
			mat3[i] = (int *)calloc(col2, sizeof(int));
		}
	
		do {
			printf("\n 1. Sumar \n2. Salir\n");
			printf("\nElija una opción: ");
			scanf("%d", &ans);
			
			switch(ans){
				case suma:
					if (row1 == row2 && col1 == col2){
						imprimeMatriz1(mat1);
						printf("\n + \n");
						imprimeMatriz2(mat2);
						printf(" \n = \n");
						sumaMatriz(mat1, mat2, mat3);
						imprimeMatriz2(mat3);
					} else {
						printf("\nLos arreglos no se pueden sumar. El orden de las matrices no coincide.");
						stop();
					}
					break;
					
				case salir: 
					printf("\n Fin de la ejecucio. ");
					stop();
					break;
					
				default: 
					printf("\n Opcion incorrecta. ");
					stop();
					break;
			}
			
		} while (ans!= salir);

	
		//LIBERAR MEMORIA: For para visitar cada caja creada y liberar
		for (int i=0; i<row1; i++){
			free(mat1[i]);
		}
		free(mat1);
		
		for (int i=0; i<row2; i++){
			free(mat2[i]);
		}
		free(mat2);
		
		for (int i=0; i<row2; i++){
			free(mat3[i]);
		}
		free(mat3);
		printf("\nSe ha liberado con exito la memoria reservada para los arreglos.");
}

//Funciones void
void stop(){
	printf("\n Pulse tecla para continuar: ");
	getch();
}

void leeMatriz1(int **mat1){
	for(int i=0; i<row1;i++){
		for(int j=0; j<col1; j++){
			printf("\n [%d][%d]: ", i, j);
			scanf("%d", &mat1[i][j]);
		}
	}
}

void leeMatriz2(int **mat2){
	for(int i=0; i<row2;i++){
		for(int j=0; j<col2; j++){
			printf("\n [%d][%d]: ", i, j);
			scanf("%d", &mat2[i][j]);
		}
	}
}

void imprimeMatriz1(int **mat1){
	printf("\n");
	for(int i=0; i<row1;i++){
		for(int j=0; j<col1; j++){
			printf("[%d]", mat1[i][j]);
		}
	printf("\n");
	}
	stop();
}

void imprimeMatriz2(int **mat2){
	printf("\n");
	for(int i=0; i<row2;i++){
		for(int j=0; j<col2; j++){
			printf("[%d]", mat2[i][j]);
		}
	printf("\n");
	}
	stop();
}

void sumaMatriz2(int **mat1, int **mat2, **int mat3){
	printf("\n");
	for(int i=0; i<row2;i++){
		for(int j=0; j<col2; j++){
			
			mat3[i][j] = mat1[i][j] + mat2[i][j];
		}
	}
}
