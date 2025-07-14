// 40 - vector tipo UNION

#include<stdio.h>
#include<conio.h>
#define n 5

//Comenzamos inicializando el dato union
union diferentesTipos{
	char c;
	int e;
	float f;
};

//procedimientos que usamos en main (leeVector, imprimeVector) con sus parametros
void leeVector(union diferentesTipos vect[n], int tipoDato){
	//preguntar si el tipo de dato que quiere el usuario es el 1ero (caracter)
	if(tipoDato ==1){
		//Para visitar cada celda del vector
		for(int i = 0; i<n ; i++){
			fflush(stdin);
			printf("[%d] = ", i);
			scanf("%c", &vect[i].c);
		}
	} else if(tipoDato ==2){ //preguntar si el tipo de dato que quiere el usuario es el 2do (entero)
		for(int i = 0; i<n ; i++){
			printf("[%d] = ", i);
			scanf("%d", &vect[i].e);
		}
	} else { //preguntar si el tipo de dato que quiere el usuario es el 3ero (flotante)
		for(int i = 0; i<n ; i++){
			printf("[%d] = ", i);
			scanf("%f", &vect[i].f);
		}
	}
}

void imprimeVector(union diferentesTipos vect[n], int tipoDato){
	printf("\n");
	
	//preguntar si el tipo de dato que quiere el usuario es el 1ero (caracter)
	if(tipoDato ==1){
		//Para visitar cada celda del vector
		for(int i = 0; i<n ; i++){
			printf("[%c] ", vect[i].c);
		}
	} else if(tipoDato ==2){
		for(int i = 0; i<n ; i++){
			printf("[%d] ", vect[i].e);
		}
	} else {
		for(int i = 0; i<n ; i++){
			printf("[%f] ", vect[i].f);
		}
	}
}


//funcion main para operar la union
int main(){
	//inicializar variables ocupadas
	int tipoDato;
	union diferentesTipos A[n];
	
	//Para finalizar el codigo hasta que el usuario decida
	do{
		printf("\nElija el tipo de vector: \n1. Caracteres \n2. Enteros \n3. Flotantes \n4. Salir \n");
		scanf("%d", &tipoDato);
		printf("\nTipo de dato %d", tipoDato);
		getch();
		
		//switch para analizar el caso que quiera utilizar el usuario
		switch(tipoDato){
			case 1:
				//funcion leeVector que lea la opcion 1 escogida
				leeVector(A, 1);
				//invocar funcion que imprima vector
				imprimeVector(A, 1);
				break;
			case 2:
				leeVector(A, 2);
				imprimeVector(A, 2);
				break;
			case 3:
				leeVector(A, 3);
				imprimeVector(A, 3);
				break;
			case 4:
				printf("\n FIN");
				break;
			
			default:
				printf("\nOpcion incorrecta.");
		}
	} while(tipoDato =! 4); //Para terminar la condicion de do-while
	
	return 1;
}
