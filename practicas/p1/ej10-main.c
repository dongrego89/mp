#include<stdio.h>
#include<string.h>

#include "ej10.h"

int main(){

system("clear");

char cadena[50],nuevo,viejo;

printf("\nIntroduce una cadena de caracteres: ");
fgets(cadena,50,stdin);

printf("\nIntroduce el caracter a reemplazar: ");
viejo=getchar();
fflush(stdin);
getchar();

printf("\nIntroduce el caracter nuevo: ");
nuevo=getchar();
fflush(stdin);
getchar();

replace(cadena,nuevo,viejo);

printf("La cadena queda así: %s",cadena);

return 0;
}
