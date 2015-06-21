#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_TAM 10

void * reservaMemoria(int elementos,char opcion);
void rellenaVectorAleatorio(void * vector,int elementos,char opcion);
void imprimeVector(void * vector,int elementos,char opcion,char * mensaje);

#endif
