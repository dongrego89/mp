#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*
imprimeVector
Se utiliza para imprimir un vector con un título
Parametros:
Titulo, Vector, Limite de elementos
*/
void imprimeVector(char * titulo, int * v, int limite);

/*
separaMayoresMenores
Se utiliza para separar los numeros mayores de los menores o iguales de un vector, en un vector de mayores y otros de menores o iguales
Parametros:
Vector a analizar, numero de elementos de ese vector, numero de corte, puntero al vector de mayores, puntero al vector de menores, puntero al numero de elementos del vector mayor y puntero al numero de elementos del vector menor
*/
void separaMayoresMenores(int * vector, int elementos, int numero, int * mayores, int * menores, int * may, int * men);

int main(int argc, char ** argv){

	system("clear");

	int * mayores=NULL, * menores=NULL, * vector=NULL, numero, may=0, men=0;
	int i;

	if(argc!=2){ // Validacion de argumento del tamaño del vector aleatorio
		printf("ERROR AL INVOCAR AL PROGRAMA\n\t'PROGRAMA [N ELEMENTOS ARRAY]'\n");
		exit(-1);
	}

	vector=(int *)malloc(sizeof(int)*atoi(argv[1]));
	mayores=(int *)malloc(sizeof(int));
	menores=(int *)malloc(sizeof(int));
	
	
	srand(time(NULL));

	for(i=0;i<atoi(argv[1]);i++){
		vector[i]=rand()%100;
	}

	
	imprimeVector("VECTOR PRINCIPAL: ",vector,atoi(argv[1]));

	printf("\nIntroduce el numero de corte: ");
	scanf("%d",&numero);

	separaMayoresMenores(vector,atoi(argv[1]),numero,mayores,menores,&may,&men);	
	imprimeVector("VECTOR MAYORES: ",mayores,may);
	imprimeVector("VECTOR MENORES: ",menores,men);

	free(vector);
	free(mayores);
	free(menores);

	return 0;
}

void separaMayoresMenores(int * vector, int elementos, int numero, int * mayores, int * menores, int * may, int * men){
	int i;
	
	for(i=0;i<elementos;i++){
		if(vector[i]>numero){		
			if((mayores=realloc(mayores,sizeof(int)*((*may)+1)))==NULL){
				//exit(-1);//No se pudo relocalizar la memoria
			}
			mayores[*may]=vector[i];
			*may=*may+1;
		}
		else{
			if((menores=realloc(menores,sizeof(int)*((*men)+1)))==NULL){
				//exit(-1);//No se pudo relocalizar la memoria
			}
			menores[*men]=vector[i];
			*men=*men+1;
		}
	}

}


void imprimeVector(char * titulo, int * v, int limite){
	int i;
	printf("\n%s ",titulo);
	for(i=0;i<limite;i++){
		printf("[%.2d]",v[i]);	
	}
	printf("\n");
}
