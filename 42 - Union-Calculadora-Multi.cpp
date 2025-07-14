// 42 - Union-Calculadora-multiplicaciones

#include <stdio.h>
#include <conio.h>
typedef int Luis_Miguel;
typedef float Juan_Gabriel;
typedef double Jose_Jose;
typedef char Vicente_Fernandez;

enum opciones{
	multientero=1,
	multifloat,
	multidouble,
	multichar,
	salir
};

typedef union tipos{
	Luis_Miguel i;
	Juan_Gabriel f;
	Jose_Jose dd;
	Vicente_Fernandez c;
}unidoz;

void multipliDoubles(unidoz &, unidoz &, unidoz &);
void multipliCaracteres(unidoz *, unidoz *, unidoz *);

void multipliEnteros(unidoz &a, unidoz &b, unidoz &c){
	c.i=a.i * b.i;
}

void multipliFlotantes(unidoz *a, unidoz *b, unidoz *c){
	c->f=a->f * b->f;
}

Luis_Miguel main()
{
	unidoz p, q, r;
	Luis_Miguel opc;
	
	
	do{
		printf("\n1.Suma de enteros");
		printf("\n2.Suma de flotantes");
		printf("\n3.Suma de doubles");
		printf("\n4.Suma de caracteres");
		printf("\n5.Salir");
		printf("\nElija una opcion [1,2,3,4,5]-->");
		scanf("%d",&opc);
		
		switch(opc){
			case multientero:
				printf("\nDar un entero p: ");
				scanf("%d",&p.i);
				printf("\nDar un entero q: ");
				scanf("%d",&q.i);
				multipliEnteros(p, q, r);
				printf("\n%d * %d = %d",p.i,q.i,r.i);
				getch();
				break;
			case multifloat:
				printf("\nDar un flotante p: ");
				scanf("%f",&p.f);
				printf("\nDar un flotante q: ");
				scanf("%f",&q.f);
				multipliFlotantes(&p, &q, &r);
				printf("\n%.2f * %.2f = %.2f",p.f,q.f,r.f);
				getch();
				break;
			case multidouble:
				printf("\nDar un double p: ");
				scanf("%lf",&p.dd);
				printf("\nDar un double q: ");
				scanf("%lf",&q.dd);
				multipliDoubles(p, q, r);
				printf("\n%.2lf * %.2lf = %.2lf",p.dd,q.dd,r.dd);
				getch();
				break;
			case multichar:
				printf("\nDar un caracter p: ");
				fflush(stdin);
				scanf("%c",&p.c);
				printf("\nDar entero: ");
				fflush(stdin);
				scanf("%d",&q.i);
				multipliCaracteres(&p, &q, &r);
				printf("\n%c * %c = %c",p.c,q.i,r.c);
				getch();
				break;
			case salir:
				printf("Chao");
				break;
			default:
				printf("\nOpcion incorrecta");
				getch();
		}
		
		
	}while(opc!=salir);
}

void multipliDoubles(unidoz &a, unidoz &b, unidoz &c){
	c.dd=a.dd * b.dd;
}

void multipliCaracteres(unidoz *a, unidoz *b, unidoz *c){
	c->c=a->c * b->i;
}
