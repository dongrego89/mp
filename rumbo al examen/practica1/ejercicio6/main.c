#include<stdio.h>

#include "funciones.h"

int main(){

	system("clear");
	
	double x,y,resultado;

	printf("\nIntroduce los valores para x e y: " );
	scanf("%lf %lf",&x,&y);
	getchar();

	printf("\n\t[*]La media aritmetica de %.3lf y %.3lf es %.3lf",x,y,media(x,y));

	media_referencia(x,y,&resultado);

	printf("\n\t[*]La media aritmetica por referencia de %.3lf y %.3lf es %.3lf\n",x,y,resultado);

	getchar();
	
	system("clear");

	return 0;

}
