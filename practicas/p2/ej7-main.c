#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int ** multiplicaMatrices(int ** matrizA,int h,int i,int ** matrizB,int j,int k){
	int ** puntero=NULL;
	int a,b,c,sumatorio;
	puntero=reservaMemoria(h,k);
	printf("petada padre A");
	for(a=0;a<h;a++){		
	printf("petada padre b");
		for(b=0;b<k;b++){
	printf("petada padre c");
			sumatorio=0;
			for(c=0;c<i;c++){
				sumatorio+=(matrizA[a][c])*(matrizB[c][a]);
			}
			puntero[a][b]=sumatorio;
		}
	}

	return puntero;
}

int main(){

	system("clear");

	int ** matrizA, ** matrizB, ** matrizC;
	int h,i,j,k,l,m;
	int a,b;

	printf("Introduce las dimensiones de la matriz A: ");
	scanf("%d %d",&h,&i);
	printf("Introduce las dimensiones de la matriz B: ");
	scanf("%d %d",&j,&k);

	matrizA=reservaMemoria(h,i);
	matrizB=reservaMemoria(j,k);

	rellenaMatriz(matrizA,h,i);
	rellenaMatriz(matrizB,j,k);

	imprimeMatriz(matrizA,h,i,"\nMatriz A");
	imprimeMatriz(matrizB,j,k,"\nMatriz B");

	if(i!=j){
		printf("\nImposible multiplicar matrices por diferencia de ordenes");
		exit(-1);
	}
	/*
	matrizC=multiplicaMatrices(matrizA,h,i,matrizB,j,k);
	
	imprimeMatriz(matrizC,h,k);*/

	return 0;
}
