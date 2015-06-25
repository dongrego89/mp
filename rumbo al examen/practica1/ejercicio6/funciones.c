#include "funciones.h"

double media(double x, double y){
	return (x+y)/2;
}

double * media_referencia(double x,double y,double * resultado){
	*resultado=(x+y)/2;
}
