#include<stdio.h>
#include "6.h"

int main(){
system("clear");

	double num1, num2, nMedia;
	printf("Introduce numero1 y numero2: ");
	scanf("%d %d",&num1,&num2);

	nMedia=media(num1,num2);
	printf("\tEl resultado devuelto por el método media es %d\n", nMedia);
	
	media_referencia(num1,num2,&nMedia);
	printf("\tEl resultado devuelto por el método media_referencia es %d\n", nMedia);
	
	return 0;
}
