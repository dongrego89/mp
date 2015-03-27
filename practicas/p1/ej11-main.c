#include<stdio.h>
#include "ej11.h"

int main(){

system("clear");

double valores[N];
int opcion=0;

while(1){
	opcion=menu();
	switch(opcion){
	case 1:
		printf("\tLectura de valores:\n");
		lectura(valores);
	break;
	case 2:
		printf("\tEscritura de valores:\n");
		escritura(valores);
		fflush(stdin);
		getchar();
		getchar();
		fflush(stdin);
	break;
	case 3:
		printf("\n\tLa media aritmética del vector es %.2lf\n",mediaAritmetica(valores));
		fflush(stdin);
		getchar();
		getchar();
		fflush(stdin);
	break;
	default:
		return 0;
	}
	
}

}
