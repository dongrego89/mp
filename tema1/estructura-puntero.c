//Estructuras y punteros, calculando puntos de una linea por coordenadas
#include<stdio.h>

typedef struct{
	float x;
	float y;
}punto;

typedef struct{
	punto inicio;
	punto final;
}recta;

void leerPunto(punto * p);
void imprimirPunto(punto * p);
void mediaPunto(recta * linea, punto * centro);
void divisionCuatro(recta * linea, punto * p1, punto * p2);

int main(){

system("clear");

recta linea;
punto centro,p1,p2;

printf("Introduce los valores para el inicio de la linea: \n \t");
leerPunto(&linea.inicio);
printf("Introduce los valores para el fin de la linea: \n \t");
leerPunto(&linea.final);

printf("\n\nLa linea se ha situado en las coordenadas:");
imprimirPunto(&linea.inicio);
imprimirPunto(&linea.final);

mediaPunto(&linea,&centro);
printf("\n\nEl punto central de la linea es:");
imprimirPunto(&centro);

divisionCuatro(&linea,&p1,&p2);
printf("\n\nLos puntos que dividen la linea en 4 son:");
imprimirPunto(&p1);
imprimirPunto(&centro);
imprimirPunto(&p2);

printf("\n");

return 0;
}

void leerPunto(punto * p){
	scanf("%f %f",&p->x,&p->y);
}

void imprimirPunto(punto *p){
	printf("\n\t Coordenadas(%.2f,%.2f)",p->x,p->y);
}

void mediaPunto(recta * linea, punto * centro){
	centro->x=(linea->inicio.x + linea->final.x) / 2;
	centro->y=(linea->inicio.y + linea->final.y) / 2;
}

void divisionCuatro(recta * linea, punto * p1, punto * p2){
	punto centro;
	recta aux;
	
	mediaPunto(linea,&centro);

	aux.inicio.x=linea->inicio.x;
	aux.inicio.y=linea->inicio.y;
	aux.final.x=centro.x;
	aux.final.y=centro.y;
	
	mediaPunto(&aux,p1);

	aux.final.x=linea->final.x;
	aux.final.y=linea->final.y;
	aux.inicio.x=centro.x;
	aux.inicio.y=centro.y;
	
	mediaPunto(&aux,p2);
	
}
