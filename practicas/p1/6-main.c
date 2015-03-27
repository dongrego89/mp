#include<stdio.h>
#include "6.h"

int main(){

system("clear");

	double n1,n2,nMedia;
	printf("Introduce los 2 números: ");
	scanf("%lf %lf",&n1,&n2);

	nMedia=media(n1,n2);
	printf("\nLa media aritmética entre %lf y %lf es %lf",n1,n2,nMedia);
	
	nMedia=0;//Ponemos 0 para comprobar que vuelve a cambiar su valor posteriormente	

	media_referencia(n1,n2,&nMedia);
	printf("\nLa media aritmética entre %lf y %lf es %lf\n",n1,n2,nMedia);
	

return 0;
}
