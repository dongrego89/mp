#include<stdio.h>

//Prototipos
void ordena(int * n1, int * n2, int * n3);
void intercambia(int * v1, int * v2);

int main(){

	int num1,num2,num3;

	system("clear");

	printf("Introduce el numero 1: ");
	scanf("%d",&num1);
	printf("Introduce el numero 2: ");
	scanf("%d",&num2);
	printf("Introduce el numero 3: ");
	scanf("%d",&num3);

	printf("\n\tLos numeros sin ordenar son \n\t[N1:%d]\n\t[N2:%d]\n\t[N3:%d]\n",num1,num2,num3);

	ordena(&num1,&num2,&num3);

	printf("\n\tLos numeros tras ordenar son \n\t[N1:%d]\n\t[N2:%d]\n\t[N3:%d]\n",num1,num2,num3);

	return 0;
}

//Funciones
void ordena(int * n1, int * n2, int * n3){	
	if(*n3<*n2){
		intercambia(n3,n2);	
	}
	if(*n3<*n1){//Aquí conseguimos tener en n3 el número mayor
		intercambia(n3,n1);
	}
	if(*n2<*n1){//Aquí ordenamos el resto de números en su lugar correspondiente
		intercambia(n2,n1);
	}	
}

void intercambia(int * v1, int * v2){
	int auxiliar;
	auxiliar=*v1;
	*v1=*v2;
	*v2=auxiliar;
}
