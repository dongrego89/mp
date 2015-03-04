#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "7.h"

int main(){

	system("clear");
	
	srand(time(NULL)); // Semilla generadora numeros aleatorios

	float examenes[50];
	float minima_a=10, minima_b=10, maxima_a=0, maxima_b=0, media_a=0, media_b=0;

	rellenaNotas(examenes);

	imprimeNotas(examenes);

	calculaEstadisticas(examenes,&media_a,&maxima_a,&minima_a,&media_b,&maxima_b,&minima_b);
	printf("\nLas estadisticas del examen TIPO A son\n\tMEDIA = %.2f\tMAXIMA = %.2f\tMINIMA= %.2f",media_a,maxima_a,minima_a);
	printf("\nLas estadisticas del examen TIPO B son\n\tMEDIA = %.2f\tMAXIMA = %.2f\tMINIMA= %.2f\n",media_b,maxima_b,minima_b);

	return 0;
}
