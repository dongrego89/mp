#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ej3.h"

int main(){

	system("clear");

	int nJugadores;
	struct fichaJugador * jugadores;
	char letra;

	printf("Introduce el numero de jugadores a registrar: ");
	scanf("%d",&nJugadores);
	getchar();

	jugadores=reservaMemoria(nJugadores);
	
	rellenaVector(jugadores,nJugadores);
	imprimeRegistro(jugadores,nJugadores,"\nRegistro de Jugadores\n");	
	
	printf("Introduce la letra por la que borrar a los jugadores: ");
	scanf("%c",&letra);
	getchar();

	jugadores=borraPorLetra(jugadores, &nJugadores, letra);
	imprimeRegistro(jugadores,nJugadores,"\nRegistro de Jugadores tras borrar\n");
	
	free(jugadores);
	jugadores=NULL;

return 0;
}
