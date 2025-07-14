//95 - Clase-Rectangulo
#include<iostream>     //biblioteca que contiene       printf-->cout        scanf-->cin

using namespace std;
class Rectangulo{
	private:
		float base;
		float altura;
	public:
		//constructor
		Rectangulo(float otroAltura, float otraBase){
			altura=otroAltura;
			base=otraBase;
		}
		void area(){
			cout<<"\nArea: "<<base*altura;
		}
		void perimetro(){
			cout<<"\nPerimetro: "<<2*base+(2*altura);
		}
		void imprimeRect(){
			cout<<"\n\nRectangulo de altura: "<<altura;
			cout<<"\n\nRectangulo de base: "<<base;
			area();
			perimetro();
	}
};
int main(){
	float bas;
	float alt;
	cout<<"\nDar la base del rectangulo: ";
	cin>>bas;
	cout<<"\nDar la altura del rectangulo: ";
	cin>>alt;
	Rectangulo c2(bas, alt);
	c2.imprimeRect();
}
