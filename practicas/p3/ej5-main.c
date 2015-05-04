#include<stdio.h>
#include<stdlib.h>

#include "ej5.h"

int main(int argc, char ** argv){

	if(argc!=2){
		printf("\nError en la invocación, se debe usar así:\n\t%s [NTERMINOS]\n",argv[0]);
		exit(-1);	
	}

	printf("\nLa aproximacion a PI de %s elementos es %2.3f\n",argv[1],aproximaPI(atoi(argv[1])) );

	return 0;
}
