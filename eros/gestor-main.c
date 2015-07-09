#include<stdio.h>

#include "funciones.h"

int main(int argc, char ** argv){

	int bandera=0,numPuntos,opcion;
	char codCliente[MAX_CHAR];

	system("clear");

	do{
		if(bandera==1){
			printf("\nClave erronea..");
		}
		if(bandera==0){
			bandera=1;
		}
	}while(loginUsuario()!=0);

	printf("\nIntroduce el codigo de usuario: ");
	scanf("%s",codCliente);
	getchar();

	printf("\nIntroduce el numero de puntos: ");
	scanf("%d",&numPuntos);
	getchar();

	do{
		opcion=menu();
		
		switch(opcion){
			case 1:
				if(sumaPuntos(codCliente,+numPuntos)==1){
					printf("\n\tSaldo de puntos actualizado correctamente...\n");
				}
				else{
					printf("\n\tError abriendo ficheros...\n");
				}
			break;
			case 2:
				if(sumaPuntos(codCliente,-numPuntos)==1){
					printf("\n\tSaldo de puntos actualizado correctamente...\n");
				}
				else{
					printf("\n\tError abriendo ficheros...\n");
				}
			break;
			case 3:
				return 0;
			break;
			default:
				printf("\nOpcion no contemplada...");
			break;
		}

		getchar();

	}while(opcion!=3);


	return 0;
}
