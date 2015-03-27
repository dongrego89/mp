#include<stdio.h>

#include "ej8.h"

int main(){

system("clear");

persona * personas;
int nPersonas,i;

printf("Introduce el numero de personas a almacenar: ");
scanf("%d",&nPersonas);

limpiar();

personas=reservaMemoria(nPersonas);

for(i=0;i<nPersonas;i++){
	escribirPersona(&personas[i]);
}


return 0;
}
