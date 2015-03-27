#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	system("clear");

	int ** matriz, col, fil, aBorrar;
	int i,j;
	
	srand(time(NULL));

	printf("\nIntroduce las dimensiones de la matriz NxM: ");
	scanf("%d %d",&fil,&col);

	matriz=reservaMemoria(fil,col);
	
	rellenaMatriz(matriz,fil,col);

	imprimeMatriz(matriz,fil,col,"\nMatriz Original");

	do{
		printf("\nIntroduce la fila que deseas borrar: ");
		scanf("%d",&aBorrar);
	}while((aBorrar>=fil) || (aBorrar<0));

	matriz=eliminaFila(matriz,fil,col,aBorrar);

	imprimeMatriz(matriz,fil-1,col,"\nMatriz Menos Uno");

	liberaMemoria(&matriz,fil-1);

	if(matriz==NULL){
		printf("\nMemoria liberada correctamente\n");
	}	

return 0;
}
