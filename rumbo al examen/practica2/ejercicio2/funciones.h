#ifndef FUNCIONES_H
#define FUNCIONES_H

int * reservaMemoria(int elementos);
void rellenaVector(int * vector,int elementos);
void imprimeVector(int * vector,int elementos);
void extraeImpares(int ** vector,int * elementos);
void liberaMemoria(int ** vector);

#endif
