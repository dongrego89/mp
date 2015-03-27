#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "ej7.h"

int main(){

system("clear");

srand48(time(NULL));

float * examenes, minA=10, minB=10, maxA=0, maxB=0, mediaA=0, mediaB=0;
int numExamenes;

printf("\nIndica el numero de examenes totales: ");
scanf("%d",&numExamenes);

examenes=reservaMemoria(numExamenes);
rellenaExamenes(examenes,numExamenes);

imprimeNotas("NOTAS DE LOS EXAMENES: ",examenes,numExamenes);

calculaMedia(examenes, numExamenes, &mediaA, &mediaB);
calculaMin(examenes, numExamenes, &minA, &minB);
calculaMax(examenes, numExamenes, &maxA, &maxB);

printf("\nESTADISTICAS DEL EXAMEN TIPO A:\n\t MEDIA=%2.2f\tMINIMA=%2.2f\tMAXIMA=%2.2f",mediaA,minA,maxA);
printf("\nESTADISTICAS DEL EXAMEN TIPO B:\n\t MEDIA=%2.2f\tMINIMA=%2.2f\tMAXIMA=%2.2f\n",mediaB,minB,maxB);

return 0;
}
