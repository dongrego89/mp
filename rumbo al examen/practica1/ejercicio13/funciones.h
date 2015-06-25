#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_N 50
#define MAX_A 150
#define MAX_V 100

struct al{
	char nombre[MAX_N];
	char apellidos[MAX_A];
	int dni;
	struct al * companero;
};

typedef struct al alumno;

void rellenaVector(alumno * vector,int elementos);
void asignaParejas(alumno * vector,int elementos);
void imprimeParejas(alumno * vector,int elementos);

#endif
