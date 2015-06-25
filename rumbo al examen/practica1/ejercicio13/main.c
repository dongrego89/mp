#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "funciones.h"

int main(){

	system("clear");

	srand(time(NULL));//Semilla random

	int numAlumnos;
	alumno alumnos[MAX_V];

	printf("\nIntroduce el numero de alumnos que se registraran: ");
	scanf("%d",&numAlumnos);
	getchar();

	rellenaVector(alumnos,numAlumnos);
	asignaParejas(alumnos,numAlumnos);
	imprimeParejas(alumnos,numAlumnos);

	getchar();
	
	system("clear");

	return 0;
}
