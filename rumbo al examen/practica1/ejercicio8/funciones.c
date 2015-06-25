#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "funciones.h"


void leePersona(datos * persona){

	printf("\n\nIntroduce el nombre: ");
	fgets(persona->nombre,MAX_CHAR,stdin);
		if(persona->nombre[strlen(persona->nombre)-1]=='\n'){	
			persona->nombre[strlen(persona->nombre)-1]='\0';
		}
	printf("Introduce los apellidos: ");
	fgets(persona->apellidos,MAX_CHAR,stdin);
		if(persona->apellidos[strlen(persona->apellidos)-1]=='\n'){	
			persona->apellidos[strlen(persona->apellidos)-1]='\0';
		}
	printf("Introduce la edad: ");
	scanf("%d",&(persona->edad));
	getchar();
	printf("Introduce el sexo: ");
	scanf("%c",&(persona->sexo));
	getchar();
}

void escribePersona(datos persona){
	printf("\nNombre y apellidos: %s %s\nEdad: %d\tSexo: ",persona.nombre,persona.apellidos,persona.edad);
	if(persona.sexo=='h'){
		printf("Hombre\n");
	}
	else{
		printf("Mujer\n");
	}
}


datos * reservaMemoria(int elementos){

	datos * puntero=NULL;

	puntero=(datos *)malloc(sizeof(datos)*elementos);
	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}	
	return puntero;
}

void buscaMayorMenor(datos * vector,int elementos, datos * mayor, datos * menor){

	int i;
	
	*mayor=vector[0];
	*menor=*mayor;

	for(i=0;i<elementos;i++){
		if(vector[i].edad>mayor->edad){
			*mayor=vector[i];
		}
		if(vector[i].edad<menor->edad){
			*menor=vector[i];
		}

	}

}

float calculaEdadMedia(datos * vector, int elementos){

	int i;
	float edad=0;

	for(i=0;i<elementos;i++){
		edad+=vector[i].edad;
	}
	
	return edad/(float)elementos;

}











