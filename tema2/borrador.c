#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define FILAS 2
#define COLUMNAS 3

int main(){

int ** matriz;
int i,j;

system("clear");

srand(time(NULL));

matriz=(int **)malloc(sizeof(int *)*FILAS);

for(i=0;i<COLUMNAS;i++){
	matriz[i]=(int *)malloc(sizeof(int)*COLUMNAS);
}

for(i=0;i<FILAS;i++){

	printf("FILA %d",i+1);	
	for(j=0;j<COLUMNAS;j++){
		matriz[i][j]=rand()%10;
		printf("[%d]",matriz[i][j]);
	}
	printf("\n");
}

printf("\n:::::::::::::::::::::::::::\n\n");

printf("Matriz: %p\n",matriz);
printf("Matriz+1: %p\n",matriz+1);
printf("*(Matriz+1): %p\n",*(matriz+1));
printf("(*(Matriz+1)+1): %p\n",(*(matriz+1)+1));


return 0;
}
