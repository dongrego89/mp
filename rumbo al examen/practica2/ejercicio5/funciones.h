#ifndef FUNCIONES_H
#define FUNCIONES_H

char ** leeFrases(int max,char fin, int * numero);
char * concatenaFrases(char ** vector,int numero);

void imprimeFrases(char ** vector,int numero);
void liberaMemoria(char *** vector, int frases);

#endif
