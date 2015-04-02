#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "ej4.h"

int main(){

	system("clear");
	srand(time(NULL));

	int ** ma, ** mb, ** mc;
	int fa,ca,fb,cb,fc,cc;

	printf("\nIntroduce las dimensiones F x C de la matriz A: ");
	scanf("%d %d",&fa,&ca);

	printf("\nIntroduce las dimensiones F x C de la matriz B: ");
	scanf("%d %d",&fb,&cb);

	ma=reservaMemoria(fa,ca);
	mb=reservaMemoria(fb,cb);

	rellenaMatriz(ma,fa,ca);
	rellenaMatriz(mb,fb,cb);

	imprimeMatriz(ma,fa,ca,"\nMatriz A:");
	imprimeMatriz(mb,fb,cb,"\nMatriz B:");

	if(ca!=fb){
		printf("\nError, no se puede multiplicar estas matrices por diferencia de órdenes\n");
		exit(-1);
	}
	
	mc=reservaMemoria(fa,cb);
	fc=fa;
	cc=cb;
	
	multiplica(ma,fa,ca,mb,fb,cb,mc,fc,cc);
	
	imprimeMatriz(mc,fc,cc,"\nMatriz C:");	

	liberaMemoria(&ma,fa);
	liberaMemoria(&mb,fb);
	liberaMemoria(&mc,fc);

	if((ma==NULL) && (mb==NULL) && (mc==NULL)){
		printf("\nMemoria liberada satisfactoriamente\n");
	}

	return 0;
}
