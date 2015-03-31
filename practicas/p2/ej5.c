#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include "ej5.h"


char ** leeCadenas(int * n){

	char ** puntero=NULL;
	char auxiliar[160];
	*n=0; //El numero de cadenas utiles de momento es 0
	printf("\nPara dejar de introducir cadenas escribe $:\n");
	do{
		fgets(auxiliar,160,stdin); //Leemos la cadena
	
		if(auxiliar[0]!='$'){ //Si no es el $
			*n=(*n)+1; //Incrementamos el numero de elementos utiles en el vector
			auxiliar[strlen(auxiliar)-1]='\0'; //Supresión del \n por \0

			puntero=(char **)realloc(puntero,sizeof(char *)*(*n)); //Reconfiguramos el espacio según los elementos útiles actuales
			puntero[(*n)-1]=(char *)realloc(puntero[(*n)-1],sizeof(char)*(strlen(auxiliar)+1));	//Reservamos espacio para la cadena que pedimos al usuario
			
			strcpy(puntero[(*n)-1],auxiliar);//Copiamos la cadena en su lugar del vector		
		}
		
	}while(auxiliar[0]!='$'); //Mientras no se introduzca el caracter $
	
	return puntero;
}

void imprimeCadenas(char ** vector,int n,char * mensaje){
	int i;

	printf("%s",mensaje);
	for(i=0;i<n;i++){
		printf("\n\t%s (%d)",vector[i],(int)strlen(vector[i]));
	}
	printf("\n");
}

char * concatena(char ** vector, int n){
	char * puntero=NULL;	
	int tam=0,i,pos;

	for(i=0;i<n;i++){
		if(i%2!=0){
			tam=1+tam+strlen(vector[i]);
		//He de reservar 1 caracter más de espacio porque el \0 lo omite al mostrar strlen, y luego necesitaré el hueco para el espacio.
		}
	}
	
	puntero=(char *)malloc(sizeof(char)*tam);

	if(puntero==NULL){
		printf("\nError reservando memoria\n");
		exit(-1);	
	}

	pos=0; //En esta variable llevaremos la posición donde continuaremos copiando.	
	
	for(i=0;i<n;i++){
		if(i%2!=0){
			strcpy(&puntero[pos],vector[i]);
			pos=pos+(int)strlen(vector[i]);
			puntero[pos]=' ';//En la siguiente posición a donde termina la cadena va un espacio
			pos++;//E incrementamos la posición para recibir la próxima cadena.
		}
	}

	puntero[pos-1]='\0'; //En el caso de la última frase si hay que dejar el \0 para indicar que acaba la cadena
	
	return puntero;
}
