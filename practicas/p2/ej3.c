#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#include "ej3.h"

struct fichaJugador * reservaMemoria(int n){

	struct fichaJugador * puntero =NULL;

	puntero=(struct fichaJugador *)malloc(sizeof(struct fichaJugador)*n);

	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	return puntero;
}

struct fichaJugador rellenaJugador(int i){
	struct fichaJugador jugador;

	printf("\nIntroduce los datos del jugador %d:\n ",i+1);
	printf("\tNombre: ");
	gets(jugador.nombre);
	printf("\tDorsal: ");
	scanf("%d",&jugador.dorsal);
	printf("\tPeso: ");
	scanf("%f",&jugador.peso);
	printf("\tEstatura: ");
	scanf("%d",&jugador.estatura);
	getchar();
	printf("\n");

	return jugador;
}

void rellenaVector(struct fichaJugador * jugadores,int n){

	int i;

	for(i=0;i<n;i++){
		jugadores[i]=rellenaJugador(i);
	}
}


void imprimeRegistro(struct fichaJugador * jugadores, int n, char * mensaje){
	int i;
	
	printf("%s",mensaje);

	for(i=0;i<n;i++){
		printf("\tNombre: %-27s Dorsal: %2d \n\tPeso: %-25.2fEstatura: %d cm\n\n",jugadores[i].nombre,jugadores[i].dorsal, jugadores[i].peso, jugadores[i].estatura);
	}
}

struct fichaJugador * borraPorLetra(struct fichaJugador * jugadores, int * n,char letra){
	
	struct fichaJugador * puntero;

	puntero=reservaMemoria(*n);	
	
	int contador=0,i;

	for(i=0;i<*n;i++){
		if(strstr(jugadores[i].nombre,&letra)==NULL){
			strcpy(puntero[contador].nombre,jugadores[i].nombre);
			puntero[contador].dorsal=jugadores[i].dorsal;
			puntero[contador].peso=jugadores[i].peso;
			puntero[contador].estatura=jugadores[i].estatura;
			contador+=1;	
		}
	}


	puntero=(struct fichaJugador *)realloc(puntero,contador);
	*n=contador;

		
	free(jugadores);
	
	if(puntero==NULL){ // Error en el realloc o ningun cambio respecto vectores
				
		if(contador==*n){
			return puntero;
		}
		else{
			printf("\nError en realloc\n");
			exit(-1);
		}		
		
	}
	else{ //Si no hubo error en el realloc
		*n=contador;
		return puntero;	
	}
}

