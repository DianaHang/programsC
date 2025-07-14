//20-area- perimetro del circulo- procedimientos y funciones

#include <stdio.h>
#include <time.h>
#define pi 3.1416
float perimetroCirculo(float); //prototipo: sirve para avisar al programa que una funcion esta fuera del main

enum circulo {
    area = 1,
    perimetro,
    salir
};

void caratula(){
    printf("\nUniversidad Nacional Autonoma de Mexico");
    printf("\nFacultad de Estudios Superiores Acatlan");
    printf("\nMatematicas Aplicadas y Computacion");
    printf("\n Programacion 2 \t grupo: 2251");
}

void stop(){
    char x;
    
    printf("\npulse tecla para continuar\n");
    fflush(stdin);
    scanf("%c", &x);
}

//pi * radio * radio
//Declarando la función área:
float areaCirculo(float radio){
                       //parametro formal   //Paso de parametros por valor
    return(pi*radio*radio);
}

int main(){
    time_t tinic, tfin;
    int opc;
    float rad;
    
    tinic = time(NULL);
    
    caratula();
    stop();
    do {
        printf("\n1. Calculo del area del circulo"
               "\n2. Calculo del perimetro del circulo"
               "\n3. Salir"
               "\nElegir opcion"
        );
        scanf("%d", &opc);
        
        switch(opc){
            case area:
               printf("\n1. Calculo del area del circulo");
               printf("\nIngresa el valor del radio: ");
               scanf("%f", &rad);
                           //parametro real
               printf("\nEl area del circulo de radio %.2f es: %f", rad, areaCirculo(rad)); //funcion invocada
               stop();
               break;
            case perimetro:
               printf("\n2. Calculo del perimetro del circulo");
               printf("\nIngresa el valor del radio: ");
               scanf("%f", &rad);
                           //parametro real
               printf("\nEl perimetro del circulo de radio %.2f es: %f", rad, perimetroCirculo(rad));
               stop();
               break;
            case salir:
               printf("\n3. Salir");
               stop();
               break;
            default:
               printf("\nOpcion incorrecta, vuelva a elegir.");
               stop();
        }
        
        
    } while (opc != salir);
    
    //para mostrar los datos de tiempo de permanencia, entrada y salida.
    tfin = time(NULL);
    printf("\nHora de entrada es: %s", asctime(localtime(&tinic)));
    printf("\nHora de salida es: %s", asctime(localtime(&tfin)));
    printf("\nTiempo de permanencia: %4.2f", difftime(tfin, tinic));
    
} //Fin del main

//Funcion perimetro
float perimetroCirculo(float radio){
    return(pi*2*radio);
}
