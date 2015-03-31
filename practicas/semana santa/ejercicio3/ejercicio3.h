#ifndef EJERCICIO3_H
#define EJERCICIO3_H

struct estudiante{
	char nombre[50];
	int dni;
	float nota;
};

struct estudiante * reservaMemoria(int n);

void rellenaVector(struct estudiante * v, int n);

void rellenaEstudiante(struct estudiante * e);

void imprimeVector(struct estudiante * v, int n);

float calculaMediaNombre(struct estudiante * v, int n);

void liberaMemoria(struct estudiante ** v);

#endif

