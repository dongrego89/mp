#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "funciones.h"

void liberaMemoria(char *** vector, int frases){

	int i;
	
	for(i=0;i<frases;i++){
		free((*vector)[i]);
	}
	free(*vector);

	*vector=NULL;
}

char * reservaMemoria(int tamano){//Reserva memoria para una cadena
	
	char * puntero=NULL;

	puntero=(char *)malloc(sizeof(char)*tamano);

	if(!puntero){
		printf("\nError reservando memoria...\n");
		exit(-1);
	}
	
	return puntero;
}

char ** leeFrases(int max,char fin, int * numero){
	
	int i=0;
	char ** puntero=NULL;

	*numero=0;

	puntero=(char **)malloc(sizeof(char *));

	printf("\n");	

	do{
		i++;
		
		puntero=(char **)realloc(puntero,sizeof(char *)*i);//Ampliamos la memoria del vector para que entre el proximo elemento
		puntero[i-1]=reservaMemoria(max);//Reservamos memoria para la proxima cadena

		printf("Cadena nº %d: ",i-1);
		fgets(puntero[i-1],max,stdin);

		if(puntero[i-1][strlen(puntero[i-1])-1]=='\n'){//Acondicionamos para pisar el \n en caso de que sea el ultimo caracter de la cadena
			puntero[i-1][strlen(puntero[i-1])-1]='\0';
		}
		
	}while(strchr(puntero[i-1],fin)==NULL);
	
	printf("\n");	

	*numero=i;
	
	return puntero;
}

char * concatenaFrases(char ** vector,int numero){
	
	int i,tamano=0,apuntador=0;
	
	char * frase=NULL;	
	
	for(i=0;i<numero;i++){
		if(i%2!=0){
			tamano+=strlen(vector[i])+1;//sumamos un hueco para el espacio
		}
	}
	
	frase=reservaMemoria(tamano);

	for(i=0;i<numero;i++){
		if(i%2!=0){
			strcpy(frase+apuntador,vector[i]);
			apuntador=strlen(frase);
	
			frase[apuntador]=' ';//Pisamos el caracter \0 por un espacio
			apuntador+=1;
		}
	}
		apuntador-=1;
		frase[apuntador]='\0';//Pisamos el ultimo caracter por el fin de cadena
	
	return frase;
}

void imprimeFrases(char ** vector,int numero){
		
	int i;

	printf("\n");

	for(i=0;i<numero;i++){
		printf("\nFrase %d : '%s'",i,vector[i]);
	}	

	printf("\n");

}
