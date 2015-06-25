#include<stdlib.h>
#include<stdio.h>

#include "funciones2.h"

void multiplicacion(int ** matrizA,int ** matrizB,int ** matrizC,int fa,int ca,int cb){

	int i,j,k,sumatorio;

	for(i=0;i<fa;i++){//Los dos primeros sirven para recorrer la posicion de la matriz C
		for(j=0;j<cb;j++){
			sumatorio=0;
			for(k=0;k<ca;k++){//Este recorre columnas A que son filas B
				sumatorio+=matrizA[i][k] * matrizB[k][j];
			}
			matrizC[i][j]=sumatorio;
		}
	}
}
