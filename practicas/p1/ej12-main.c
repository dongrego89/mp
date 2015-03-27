#include<stdio.h>
#include<stdlib.h>

#include "ej12.h"

int main(){

system("clear");

int * matriz, nfil, ncol;

printf("\nIntroduce las dimensiones de la matriz: ");
scanf("%d %d",&nfil,&ncol);

matriz=reservaMemoria(nfil*ncol);


printf("\nRellenar matriz:\n");

leerMatriz(matriz,nfil,ncol);

printf("\nImprimir matriz:\n");

escribirMatriz(matriz,nfil,ncol);

free(matriz);
matriz=NULL;

return 0;
}
