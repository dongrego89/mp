#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_CHAR 50

typedef struct{
	char nombre[MAX_CHAR];
	int dorsal;
	float peso;
	int estatura;
}ficha;

ficha * reservaMemoria(int elementos);
void rellenaVector(ficha * vector, int elementos);
void rellenaElemento(ficha * estructura);
void imprimeVector(ficha * vector, int elementos);
void borraPorCaracter(ficha ** vector, int * elementos, char caracter);
void liberaMemoria(ficha ** vector);
void acondicionaCadena(char * cadena);
#endif
