//65 - Calloc-free

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int row;
int col;

//Prototipos para poder invocar antes las funciones void
void stop();
void leeMatriz(int **);
void imprimeMatriz(int **);

int main(){
	//Crear liga
	int **mat; //Doble apuntador
	
	//Lectura 
	printf("\n\tNumero de rengolnes:  ");
	scanf("%d", &row);
	printf("\n\tNumero de columnass:  ");
	scanf("%d", &col);
	
	//Crear arreglo con meemoria dinamica
	mat = (int **)calloc(row, sizeof(int *));
	
	//Crear cajas vacias
	for (int i = 0; i<row; i++){
		// calloc: (numero de elementos, longitud que necesita)
		mat[i] = (int *)calloc(col, sizeof(int));
	}
	
	//Invocar funcion que lea el arreglo
	leeMatriz(mat);
	imprimeMatriz(mat);
	
	//LIBERAR MEMORIA: For para visitar cada caja creada y liberar
	for (int i=0; i<row; i++){
		free(mat[i]);
	}
	free(mat);
}

//Funciones void
void stop(){
	printf("\n [Pulse tecla para continuar.]");
	getch();
}

void leeMatriz(int **mat){
	for(int i=0; i<row;i++){
		for(int j=0; j<col; j++){
			printf("\n [%d][%d]: ", i, j);
			scanf("%d", &mat[i][j]);
		}
	}
}

void imprimeMatriz(int **mat){
	for(int i=0; i<row;i++){
		for(int j=0; j<col; j++){
			printf("[%d]", mat[i][j]);
		}
	printf("\n");
	}
	stop();
}
