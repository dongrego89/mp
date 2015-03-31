#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ejercicio3.h"

struct estudiante * reservaMemoria(int n){
	struct estudiante * puntero=NULL;

	puntero=(struct estudiante *)malloc(sizeof(struct estudiante)*n);
	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}	
	return puntero;
}

void rellenaVector(struct estudiante * v, int n){
	int i;
	
	for(i=0;i<n;i++){
		rellenaEstudiante(v+i);
	}
}

void rellenaEstudiante(struct estudiante * e){
	getchar();
	printf("\n[+] Nuevo Estudiante :::::::::::::::::::::::::::::::::::::::::\n");
	printf("\n\tNombre: ");
	gets(e->nombre);
	printf("\tDni: ");
	scanf("%d",&(e->dni));
	printf("\tNota: ");
	scanf("%f",&(e->nota));
	printf("\n");
}

void imprimeVector(struct estudiante *v, int n){
	int i;

	printf("\n[*] Estudiantes Registrados :::::::::::::::::::::::::::::::::::\n");

	for(i=0;i<n;i++){
		printf("\n\t %-25s %8d %2.2f",v[i].nombre,v[i].dni,v[i].nota);
	}	
	printf("\n\n");
}

float calculaMediaNombre(struct estudiante * v, int n){
	int i;
	float sumatorio=0;

	for(i=0;i<n;i++){
		sumatorio=sumatorio+(float)strlen(v[i].nombre);
	}

	return sumatorio/(float)n;
}


void liberaMemoria(struct estudiante ** v){
	free(*v);
	*v=NULL;
}

