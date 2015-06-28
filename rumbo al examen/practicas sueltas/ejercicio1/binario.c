#include<stdio.h>

#include "binario.h"

int modificaPrecio(char * binario,int codigo,float precio){

	FILE * fichB=NULL;
	producto auxiliar;	

	fichB=fopen(binario,"rb+");
	
	if(!fichB){
		printf("\nError en apertura de ficheros");
		return -2;
	}

	fread(&auxiliar,sizeof(producto),1,fichB);

	while(!feof(fichB)){
		if(auxiliar.cod==codigo){
			fseek(fichB,-(sizeof(int)+sizeof(float)),SEEK_CUR);//Posicionamos la cabeza lectora justo donde queremos pisar
			fwrite(&precio,sizeof(float),1,fichB);
			fclose(fichB);
			return 1;
		}
		fread(&auxiliar,sizeof(producto),1,fichB);
	}

	fclose(fichB);
	return -1;
}
