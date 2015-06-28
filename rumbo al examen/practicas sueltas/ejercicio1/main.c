#include<stdio.h>
#include<stdlib.h>

#include "binario.h"
#include "texto.h"

int main(int argc, char ** argv){

	system("clear");

	int codigo;
	float precio;

	if(argc!=3){
		printf("\n El formato de ejecución de esta aplicacion es: \n\t %s [FICHERO.BIN] [FICHERO.TXT] \n",argv[0]);
		exit(-1);
	}

	binarioTexto(argv[1],argv[2]);
	
	printf("\nIntroduce el codigo del producto a modificar: ");
	scanf("%d",&codigo);
	getchar();
	
	printf("\nIntroduce el precio del producto a modificar: ");
	scanf("%f",&precio);
	getchar();

	switch(modificaPrecio(argv[1],codigo,precio)){
		case 1:
			printf("\nSe modifico el precio del producto con codigo %d a %.2f\n",codigo,precio);
		break;
		case -1:
			printf("\nNo se encontró el producto con codigo %d en el fichero\n",codigo);
		break;
		case -2:
			printf("\nError en la apertura del fichero binario\n");
			exit(-1);
		break;
		
	}

	return 0;
}
