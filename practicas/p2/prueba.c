#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(){

char cadena[4]="Hola";

printf("%s %s (%d) [%c]",cadena,cadena,(int)strlen(cadena),cadena[(int)strlen(cadena)]);

return 0;
}
