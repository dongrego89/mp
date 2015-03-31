/**
	@file ejercicio-main.c
	@brief Programa principal del trabajo para semana santa
	@author Grego Corpas
	@date 30-03-2015
	@version 1.0
	
	El objetivo de este programa es manejar punteros y memoria dinámica para uso de matrices y vectores
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#include "ejercicio.h"
#include "../ejercicio1/entradaSalida.h"


/**
	@fn main()
	@brief Función principal

	El programa pedirá las dimensiones de la matriz que generará, también pedirá un número de corte para extraer los elementos mayores. @n
	Las acciones se realizarán del siguiente modo:
	
	@li Pedir el numero de filas y columnas
	@li Reservar memoria para la matriz
	@li Rellenar la matriz 
	@li Mostrar la matriz resultante
	@li Pedir al usuario el elemento de corte a la hora de buscar en la matriz
	@li Extraer el vector
	@li Mostrarlo por pantalla
	@li Calcular el máximo y mínimo 
	@li Imprimir dichos resultados 

	@return 
	@li 0 si todo fue correcto
	@li Otro valor si hubo algún fallo
*/
int main(){

	system("clear");
	srand(time(NULL));

	int f,c,corte,e,max,min;
	int ** matriz, * vector;
	
	printf("\nIntroduce el numero de filas y columnas: ");
	scanf("%d %d",&f,&c);

	matriz=creaMatriz(f,c);

	rellenaMatriz(matriz,f,c);
	imprimeMatriz(matriz,f,c);
	
	printf("\nIntroduce el valor de corte para extraer los mayores de la matriz: ");
	scanf("%d",&corte);

	vector=extraeMayores(matriz,f,c,corte,&e);
	imprimeVector(vector,e);

	calculaMaxMin(matriz,f,c,&max,&min);
	printf("\nEl maximo de la matriz es %d\nEl minimo de la matriz es %d\n",max,min);

	liberaVector(&vector);
	liberaMatriz(&matriz,f);

	if((matriz==NULL) && (vector==NULL)){
		printf("\nMemoria liberada con exito\n");
	}

return 0;
}
