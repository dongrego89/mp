#include<stdlib.h>
#include<stdio.h>

#include "funciones.h"

void rellenaVector(float * vector, int elementos){

	int i;

	for(i=0;i<elementos;i++){
		vector[i]=(rand()%1001)/(float)100;
	}
}

void imprimeVector(float * vector,int elementos){
	
	int i;
	
	printf("\nEXAMEN A\tEXAMEN B\n");

	for(i=0;i<elementos;i+=2){
		printf("[A]%02.2f\t\t[B]%02.2f\n",vector[i],vector[i+1]);
	}

	printf("\n");
}


void calculaEstadisticas(float * vector, int elementos,float * mediaA, float * mediaB, float * minA, float * minB, float * maxA, float * maxB){

	int i;

	//Inicializamos las variables
	*mediaA=0;
	*mediaB=0;
	*minA=vector[0];
	*minB=vector[1];
	*maxA=*minA;
	*maxB=*minB;

	for(i=0;i<elementos;i++){
	
		if(i%2==0){//Nota del EXAMEN A
			if(vector[i]>*maxA){
				*maxA=vector[i];
			}
			if(vector[i]<*minA){
				*minA=vector[i];
			}
			*mediaA+=vector[i];		
		}
		else{//Nota del EXAMEN B
			if(vector[i]>*maxB){
				*maxB=vector[i];
			}
			if(vector[i]<*minB){
				*minB=vector[i];
			}
			*mediaB+=vector[i];	

		}
	
	}

	*mediaA=*mediaA/(float)(elementos/2);
	*mediaB=*mediaB/(float)(elementos/2);
}
