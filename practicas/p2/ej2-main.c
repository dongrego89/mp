#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "ej2.h"

int main(){

system("clear");

srand(time(NULL));

int * vector,* impares,elementos,nElementos;

printf("Introduce el numero de elementos que contendrá el vector: ");
scanf("%d",&elementos);

vector=reservaMemoria(elementos);

rellenaVector(vector, elementos);

imprimeVector(vector, elementos, "Vector Original");

impares=extraeImpares(vector, elementos, &nElementos);

imprimeVector(impares, nElementos, "Vector Impares");

free(vector);
free(impares);

vector=NULL;
impares=NULL;

return 0;
}

