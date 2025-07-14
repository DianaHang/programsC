/* Introduccion a POO
96 - Clase - Inventaario
Programar: la clase inventario */

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std; //Encabezado para usar std (cout/cin)

//----ATRIBUTOS (Datos)-----
typedef struct producto{
	int idProducto;
	char nomProducto[90];
	float precioVenta;
}prod;

typedef enum opciones{
	altaProd = 1,
	imprimeInv,
	salir	
}opc;
//-------------------------

class Inventario{
	//private seccion: protege los atributos
	private:
		prod xproducto;
		FILE *arch;
		char nomRutaInventario[255];
		
	public: //Declaraciones publicas
		/*Constructor: LLeva el mismo nombre de la clase. No devuelve valor (ni siquiera void).
			(Crea/instancia al objeto) */
		Inventario(char nri[255]){
			strcpy(nomRutaInventario, nri); //Asigna lo que el usuario registre
		}
		void leeRegis(){
			cout<<"\nIngresa el ID del producto: ";
			cin>>xproducto.idProducto;
			cout<<"\nIngresa el nombre del producto: ";
			fflush(stdin);
			gets(xproducto.nomProducto);
			cout<<"\nIngresa el precio de venta: ";
			cin>>xproducto.precioVenta;
			guardaRegis();
			
		}
		void imprimeRegis(){
			cout<<"\nID producto: "<<xproducto.idProducto;
			cout<<"\nNombre del producto: "<<xproducto.nomProducto;
			cout<<"\nPrecio venta del producto: "<<xproducto.precioVenta;
		}
		void guardaRegis(){
			arch =fopen(nomRutaInventario, "ab");
			if(arch==NULL){
				cout<<"\nError en apertura de archivo. ";
				getch();
				return;
			}
			fwrite(&xproducto, sizeof(prod),1,arch);
			cout<<"\nRegistro almacenado con exito";
			fclose(arch);
		}
		void imprimeInventario(){
			arch=fopen(nomRutaInventario, "rb");
			if(arch==NULL){
				cout<<"\nError en apertura de archivo. ";
				getch();
				return;
			}
			while(fread(&xproducto, sizeof(prod),1,arch)){
				imprimeRegis();
			}
			fclose(arch);
		}
};

int main(){
	int opcion;
	//Crea al objeto, hace un salto y pasa al constructor
	Inventario cuais("InventarioCuaisFESAcatlan.dat");
	
	do{
		cout<<"\nREGISTRO DE INVENTARIOS.";
		cout<<"\n1.Alta producto.";
		cout<<"\n2.Listar Inventario.";
		cout<<"\n3.Salir";
		cout<<"\nElija opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case altaProd:
				cuais.leeRegis();
				break;
			case imprimeInv:
				cuais.imprimeInventario();
				break;
			case salir:
				cout<<"\nFin de ejecucion";
				getch();
				break;
			default:
				cout<<"\nOpcion Incorrecta";
				getch();
		}
	}while(opcion != salir);

	return 0;
}
