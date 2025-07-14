//93 - Clase circulo basica
#include<iostream>
#include<conio.h>
using namespace std;

class Circulo{
	private:
		float radio;
	public:
		//constructor
		Circulo(float otroRadio){
			radio=otroRadio;
		}
		void area(){
			cout<<"\nArea: "<<3.1416*radio*radio;
		}
		void perimetro(){
			cout<<"\nPerimetro: "<<3.1416*2*radio;
		}
		void imprime(){
			cout<<"\n\nCirculo de radio: "<<radio;
			area();
			perimetro();
		}
};//No olvidar

//Cliente de la clase
int main(){
	float rad;
	Circulo c1(100);
	c1.imprime();
	getch();
	Circulo c2(10);
	c2.imprime();
	cout<<"\nDar el radio: ";
	cin>>rad;
	Circulo c3(rad);
	c3.imprime(); 
}
