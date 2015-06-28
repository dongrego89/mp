#ifndef BINARIO_H
#define BINARIO_H

typedef struct{
	char nombre[50];
	int cod;
	float precio;
	int unidades;
}producto;

int modificaPrecio(char * binario,int codigo,float precio);

#endif
