#include<stdio.h>
#include<stdlib.h>

#include "ej5.h"

int main(){
	
	system("clear");

	char ** vector, *cadena=NULL;
	int nFrases=0,i;

	vector=leeFrases(&nFrases);

	imprimeFrases(vector,nFrases,"\nVector de cadenas:");
	
	cadena=(char *)malloc(sizeof(char));

	for(i=0;i<nFrases;i++){
		if(i%2==0){
			cadena=concatenaCadenas(cadena,vector[i]);
		}
	}


	printf("La cadena resultante es:\n\t%s\n",cadena);


return 0;
}
