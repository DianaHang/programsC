//21-paso_valor_referencia_direccion
//Los datos prevalecen en la función que invoca.

#include <stdio.h>

void funcPasoPorValor(int x){ 
	x++;
}

void funcPasoPorReferencia(int &x){
	x++;
}

void funcPasoPorDireccion(int *x){ //puntero * apunta a la direccion de la otra variable
	*x = *x+1;
}

int main(){
	int MAC_valor = 100;
	printf("\nMAC_valor = %d", MAC_valor);
	
	//POR VALOR: Se crean variables extras y luego desaparecen valores
	funcPasoPorValor(MAC_valor); //esta función manda el valor almacenado a otra variable y borra de la RAM el anterior
	printf("\nDespues de regresar de funcPasoPorValor, MAC_valor = %d", MAC_valor);
	
	//POR REFERENCIA
	funcPasoPorReferencia(MAC_valor); //esta función no crea otra variable, hace una referencia (&) al mismo espacio de memoria la reconoce con su valor, como si fuera su apodo. Sale de ahí y el cambio se efectua.
	printf("\nDespues de regresar de funcPasoPorReferencia, MAC_valor = %d", MAC_valor);
	
	//POR DIRECCION
	funcPasoPorDireccion(&MAC_valor); //como es un puntero, se usa & para darle la direccion. esta función no crea otra variable, hace una referencia (&) al mismo espacio de memoria la reconoce con su valor, como si fuera su apodo. Sale de ahí y el cambio se efectua.
	printf("\nDespues de regresar de funcPasoPorDireccion, MAC_valor = %d", MAC_valor);
	
	return -8;
}
