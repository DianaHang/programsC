//17- While: Se puede ejecutar o no, si la condicion se cumple o no

#include <stdio.h>

int main(){
    char nombre [80];
    int edad;
    int cuenta = 1;
    
    printf("\nIngresa un nombre: ");
    fflush(stdin);
    gets(nombre);
    
    printf("\nDigita tu edad:  ");
    scanf("%d", &edad);
    
    while(cuenta <= edad){
            printf("\n%d - %s", cuenta, nombre);
            cuenta ++; //aqui la instruccion de incremento va al final
            }
    
return 0;
}
