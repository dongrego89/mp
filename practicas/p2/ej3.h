#ifndef EJ3_H
#define EJ3_H

struct fichaJugador{
	char nombre[50];
	int dorsal;
	float peso;
	int estatura;
};

struct fichaJugador * reservaMemoria(int n);

struct fichaJugador rellenaJugador(int i);

void rellenaVector(struct fichaJugador * jugadores,int n);

void imprimeRegistro(struct fichaJugador * jugadores, int n, char * mensaje);

struct fichaJugador * borraPorLetra(struct fichaJugador * jugadores, int * n,char letra);

#endif
