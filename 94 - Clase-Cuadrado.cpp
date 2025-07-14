//94 - Clase Cuadrado
#include<iostream>     //biblioteca que contiene       printf-->cout        scanf-->cin

using namespace std;

class Cuadrado{
	private:
		float lado;
	public:
		//constructor
		Cuadrado(float otroLado){
			lado=otroLado;
		}
		void area(){
			cout<<"\nArea: "<<lado*lado;
		}
		void perimetro(){
			cout<<"\nPerimetro: "<<4*lado;
		}
		void imprime(){
			cout<<"\n\nCuadrado de lado: "<<lado;
			area();
			perimetro();
		}
};//No olvidar
//Cliente de la clase
int main(){
	float lad;
	cout<<"\nDar el lado del cuadrado: ";
	cin>>lad;
	Cuadrado c1(lad);
	c1.imprime(); 

}
