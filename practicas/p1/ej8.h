#ifndef EJ8_H
#define EJ8_H

#define N 50
#define M 100

typedef struct{
	char nombre[N];
	char apellidos[M];
	int edad;
	char sexo;
}persona;

persona * reservaMemoria(int n);

void escribirPersona(persona * p);
void limpiar();

#endif
