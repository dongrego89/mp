#include<stdio.h>

#include "funciones.h"

int main(){
	
	system("clear");

	double n;
	char f;
	double (*pFuncion)(double);	

	do{
		printf("\nIndica el valor de N: ");
		scanf("%lf",&n);
		getchar();
	}while(n<0);

	printf("\nIndica la función a evaluar\n[f] = F(x)\n[g] = G(x)\n[z] = Z(x)");

	do{
		printf("\n\tFuncion: ");
		scanf("%c",&f);
		getchar();
	}while(f!='f' && f!='g' && f!='z');
	
	switch(f){
		case 'f':
			pFuncion=&funcionF;
		break;
		case 'g':
			pFuncion=&funcionG;
		break;
		case 'z':
			pFuncion=&funcionZ;
		break;
	}

	evaluaFuncion(n,0.2,pFuncion);

	return 0;	
}
