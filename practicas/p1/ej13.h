#ifndef EJ13_H
#define EJ13_H

struct alumno{
	char nombre[50];
	char apellidos[150];
	int dni;
	struct alumno * companero;
};

void inscribeAlumnos(struct alumno vector[],int nAlumnos);
void emparejaAlumnos(struct alumno vector[],int nAlumnos);
void imprimeParejas(struct alumno vector[],int nAlumnos);

#endif
