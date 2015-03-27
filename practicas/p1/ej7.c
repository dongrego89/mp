#include<stdio.h>
#include<stdlib.h>

float * reservaMemoria(int numExamenes){
	float * direccion=NULL;
	direccion=(float *)malloc(sizeof(float)*numExamenes);

	if(direccion==NULL){
		printf("\nError en reserva de memoria");
		exit(-1);
	}
	return direccion;
}

void rellenaExamenes(float * examenes,int numExamenes){

	int i;

	for(i=0;i<numExamenes;i++){
		examenes[i]=drand48()*(10.0 - 0.0);
	}
	
}


void imprimeNotas(char * titulo,float * examenes,int numExamenes){
	int i;

	printf("\n%s",titulo);
	printf("\n\n\t TIPO A\tTIPO B\n");
	for(i=0;i<numExamenes;i++){
		if(i%2==0){
			printf("\n");
		}
		printf("\t%2.2f",examenes[i]);
		
	}
	printf("\n");
}



void calculaMedia(float * examenes, int numExamenes, float * mediaA, float * mediaB){
	int i;

	for(i=0;i<numExamenes;i++){
		if(i%2==0){
			*mediaA+=examenes[i];
		}
		else{
			*mediaB+=examenes[i];
		}
	}
	
	*mediaA=*mediaA/(numExamenes/2);	
	*mediaB=*mediaB/(numExamenes/2);	
	
}
void calculaMax(float * examenes, int numExamenes, float * maxA, float * maxB){

	int i;

	for(i=0;i<numExamenes;i++){
		if(i%2==0){
			if(examenes[i]>*maxA){
				*maxA=examenes[i];
			}
		}
		else{
			if(examenes[i]>*maxB){
				*maxB=examenes[i];
			}
		}
	}

}
void calculaMin(float * examenes, int numExamenes, float * minA, float * minB){

	int i;

	for(i=0;i<numExamenes;i++){
		if(i%2==0){
			if(examenes[i]<*minA){
				*minA=examenes[i];
			}
		}
		else{
			if(examenes[i]<*minB){
				*minB=examenes[i];
			}
		}
	}

}

