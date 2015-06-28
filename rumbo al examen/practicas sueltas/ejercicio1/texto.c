#include<stdio.h>
#include<stdlib.h>

#include "texto.h"
#include "binario.h"

void binarioTexto(char * binario, char * texto){

	FILE * fichB=NULL, * fichT=NULL;
	producto auxiliar;

	fichB=fopen(binario,"rb");
	fichT=fopen(texto,"w");

	if(!fichB || !fichT){
		printf("\nError en apertura de ficheros");
		exit(-1);
	}

        


	fread(&auxiliar,sizeof(producto),1,fichB);

	while(!feof(fichB)){
		
		fprintf(fichT,"%d %s %.2f %d\n",auxiliar.cod,auxiliar.nombre,auxiliar.precio,auxiliar.unidades);//Imprimimos en el fichero de texto	

		fread(&auxiliar,sizeof(producto),1,fichB);
	}

	fclose(fichB);
	fclose(fichT);

}

