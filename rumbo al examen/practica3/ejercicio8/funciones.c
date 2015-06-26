#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "funciones.h"

int existeLibro(char * nombre,char * cadena){
	
	FILE * archivo=NULL;
	int contador=0;
	char auxiliar[MAX_A];

	archivo=fopen(nombre,"r");

	if(!archivo){
		printf("\nError en apertura de fichero...\n");
		exit(-1);
	}

	while((fgets(auxiliar,MAX_A,archivo))!=NULL){//Estamos sacando una cadena
		if(contador==0){
			//comparamos el titulo 
			if(strcmp(cadena,auxiliar)==0){//Si son iguales
				fclose(archivo);
				return 1;
			}
		}
		else{
			if(contador==2){
				contador=-1;				
			}
		}
		contador+=1;
	}
	
	fclose(archivo);
	return 0;
}

void nuevoLibro(char * nombre,libro informacion){

	FILE * archivo=NULL;

	archivo=fopen(nombre,"a");

	if(!archivo){
		printf("\nError en apertura de fichero...\n");
		exit(-1);
	}

	fprintf(archivo,"%s\n",informacion.titulo);
	fprintf(archivo,"%s\n",informacion.autor);
	fprintf(archivo,"%f %d\n",informacion.precio,informacion.unidades);

	fclose(archivo);
}

int cuentaLibros(char * nombre){
	
	FILE * archivo=NULL;
	char auxiliar;
	int contador=0;
	
	archivo=fopen(nombre,"r");
	
	if(!archivo){
		printf("\nError en apertura de fichero...\n");
		exit(-1);
	}

	while((auxiliar=fgetc(archivo))!=EOF){
		if(auxiliar=='\n'){
			contador+=1;
		}
	}

	fclose(archivo);
	return contador/3;
}


libro * reservaMemoria(int elementos){

	libro * puntero=NULL;

	puntero=(libro *)malloc(sizeof(libro)*elementos);

	if(!puntero){
		printf("\nError en la reserva de memoria\n");
		exit(-1);
	}

	return puntero;

}


void rellenaVector(char * nombre,libro * vector,int tamano){

	FILE * archivo=NULL;
	int i=0;	
	char cadena[MAX_A];	
	
	archivo=fopen(nombre,"r");
	
	if(!archivo){
		printf("\nError en apertura de fichero...\n");
		exit(-1);
	}

	while((fgets(cadena,MAX_A,archivo))!=NULL){
		if(cadena[strlen(cadena)-1]=='\n'){
			cadena[strlen(cadena)-1]='\0';
		}
		strcpy(vector[i].titulo,cadena);//Rellenamos el titulo
		
		fgets(cadena,MAX_A,archivo);

		if(cadena[strlen(cadena)-1]=='\n'){
			cadena[strlen(cadena)-1]='\0';
		}
		strcpy(vector[i].autor,cadena);//Rellenamos autor

		fscanf(archivo,"%f %d\n",&(vector[i].precio),&(vector[i].unidades));
		
		//fgets(cadena,MAX_A,archivo);

		i++;
	}

	fclose(archivo);
}



void imprimeStock(libro * vector,int tamano){

	int i;

	for(i=0;i<tamano;i++){
		printf("\nTitulo: %s\nAutor: %s\nPrecio: %.3f\tUnidades: %d\n",vector[i].titulo,vector[i].autor,vector[i].precio,vector[i].unidades);
	}

}

void guardaBinario(libro * vector,int tamano, char * nombre){
	
	FILE * archivo=NULL;

	archivo=fopen(nombre,"wb");
	
	if(!archivo){
		printf("\nError en apertura de fichero...\n");
		exit(-1);
	}
	
	if(fwrite(vector,sizeof(libro),tamano,archivo)==tamano){
		printf("\nInsertados en el fichero binario...");
	}
	else{
		printf("\nError en insercion");
	}

	fclose(archivo);

}

