#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej8.h"

int compruebaLibro(char * titulo){
	
	int i=1;	
	char auxiliar[MAX_CHAR];
	FILE * fichero=NULL;

	fichero=fopen(BBDD,"r");

	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while((fgets(auxiliar,MAX_CHAR,fichero))!=NULL){
		if(i==1){	

			auxiliar[strlen(auxiliar)-1]='\0';

			if((strcmp(titulo,auxiliar))==0){
				fclose(fichero);
				return 1;
			}
		i=4;
		}
		i--;
	}

	fclose(fichero);
	return 0;
}

void introduceLibro(registro libro){
	FILE * fichero=NULL;

	fichero=fopen(BBDD,"a");

	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	fputs(libro.titulo,fichero);
	fputc('\n',fichero);
	fputs(libro.autor,fichero);
	fputc('\n',fichero);
	fprintf(fichero,"%3.2f,%d\n",libro.precio,libro.unidades);

	fclose(fichero);
}

int cuentaLibros(){
	char c;
	int libros=0;
	FILE * fichero=NULL;
	fichero=fopen(BBDD,"r");
	
	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);		
	}

	while((c=fgetc(fichero))!=EOF){
		if(c=='\n'){
			libros+=1;
		}
	}
	
	fclose(fichero);
	
	return libros/3;
}

registro * reservaMemoria(int regs){

	registro * puntero=NULL;
	puntero=(registro *)malloc(sizeof(registro)*regs);

	if(!puntero){
		printf("\nError reservando memoria\n");
		exit(-1);
	}
	
	return puntero;
}

void vuelcaFichero(registro * vector){
	
	int i=0;
	char auxiliar[MAX_CHAR];
	FILE * fichero;
	fichero=fopen(BBDD,"r");

	if(!fichero){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}
	printf("Depuremos pues");
	while((fgets(auxiliar,MAX_CHAR,fichero))!=NULL){
		auxiliar[strlen(auxiliar)-1]='\0';
		strcpy(vector[i].titulo,auxiliar);

		fgets(auxiliar,MAX_CHAR,fichero);
		strcpy(vector[i].autor,auxiliar);
		
		
		fgets(auxiliar,MAX_CHAR,fichero);

		vector[i].precio=atof(strtok(auxiliar,","));
		vector[i].unidades=atoi(strtok(NULL,","));

		i++;
	}
	
	fclose(fichero);
}

void listaLibros(registro * vector, int regs){

	int i;

	for(i=0;i<regs;i++){
		printf("\n\tTITULO: %s",vector[i].titulo);
		printf("\n\tAUTOR: %s",vector[i].autor);
		printf("\n\tPRECIO: %3.2f\tUNIDADES: %d\n",vector[i].precio,vector[i].unidades);
		printf("\n************************************************************\n");

	}

}

int vendeLibro(char * titulo){
	FILE * origen=NULL, * destino=NULL;
	char nombreDestino[MAX_FILENAME],auxiliar[MAX_CHAR];
	int cambios=0,unidades;	
	float precio;

	strcpy(nombreDestino,BBDD);
	strcat(nombreDestino,".tmp");

	
	origen=fopen(BBDD,"r");

	if(!origen){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}	
	
	destino=fopen(nombreDestino,"w");
	if(!destino){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}	

		
	while((fgets(auxiliar,MAX_CHAR,origen))!=NULL){

		fputs(auxiliar,destino);//Guardamos titulo en temporal
		auxiliar[strlen(auxiliar)-1]='\0';
		if(strcmp(auxiliar,titulo)==0){//Si es el libro que buscabamos
			fgets(auxiliar,MAX_CHAR,origen);
			fputs(auxiliar,destino);//Guardamos el autor

			fgets(auxiliar,MAX_CHAR,origen);//Extraemos las cifras
	
			precio=atof(strtok(auxiliar,","));
			unidades=atoi(strtok(NULL,","));
		
			if(unidades>0){//Es posible actualizar el stock
				unidades-=1;
				cambios=1; //Podremos disminuir el stock
			}
			else{
				cambios=2; //No podremos disminuir el stock, por tanto lo copiaremos tal cual aunque en el main mostraremos el error
			}			
	
			fprintf(destino,"%3.2f,%d\n",precio,unidades);
		}
		else{//Si no es el libro que buscabamos
			fgets(auxiliar,MAX_CHAR,origen);
			fputs(auxiliar,destino);//Guardamos el autor en temporal
			fgets(auxiliar,MAX_CHAR,origen);
			fputs(auxiliar,destino);//Guardamos las cifras en temporal
		}
	}

	fclose(origen);
	fclose(destino);
	
	remove(BBDD);
	rename(nombreDestino,BBDD);

	return cambios;
}

void borraCero(){
	FILE * origen=NULL, * destino=NULL;
	char auxiliar[MAX_CHAR],nombreDestino[MAX_FILENAME];
	registro regAuxiliar;
	
	strcpy(nombreDestino,BBDD);
	strcat(nombreDestino,".tmp");

	origen=fopen(BBDD,"r");
	if(!origen){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	destino=fopen(nombreDestino,"w");
	if(!destino){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while((fgets(auxiliar,MAX_CHAR,origen))!=NULL){
		strcpy(regAuxiliar.titulo,auxiliar);

		fgets(auxiliar,MAX_CHAR,origen);
		strcpy(regAuxiliar.autor,auxiliar);

		fgets(auxiliar,MAX_CHAR,origen);
		
		regAuxiliar.precio=atof(strtok(auxiliar,","));
		regAuxiliar.unidades=atoi(strtok(NULL,","));
		
		if(regAuxiliar.unidades!=0){//Si las unidades son distintas a cero, copiamos los valores en el fichero destino
			fputs(regAuxiliar.titulo,destino);
			fputs(regAuxiliar.autor,destino);
			fprintf(destino,"%3.2f,%d\n",regAuxiliar.precio,regAuxiliar.unidades);
		}
	}	

	fclose(origen);
	fclose(destino);

	remove(BBDD);
	rename(nombreDestino,BBDD);
	
}



















