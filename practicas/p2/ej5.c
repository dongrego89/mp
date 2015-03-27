#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej5.h"


char ** leeFrases(int * nFrases){

	char auxiliar[MAX],letra,** puntero=NULL;
	int i=0;

	printf("\nIntroduciendo cadenas. Usa el caracter $ para finalizar\n");
	while(1){
		i++;
		puntero=realloc(puntero,sizeof(char *) * i);
		fflush(stdin);
		fgets(auxiliar,MAX,stdin);
		
		if(auxiliar[0]=='$'){
			break;
		}

		puntero[i-1]=(char *)malloc(sizeof(char)*strlen(auxiliar));
		auxiliar[strlen(auxiliar)-1]='\0';
		strcpy(puntero[i-1],auxiliar);	

	}
	
	*nFrases=i-1;
	return puntero;
}

void imprimeFrases(char ** vector, int nFrases, char * mensaje){
	int i;
	
	printf("%s",mensaje);
	for(i=0;i<nFrases;i++){
		printf("\n\t%s",vector[i]);
	}
	printf("\n");
}


char * concatenaCadenas(char * destino, char * origen){
	int n=strlen(destino) + strlen(origen),i,contador;
	
	char * puntero=(char *)malloc(sizeof(char)*n);

	for(i=0,contador=0;i<strlen(destino);i++,contador++){
		puntero[contador]=destino[i];
	}

	puntero[contador]=' '; //quitar el \0
	contador+=1;
	puntero[contador]=' '; //meter espacio

	for(i=0;i<strlen(origen);i++,contador++){
		puntero[contador]=origen[i];
	}
	
	return puntero;
}


