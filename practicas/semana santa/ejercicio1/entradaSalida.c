#include<stdio.h>
#include<stdlib.h>

void rellenaVector(int * v, int n){
	int i;
	for(i=0;i<n;i++){
		v[i]=rand()%10;
	}	
}

void imprimeVector(int * v, int n){
	int i;
	
	printf("\nVECTOR: ");
	for(i=0;i<n;i++){
		printf("[%d]",v[i]);
	}
	printf("\n");
}

void rellenaMatriz(int ** m, int fil, int col){
	int i,j;
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			m[i][j]=rand()%10;
		}
	}
}

void imprimeMatriz(int ** m, int fil, int col){
	int i,j;
	
	printf("\nMATRIZ:");
	for(i=0;i<fil;i++){
		printf("\n\t");
		for(j=0;j<col;j++){
			printf("[%2d]",m[i][j]);
		}
	}
	printf("\n");
}
