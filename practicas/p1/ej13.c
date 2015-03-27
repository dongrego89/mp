#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej13.h"

void inscribeAlumnos(struct alumno vector[],int nAlumnos){
	int i;
		getchar();
		fflush(stdin);	
	
	for(i=0;i<nAlumnos;i++){
		printf("\nAlumno %d\n",i+1);
		printf("\tIntroduce el nombre: ");
		fgets(vector[i].nombre,50,stdin);
		vector[i].nombre[strlen(vector[i].nombre)-1]='\0';
		printf("\tIntroduce los apellidos: ");
		fgets(vector[i].apellidos,150,stdin);
		vector[i].apellidos[strlen(vector[i].apellidos)-1]='\0';
		printf("\tIntroduce el dni: ");
		scanf("%d",&vector[i].dni);
		vector[i].companero=NULL;

		getchar();
		fflush(stdin);
	}
}


void emparejaAlumnos(struct alumno vector[],int nAlumnos){
	int i, aleatorio;
	for(i=0;i<nAlumnos;i++){
		if(vector[i].companero==NULL){
			do{	
				do{
					aleatorio=rand()%nAlumnos;//Generar nuevo aleatorio mientras el compañero no este vacio o el aleatorio sea el elemento actual
				}while(vector[aleatorio].companero!=NULL);
			}while(aleatorio==i);

			vector[i].companero=&vector[aleatorio];
			vector[aleatorio].companero=&vector[i];
		}
	}
}


void imprimeParejas(struct alumno vector[],int nAlumnos){
	int i;
	printf("\n");
	for(i=0;i<nAlumnos;i++){
		printf("%s %s [%d] && ",vector[i].nombre,vector[i].apellidos,vector[i].dni);
		printf("%s %s [%d] \n",vector[i].companero->nombre,vector[i].companero->apellidos,vector[i].companero->dni);
	}
}
