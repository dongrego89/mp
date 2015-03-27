#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

#include "ej13.h"

int main(){

	system("clear");
	srand(time(NULL));//Semilla generadora de aleatorios
	
	int nAlumnos;
	struct alumno vector[MAX];
	
	do{//Para poder ejecutar correctamente necesitaremos un numero de alumnos par, menor del maximo (100) y mayor o igual a 2
		printf("Introduce un numero par de alumnos entre 2 y %d: ",MAX);
		scanf("%d",&nAlumnos);
	}while((nAlumnos>MAX || nAlumnos<2) || (nAlumnos%2!=0));

	inscribeAlumnos(vector,nAlumnos);
	emparejaAlumnos(vector,nAlumnos);
	imprimeParejas(vector,nAlumnos);

return 0;
}
