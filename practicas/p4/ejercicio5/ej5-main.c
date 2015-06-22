#include<stdio.h>

#include "ej5.h"

int main(){
	system("clear");

	int terminos,i,coeficiente;
	float x;
	monomio * lista=NULL;
	

	printf("Introduce el número de monomios que tendrá el polinomio: ");
	scanf("%d",&terminos);

	for(i=terminos-1;i>=0;i--){
		printf("Introduce el coeficiente del monomio %d: ",i);
		scanf("%d",&coeficiente);
	
		pushFront(&lista,coeficiente,i);
	}
		
	printf("\nImpresion de polinomio: \n");
	muestraPolinomio(lista);

	printf("\n\n*********************************\n*\tX\t*\tPolin\t*\n*********************************");
	for(x=0;x<5;x+=0.5){
		printf("\n*\t%-2.2f\t*\t %-2.2f\t*",x,evaluaPolinomio(lista,x));	
	}

	printf("\n");
	return 0;
}
