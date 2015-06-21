#include<math.h>
#include<stdio.h>

#include "funciones.h"

double funcionF(double x){
	return 3*exp(x)-2*x;
}
double funcionG(double x){
	return -x*sin(x)+1.5;
}
double funcionZ(double x){
	return pow(x,3)-2*x+1;
}

void evaluaFuncion(double n,double incremento, double (*funcion)(double x)){
	double i;
	printf("\nEvaluando funcion hasta %2.2lf con incremento de %2.2lf:",n,incremento);
	for(i=0;i<n;i+=incremento){
		printf("\n\tFuncion(%2.2lf)=%2.2lf",i,(*funcion)(i));
	}
	printf("\n");
}
