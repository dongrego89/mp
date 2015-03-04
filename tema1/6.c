#include <stdio.h>
#include "6.h"

double media(double x, double y){
	return (x+y)/2;
}

void media_referencia(double x, double y, double * retorno){
	*retorno=(x+y)/2;
}
