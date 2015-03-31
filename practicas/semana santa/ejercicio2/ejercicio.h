/*---------------------------------------------------------------------------------

	@file ejercicio.h
	@brief Cabeceras prototipo de las funciones
	@author Grego Corpas Prieto
	@date 30-03-2015
	@version 1.0

---------------------------------------------------------------------------------*/

#ifndef EJERCICIO_H
#define EJERCICIO_H

int ** creaMatriz(int fil, int col);
int * creaVector(int e);
int * extraeMayores(int ** matriz,int f,int c,int corte,int * e);
void calculaMaxMin(int ** matriz,int f,int c,int * max,int * min);

void liberaMatriz(int *** matriz, int f);
void liberaVector(int ** vector);

#endif
