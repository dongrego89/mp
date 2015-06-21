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
	int (*funcionOrdenacionDni)(const void * ,const void *);//Puntero a la funcion de ordenación por dni que recibirá 2 parámetros de tipo int
	int (*funcionOrdenacionNota)(const void * ,const void *);//Puntero a la funcion de ordenación por dni que recibirá 2 parámetros de tipo int
	char campo;

	ficha * vector=NULL;

	if(atoi(argv[1])==1){//Según el argumento en linea de comandos, escogemos entre una de las dos funciones de ordenacion
		funcionOrdenacionDni=&mayorDni;	
		funcionOrdenacionNota=&mayorNota;		
	}
	else{
		funcionOrdenacionDni=&menorDni;
		funcionOrdenacionNota=&menorNota;
	}

	printf("\n¿Cuantas fichas de alumno se generarán?: ");
	scanf("%d",&n);
	getchar();

	vector=reservaMemoria(n);//Reservamos espacio
	rellenaVector(vector,n);//Rellenamos el vector con valores aleatorios
	imprimeVector(vector,n,"\n[+]Fichas de alumno generadas:");//Realizamos una impresión del vector de fichas
	
	printf("\n¿Desea ordenar el vector por dni o por nota? [d/n]: ");
	do{
		scanf("%c",&campo);
		getchar();
	}while((campo!='d') && (campo!='n'));

	if(campo=='d'){
		qsort((void *)vector,n,sizeof(ficha),funcionOrdenacionDni);//Se ordena por dni
	}
	else{
		qsort((void *)vector,n,sizeof(ficha),funcionOrdenacionNota);//Se ordena por nota
	}

	imprimeVector(vector,n,"\n[#]Fichas de alumno ordenadas:");//Se realiza impresión del vector ordenado

	free(vector);//Liberamos memoria e inutilizamos el vector
	vector=NULL;

	return 0;
}
