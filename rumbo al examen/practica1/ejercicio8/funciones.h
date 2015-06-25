#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_CHAR 150

typedef struct{
	char nombre[MAX_CHAR];
	char apellidos[MAX_CHAR];
	int edad;
	char sexo;
}datos;

datos * reservaMemoria(int elementos);
void leePersona(datos * persona);
void escribePersona(datos persona);
void buscaMayorMenor(datos * vector,int elementos, datos * mayor, datos * menor);
float calculaEdadMedia(datos * vector, int elementos);

#endif
