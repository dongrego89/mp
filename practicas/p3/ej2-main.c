#include<stdio.h>
#include<stdlib.h>

#include "ej2.h"

int main(int argc, char ** argv){
	if(argc!=2){
		printf("\nError, el programa se ha de invocar así:\n\t%s [NUMERO]\n",argv[0]);
		exit(-1);
	}

	printf("\nEl numero %s tiene %d digitos pares\n",argv[1],calculaPares(atoi(argv[1])));
	
	return 0;
}
