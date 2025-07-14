//13. For - iteracion de nombre

#include <stdio.h>

int main () {
    char nombre[80], respuesta; //[] tamanio maximo del char
    int edad, cuenta;
    
    do {
        printf("\nNombre: ");
        fflush(stdin); //para limpiar el buffer si tiene guardados valores
        gets(nombre); //para obtener y almacenar el nombre que ingreso el usuario
        printf("\nEdad (anios cumplidos): ");
        scanf("%d", &edad);
        
        for (int cuenta = 1; cuenta <= edad; cuenta ++){ //for(inicio; condicion repetitiva, incremento)
            printf("\n%d - %s", cuenta, nombre); //%s se refiere a una cadena
        }
            
        printf("\nDeseas continuar con la ejecucion? [S -> si o cualquier tecla en caso contrario: ");
        
        fflush(stdin);
        scanf("%c", respuesta);
        
    } while(respuesta == 's' || respuesta == 'S');

    
return 0;
}
