#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "funciones.h"

int compruebaFichero(char * nombre){
	
	FILE * fichero=NULL;

	fichero=fopen(nombre,"r");

	if(!fichero){
		printf("\nError abriendo fichero\n");
		return -1;
	}

	fclose(fichero);
	return 0;
}

void actualizaEdad(char * nombre){

	FILE * fichero=NULL, * temporal=NULL;
	char nombreTemporal[FILENAME_MAX], cadena[MAX_CHAR];

	strcpy(nombreTemporal,nombre);
	strcat(nombreTemporal,".tmp");

	fichero=fopen(nombre,"r");
	temporal=fopen(nombreTemporal,"w");

	if(!fichero || !temporal){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while(fgets(cadena,MAX_CHAR,fichero)!=NULL){
	
		fputs(cadena,temporal);
		fgets(cadena,MAX_CHAR,fichero);
	
		strtok(cadena," ");		

		fprintf(temporal,"%d",atoi(cadena)+1);
		fprintf(temporal," %2.3f",atof(strtok(NULL," ")));
		fprintf(temporal," %2.3f",atof(strtok(NULL," ")));
		fprintf(temporal," %d\n",atoi(strtok(NULL," ")));

	}	
	
	fclose(fichero);
	fclose(temporal);

	remove(nombre);
	rename(nombreTemporal,nombre);
	
}

void distribuyePorSexo(char * nombre, char * chicos, char * chicas){
	
	FILE * fichero=NULL, * fChicos=NULL, * fChicas=NULL;
	char cadena1[MAX_CHAR], cadena2[MAX_CHAR], auxiliar[MAX_CHAR];
	
	
	fichero=fopen(nombre,"r");
	fChicos=fopen(chicos,"w");
	fChicas=fopen(chicas,"w");

	if(!fichero || !fChicos || !fChicas){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while(fgets(cadena1,MAX_CHAR,fichero)!=NULL){
		fgets(cadena2,MAX_CHAR,fichero);
		
		strcpy(auxiliar,cadena2);//Copia de cadena 2
		
		strtok(auxiliar," ");
		strtok(NULL," ");		
		strtok(NULL," ");		
		if(atoi(strtok(NULL," "))==0){//Es un chico
			fputs(cadena1,fChicos);
			fputs(cadena2,fChicos);
		}		
		else{//Es una chica
			fputs(cadena1,fChicas);
			fputs(cadena2,fChicas);
		}

	}

	fclose(fichero);
	fclose(fChicos);
	fclose(fChicas);
}

void mezclaAlumnos(char * nombre, char * chicos, char * chicas){

	FILE * fichero=NULL, * fChicos=NULL, * fChicas=NULL;
	int banderaChicos=0,banderaChicas=0,indice=0;
	char cadenaChicos[MAX_CHAR],cadenaChicas[MAX_CHAR];


	fichero=fopen(nombre,"w");
	fChicos=fopen(chicos,"r");
	fChicas=fopen(chicas,"r");

	if(!fichero || !fChicos || !fChicas){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}
	
	fgets(cadenaChicos,MAX_CHAR,fChicos);
	fgets(cadenaChicas,MAX_CHAR,fChicas);
	
	
	do{
		if(indice%2==0){//Si el indice es par introduciremos un chico
			if(!feof(fChicos)){//Si aun no terminó el fichero de chicos
				fputs(cadenaChicos,fichero);
				fgets(cadenaChicos,MAX_CHAR,fChicos);
				fgets(cadenaChicos,MAX_CHAR,fChicos);//Preparada la proxima linea
			}
			else{
				banderaChicos=1;//Termino el fichero de chicos
			}
		}
		else{//Si el indice es impar introduciremos una chica
			if(!feof(fChicas)){//Si aun no terminó el fichero de chicas
				fputs(cadenaChicas,fichero);
				fgets(cadenaChicas,MAX_CHAR,fChicas);
				fgets(cadenaChicas,MAX_CHAR,fChicas);//Preparada la proxima linea
			}
			else{
				banderaChicas=1;//Terminó el fichero de chicas
			}
		}
		indice++;
	}while(banderaChicos!=1 && banderaChicas!=1);

	fclose(fichero);
	fclose(fChicos);
	fclose(fChicas);

}



















