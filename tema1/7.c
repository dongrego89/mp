#include <stdio.h>
#include <stdlib.h>

#include "7.h"

void imprimeNotas(float * examenes){
	int i,j;
	for(i=0;i<50;i++,j++){
		if(j%5==0){
			printf("\n");
		}
		printf(" %.2f ",*(examenes+i));
	}
	printf("\n");
}

void calculaEstadisticas(float * examenes, float * media_a, float * maxima_a, float * minima_a, float * media_b, float * maxima_b, float * minima_b){

	media(examenes,media_a,media_b);
	maxima(examenes,maxima_a,maxima_b);
	minima(examenes,minima_a,minima_b);

}

void media(float * examenes, float * media_a, float * media_b){

	int i;
	for(i=0;i<50;i++){
		if(i%2==0){ // Examen A 
			*media_a+=examenes[i];
		}
		else{ // Examen B
			*media_b+=examenes[i];
		}
	}

	*media_a=*media_a/25;
	*media_b=*media_b/25;

}
void maxima(float * examenes, float * maxima_a, float * maxima_b){
	int i;
	for(i=0;i<50;i++){
		if(i%2==0){ // Examen A
			if(*maxima_a<*(examenes+i)){
				*maxima_a=*(examenes+i);
			}
		}
		else{ // Examen B
			if(*maxima_b<*(examenes+i)){
				*maxima_b=*(examenes+i);
			}
		}
	}
}
void minima(float * examenes, float * minima_a, float * minima_b){
	int i;
	for(i=0;i<50;i++){
		if(i%2==0){ // Examen A
			if(*minima_a>*(examenes+i)){
				*minima_a=*(examenes+i);
			}
		}
		else{ // Examen B
			if(*minima_b>*(examenes+i)){
				*minima_b=*(examenes+i);
			}
		}
	}

}

void rellenaNotas(float * examenes){

	int i;

	for(i=0;i<50;i++){ // Recorremos el vector 
		//*(examenes+i)=drand48() * (10.00 - 0.00);
		*(examenes+i)=rand()%10;
	}

}
