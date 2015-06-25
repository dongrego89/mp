#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include "funciones.h"

void rellenaElemento(alumno * auxiliar){
	printf("\nIntroduce el nombre: ");
	fgets(auxiliar->nombre,MAX_N,stdin);
	if(auxiliar->nombre[strlen(auxiliar->nombre)-1]=='\n'){
		auxiliar->nombre[strlen(auxiliar->nombre)-1]='\0';
	}
	printf("Introduce los apellidos: ");
	fgets(auxiliar->apellidos,MAX_A,stdin);
	if(auxiliar->apellidos[strlen(auxiliar->apellidos)-1]=='\n'){
		auxiliar->apellidos[strlen(auxiliar->apellidos)-1]='\0';
	}
	printf("Introduce el DNI: ");
	scanf("%d",&(auxiliar->dni));
	getchar();pppp
	auxiliar->companero=NULL;
}

void rellenaVector(alumno * vector,int elementos){
	int i;
	for(i=0;i<elementos;i++){
		rellenaElemento(vector+i);
	}
}

void asignaParejas(alumno * vector,int elementos){

	int porEmparejar,aleatorio,i;

	porEmparejar=elementos;
	
	
	for(i=0;i<elementos;i++){
		if(vector[i].companero==NULL){//Si no tiene pareja
			do{//Generamos un aleatorio entre 0 y el numero de elementos, mientras que el compañero no sea NULL y queden por emparejar almenos 2 personas
				aleatorio=rand()%(elementos+1);
			}while((vector[aleatorio].companero!=NULL) && (porEmparejar>=1) && (aleatorio!=i));
			vector[i].companero=vector+aleatorio;
			vector[aleatorio].companero=vector+i;
			porEmparejar-=2;
		}
	}
}

void imprimeParejas(alumno * vector,int elementos){
	
	int i;

	for(i=0;i<elementos;i++){
		printf("\n[%s %s] junto a [%s %s]",vector[i].nombre,vector[i].apellidos,vector[i].companero->nombre,vector[i].companero->apellidos);
	}
	
}







