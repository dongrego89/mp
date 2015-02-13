#include<stdio.h>

int main(){
	int a, *b, **c;
	double d, *e, **f;
	
	system("clear");	
	
	printf("\nEl tamaño de a es %ld",sizeof(a));
	printf("\nEl tamaño de *b es %ld",sizeof(b));
	printf("\nEl tamaño de **c es %ld",sizeof(c));

	printf("\nEl tamaño de d es %ld",sizeof(d));
	printf("\nEl tamaño de *e es %ld",sizeof(e));
	printf("\nEl tamaño de **f es %ld\n",sizeof(f));

	return 0;	
}
