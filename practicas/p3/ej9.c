#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "ej9.h"

void borraCero(){

	libro auxiliar;
	char nombreDestino[MAX_FILENAME];
	FILE * origen=NULL, * destino=NULL;

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

	while((fread(&auxiliar,sizeof(libro),1,origen))==1){
		if(auxiliar.unidades!=0){
			fwrite(&auxiliar,sizeof(libro),1,destino);
		}
	}

	fclose(origen);
	fclose(destino);

	remove(BBDD);
	rename(nombreDestino,BBDD);
}

int vendeLibro(char * titulo){
	int cambios=0;//En caso de que no se encuentre el libro
	FILE * archivo=NULL;
	libro auxiliar;

	archivo=fopen(BBDD,"r+");
	if(!archivo){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	
	while(fread(&auxiliar,sizeof(libro),1,archivo)==1){
		if(strcmp(auxiliar.titulo,titulo)==0){
			if(auxiliar.unidades>0){
				auxiliar.unidades-=1;
				cambios=1;//Si existía stock para vender
			}
			else{
				cambios=2;//Si no existía stock para vender
			}
			fseek(archivo,-sizeof(libro),SEEK_CUR);//Localiza el cursor en archivo, una posición menos de lo que ocupa libro a partir de la pos actual
			fwrite(&auxiliar,sizeof(libro),1,archivo);		
		}
		
	}
	
	
	fclose(archivo);

	return cambios;
}


int compruebaLibro(char * titulo){
	
	libro auxiliar;
	FILE * archivo=NULL;	

	archivo=fopen(BBDD,"r");
	if(!archivo){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	while(fread(&auxiliar,sizeof(libro),1,archivo)==1){
		if(strcmp(auxiliar.titulo,titulo)==0){
			fclose(archivo);			
			return 1;
		}
	}
	
	fclose(archivo);
	return 0;
}



int cuentaRegistros(){
	
	int registros=0;
	FILE * archivo=NULL;
	archivo=fopen(BBDD,"r");

	libro auxiliar;
	
	while(fread(&auxiliar,sizeof(libro),1,archivo)==1){
		registros++;
	}

	fclose(archivo);

	return registros;
}

libro * reservaMemoria(int reg){
	libro * puntero=NULL;

	puntero=(libro *)malloc(sizeof(libro)*reg);
	if(!puntero){
		printf("\nError reservando memoria \n");
		exit(-1);
	}
	return puntero;
}

void vuelcaFichero(libro * vector){
	
	int i=0;
	libro auxiliar;
	FILE * archivo=NULL;
	

	archivo=fopen(BBDD,"r");

	if(!archivo){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}
	
	while(fread(&auxiliar,sizeof(libro),1,archivo)==1){
		vector[i]=auxiliar;
		i++;
	}	

	fclose(archivo);
}

int introduceLibro(libro registro){
	FILE * archivo=NULL;
	
	archivo=fopen(BBDD,"a");
	if(!archivo){
		printf("\nError abriendo fichero\n");
		exit(-1);
	}

	if((fwrite(&registro,sizeof(registro),1,archivo))==1){
		fclose(archivo);
		return 1;
	}

	fclose(archivo);
	return 0;
}

void listaLibros(libro * vector,int reg){
	int i=0;

	printf("\n***********************************************************\n");

	for(i=0;i<reg;i++){
		printf("\nTITULO: %s",vector[i].titulo);
		printf("\nAUTOR: %s",vector[i].autor);
		printf("\nPRECIO: %3.2f\tUNIDADES:%3.0f",vector[i].precio,vector[i].unidades);
		printf("\n\n***********************************************************\n");	
	}
}
