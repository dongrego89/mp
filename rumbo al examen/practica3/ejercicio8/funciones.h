#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_T 100
#define MAX_A 150

typedef struct{

	char titulo[MAX_T];
	char autor[MAX_A];
	float precio;
	int unidades;

}libro;

int existeLibro(char * nombre,char * cadena);
void nuevoLibro(char * nombre,libro informacion);
int cuentaLibros(char * nombre);
libro * reservaMemoria(int elementos);
void rellenaVector(char * nombre,libro * vector,int tamano);
void imprimeStock(libro * vector,int tamano);
void guardaBinario(libro * vector,int tamano, char * nombre);

#endif
