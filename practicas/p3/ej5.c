#include<stdio.h>

#include "ej5.h"


float aproximaPI(int terminos){

	float aproximacion=0;

	aproximacion=(float)4/(float)((2*terminos)-1);

	if(terminos>1){
		if(terminos%2==0){
			return -aproximacion+aproximaPI(terminos-1);
		}
		else{
			return aproximacion+aproximaPI(terminos-1);
		}
	}
	else{
		return aproximacion;
	}

}
