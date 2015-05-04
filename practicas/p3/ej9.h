#ifndef EJ9_H
#define EJ9_H

#define MAX_FILENAME 250
#define BBDD "registro_libreria.bin"

typedef struct{
	char titulo[100];
	char autor[50];
	float precio;
	float unidades;
}libro;


int compruebaLibro(char * titulo);
int cuentaRegistros();
libro * reservaMemoria(int reg);
void vuelcaFichero(libro * vector);
int introduceLibro(libro registro);
void listaLibros(libro * vector,int reg);
int vendeLibro(char * titulo);
void borraCero();
#endif
