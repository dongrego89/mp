#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include "funciones.h"

ficha * reservaMemoria(int n){
	ficha * puntero=NULL;
	puntero=(ficha *)malloc(sizeof(ficha) * n);
	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}

void rellenaVector(ficha * vector, int n){

	char nombres[10][MAX_CHAR]={{"María"},{"Alberto"},{"Juan"},{"Alvaro"},{"Matias"},{"Rodrigo"},{"Jacinta"},{"German"},{"Eustaquio"},{"Abelardo"}};
	int i;

	for(i=0;i<n;i++){
		strcpy(vector[i].nombre,nombres[rand()%10]);
		vector[i].dni=rand()%1000000000;
		vector[i].nota=rand()%10+1;
	}		

}

void imprimeVector(ficha * vector, int n, char * mensaje){
	
	int i;

	printf("%s",mensaje);

	for(i=0;i<n;i++){
		printf("\n\n\t* * * * * * * * * * * * * * *");
		printf("\n\t* Nombre: %s",vector[i].nombre);
		printf("\n\t* Dni: %.9d",vector[i].dni);
		printf("\n\t* Nota: %2.2f",vector[i].nota);
		printf("\n\t* * * * * * * * * * * * * * *");
	}

	printf("\n");
}


int mayorDni(const void * a,const void * b){
	if(((ficha *)a)->dni>((ficha *)b)->dni){
		return 1;
	}
	else{
		return 0;
	}
}
int menorDni(const void * a,const void * b){
	if(((ficha *)a)->dni<((ficha *)b)->dni){
		return 1;
	}
	else{
		return 0;
	}
}


int mayorNota(const void * a,const void * b){
	if(((ficha *)a)->nota>((ficha *)b)->nota){
		return 1;
	}
	else{
		return 0;
	}
}
int menorNota(const void * a,const void * b){
	if(((ficha *)a)->nota<((ficha *)b)->nota){
		return 1;
	}
	else{
		return 0;
	}
}



