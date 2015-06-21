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


void ordenaVector(ficha * vector,int n,int (*funcionOrdenacion)(int a, int b)){

	int i,j,posMin;
	ficha minimo, auxiliar;

	for(i=0;i<n;i++){
		posMin=i;
		minimo=vector[i];
		for(j=i;j<n;j++){
			if((*funcionOrdenacion)(vector[j].dni,minimo.dni)==1){
				minimo=vector[j];
				posMin=j;
			}
		}
		auxiliar=vector[i];
		vector[i]=minimo;
		vector[posMin]=auxiliar;
	}

}


int mayor(int a, int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	}
}
int menor(int a, int b){
	if(a<b){
		return 1;
	}
	else{
		return 0;
	}
}



