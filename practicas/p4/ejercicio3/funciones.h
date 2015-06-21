#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_CHAR 50

typedef struct{
	char nombre[MAX_CHAR];
	int dni;
	float nota;
}ficha;

ficha * reservaMemoria(int n);
void rellenaVector(ficha * vector, int n);
void imprimeVector(ficha * vector, int n, char * mensaje);

int mayorDni(const void * a, const void * b);
int menorDni(const void * a, const void * b);
int mayorNota(const void * a, const void * b);
int menorNota(const void * a, const void * b);
#endif
