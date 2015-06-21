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

//Funciones para la ordenacion	
void ordenaVector(ficha * vector,int n,int (*funcionOrdenacion)(int a, int b));
int mayor(int a, int b);
int menor(int a, int b);
#endif
