// 25 - struct-alumno
#include <stdio.h>
struct estudiante {
	int idEstudiante;  // 4 bytes
	char nombre[80];  // 80 bytes
	float promedio;  // 4 bytes
};

int main(){
	struct estudiante x;
	printf("\Identificador del estudiante: ");
	scanf("%d",&x.idEstudiante);
	
	printf("\Nombre: ");
	fflush(stdin);
	gets(x.nombre);
	
	printf("\Promedio: ");
	scanf("%f",&x.promedio);
	
	printf("\nIdentificador: %d"
		   "\nNombre: %s"
		   "\nPromedio: %.2f",x.idEstudiante,x.nombre,x.promedio);
	return 0;
}
