#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include "funciones.h"

int main(int argc,char ** argv){
	
	system("clear");
	srand(time(NULL));

	if(argc!=2){
		printf("\nError invocando programa:\n\t%s [ORDEN] (1=Ascendente/!1=Descendente)\n",argv[0]);
		exit(-1);
	}

	int n;	
	int (*funcionOrdenacion)(int,int);//Puntero a la funcion de ordenación que recibirá 2 parámetros de tipo int

	ficha * vector=NULL;

	if(atoi(argv[1])==1){//Según el argumento en linea de comandos, escogemos entre una de las dos funciones de ordenacion
		funcionOrdenacion=&mayor;		
	}
	else{
		funcionOrdenacion=&menor;
	}

	printf("\n¿Cuantas fichas de alumno se generarán?: ");
	scanf("%d",&n);

	vector=reservaMemoria(n);//Reservamos espacio
	rellenaVector(vector,n);//Rellenamos el vector con valores aleatorios
	imprimeVector(vector,n,"\n[+]Fichas de alumno generadas:");//Realizamos una impresión del vector de fichas

	ordenaVector(vector,n,funcionOrdenacion);//Se ordena

	imprimeVector(vector,n,"\n[#]Fichas de alumno ordenadas:");//Se realiza impresión del vector ordenado

	free(vector);//Liberamos memoria e inutilizamos el vector
	vector=NULL;

	return 0;
}
