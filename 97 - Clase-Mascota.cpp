//97 - Clase - Mascota

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std; //Encabezado para usar std (cout/cin)

//----ATRIBUTOS (Datos)-----
typedef struct datosMascota{
	int idMascota;
	char nomMascota[90];
	char nomPropietario[150];
	char especie[60];
}masc;

typedef enum opciones{
	altaMasc = 1,
	bajaMasc,
	modifica,
	buscar,
	salir	
}opc;
//-------------------------

class Mascota{
	//private seccion: protege los atributos
	private:
		masc xmascota;
		FILE *arch;
		char nomRutaRegistro[255];
		
	public:
		Mascota(char nomrreg[255]){
			strcpy(nomRutaRegistro, nomrreg); //Asigna lo que el usuario registre
		}
		void leeRegis(){
			cout<<"\nIngresa el ID de la mascota: ";
			cin>>xmascota.idMascota;
			cout<<"\nIngresa el nombre de la mascota: ";
			fflush(stdin);
			gets(xmascota.nomMascota);
			cout<<"\nIngresa la especie: ";
			gets(xmascota.especie);
			cout<<"\nIngresa el nombre del propietario: ";
			gets(xmascota.nomPropietario);
			guardaRegis();
			
		}
		void imprimeRegis(){
			cout<<"\nID mascotita: "<<xmascota.idMascota;
			cout<<"\nNombre de la mascota: "<<xmascota.nomMascota;
			cout<<"\nEspecie: "<<xmascota.especie;
			cout<<"\nPropietario de "<<xmascota.nomMascota<<": "<<xmascota.nomPropietario;
			cout<<"\n";
		}
		
		void guardaRegis(){
			arch =fopen(nomRutaRegistro, "ab");
			if(arch==NULL){
				cout<<"\nError en apertura de archivo. ";
				getch();
				return;
			}
			fwrite(&xmascota, sizeof(masc),1,arch);
			cout<<"\nRegistro almacenado con exito";
			fclose(arch);
		}
		void imprimeRegistro(){
			arch=fopen(nomRutaRegistro, "rb");
			if(arch==NULL){
				cout<<"\nError en apertura de archivo. ";
				getch();
				return;
			}
			while(fread(&xmascota, sizeof(masc),1,arch)){
				imprimeRegis();
			}
			fclose(arch);
		}
		
		
		void bajaRegistro(int id) {
   		 FILE *temporal = fopen("temporal.dat", "wb");
		    arch = fopen(nomRutaRegistro, "rb");
		
		    if (!arch || !temporal) {
		        cout << "\nError al abrir archivos";
		        return;
		    }
		
		    bool encontrado = false;
		    while (fread(&xmascota, sizeof(masc), 1, arch)) {
		        if (xmascota.idMascota != id) {
		            fwrite(&xmascota, sizeof(masc), 1, temporal);
		        } else {
		            encontrado = true;
		        }
		    }
		
		    fclose(arch);
		    fclose(temporal);
		
		    remove(nomRutaRegistro);
		    rename("temporal.dat", nomRutaRegistro);
		
		    if (encontrado)
		        cout << "\nMascota eliminada correctamente.";
		    else
		        cout << "\nID no encontrado.";
		}
		
		void modificaRegistro(int id){
		    FILE *archTemp = fopen("temporal.dat", "wb");
		    arch = fopen(nomRutaRegistro, "rb");
		    if(arch == NULL || archTemp == NULL){
		        cout << "\nError al abrir archivo.";
		        if(arch) fclose(arch);
		        if(archTemp) fclose(archTemp);
		        return;
		    }
		
		    bool encontrado = false;
		    while(fread(&xmascota, sizeof(masc), 1, arch) == 1){
		        if(xmascota.idMascota == id){
		            encontrado = true;
		            cout << "\nRegistro encontrado. Ingrese nuevos datos:\n";
		            cout << "Nombre de la mascota: ";
		            fflush(stdin);
		            gets(xmascota.nomMascota);
		            cout << "Especie: ";
		            gets(xmascota.especie);
		            cout << "Nombre del propietario: ";
		            gets(xmascota.nomPropietario);
		        }
		        fwrite(&xmascota, sizeof(masc), 1, archTemp);
		    }
		    fclose(arch);
		    fclose(archTemp);
		
		    if(encontrado){
		        remove(nomRutaRegistro);
		        rename("temporal.dat", nomRutaRegistro);
		        cout << "\nRegistro modificado exitosamente.";
		    } else {
		        remove("temporal.dat");
		        cout << "\nNo se encontro registro con ID: " << id;
		    }
		}
		
		void buscarRegistro(int id){
		    arch = fopen(nomRutaRegistro, "rb");
		    if(arch == NULL){
		        cout << "\nError al abrir archivo.";
		        return;
		    }
		
		    bool encontrado = false;
		    while(fread(&xmascota, sizeof(masc), 1, arch) == 1){
		        if(xmascota.idMascota == id){
		            encontrado = true;
		            imprimeRegis();
		            break;
		        }
		    }
		    fclose(arch);
		
		    if(!encontrado){
		        cout << "\nNo se encontro registro con ID: " << id;
		    }
		}
		
};

int main(){
	int opcion, id;
	Mascota petland("RegistroMascotasAdoptadas.dat");
	
	do{
		cout<<"\n***MASCOTAS ADOPTADAS***";
		cout<<"\n1.Alta de mascota.";
		cout<<"\n2.Baja de mascota. :c";
		cout<<"\n3.Modificacion.";
		cout<<"\n4.Busqueda.";
		cout<<"\n5.Salir";
		cout<<"\nElija opcion: ";
		cin>>opcion;
		fflush(stdin);
		
		switch(opcion){
			case altaMasc:
				petland.leeRegis();
				petland.imprimeRegistro();
				break;
			case bajaMasc:
				cout<<"\nIngrese ID a dar de baja: ";
				cin>>id;
				fflush(stdin);
				petland.bajaRegistro(id);
				petland.imprimeRegistro();
				break;
			case modifica:
				cout << "\nIngrese ID a modificar: ";
                cin >> id;
                fflush(stdin);
                petland.modificaRegistro(id);
                petland.imprimeRegistro();
				break;
			case buscar:
				cout << "\nIngrese ID a buscar: ";
                cin >> id;
                fflush(stdin);
                petland.buscarRegistro(id);
				break;
			case salir:
				cout<<"\nFin de ejecucion";
				break;
			default:
				cout<<"\nOpcion Incorrecta. Escoja nuevamente por favor.";
		}
	}while(opcion != salir);

	return 0;
}
