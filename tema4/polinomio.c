#include<stdio.h>
#include<stdlib.h>
#include<math.h> // Necesitaremos incluir la librería math.h en la compilación usando -lm

struct mono{
	struct mono * siguiente;
	int coeficiente;
	int exponente;
};

typedef struct mono monomio;

monomio * nuevoMonomio();
void pushBack(monomio ** cabeza,int c, int e); //Añadir a lista
void imprimePolinomio(monomio * cabeza, char * mensaje); //Visualizar polinomio
int resuelvePolinomio(monomio * cabeza, int x); //Resolver el polinomio sustituyendo los valores de las incógnitas


int main(){
	int terminos,i,coeficiente,x;
	monomio * polinomio=NULL;

	printf("Introduce el numero de terminos del polinomio: ");
	scanf("%d",&terminos);
	
	for(i=0;i<terminos;i++){ //
		printf("Introduce el coeficiente para x^%d : ",i);
		scanf("%d",&coeficiente);
	
		pushBack(&polinomio,coeficiente,(int)i);// Añade a la lista polinomio el monomio coeficiente * x ^ i
	}

	imprimePolinomio(polinomio, "Mostrando polinomio: ");

	printf("\nIntroduce el valor de x en el polinomio: ");
	scanf("%d",&x);

	printf("\nLa solución del polinomio es %d\n",resuelvePolinomio(polinomio,x));

return 0;
}


void pushBack(monomio ** cabeza,int c, int e){

	monomio * nuevo=NULL, * auxiliar=NULL;

	nuevo=nuevoMonomio(); //Reservamos memoria para el nuevo monomio
	
	nuevo->coeficiente=c; //Rellenamos coeficiente
	nuevo->exponente=e; //Rellenamos exponente
	nuevo->siguiente=NULL; //Rellenamos exponente

	if(*cabeza==NULL){//Si la lista estaba vacía, simplemente rellenamos la posición de inicio con la de el elemento nuevo
		*cabeza=nuevo;
	}
	else{ //Si la lista no está vacía, hay que buscar el último elemento (aquel que tenga siguiente==NULL y hacer que apunte al nuevo monomio

		auxiliar=*cabeza;//Guardamos el primer monomio en la variable auxiliar para poder recorrer la lista apoyándonos en ella

		while(auxiliar->siguiente!=NULL){
			auxiliar=auxiliar->siguiente;
		}
		//Una vez auxiliar->siguiente == NULL, nos hemos localizado en el último elemento. Basta con asignarle la dirección del nuevo monomio.
		auxiliar->siguiente=nuevo;
	}
}

monomio * nuevoMonomio(){
	monomio * puntero=NULL;

	puntero=(monomio *)malloc(sizeof(monomio));//Reservamos espacio par aun elemento del tipo struct monomio

	if(!puntero){//Si no se puede reservar memoria rompemos la secuencialidad
		printf("\nError reservando memoria para este monomio\n");
		exit(-1);
	}
	return puntero;
}


void imprimePolinomio(monomio * cabeza, char * mensaje){

	monomio * auxiliar=cabeza;
	int bandera=0;

	printf("\n%s\n",mensaje);

	while(auxiliar!=NULL){//Mientras no lleguemos al ultimo monomio
		if(bandera==0){
			bandera=1;
		}
		else{
			printf(" + ");
		}
		printf("%dx^%d",auxiliar->coeficiente,auxiliar->exponente);

		auxiliar=auxiliar->siguiente;//Preparamos el puntero al siguiente monomio de la lista
	}
	

	printf("\n");

}

int resuelvePolinomio(monomio * cabeza, int x){
	monomio * auxiliar=cabeza;
	int resultado=0;
	
	while(auxiliar!=NULL){
		resultado+=auxiliar->coeficiente * (int)pow(x,auxiliar->exponente);
		
		printf("%d * %d ^ %d = %d \n",auxiliar->coeficiente,x,auxiliar->exponente,auxiliar->coeficiente * (int)pow(x,auxiliar->exponente));

		auxiliar=auxiliar->siguiente;//Preparamos el puntero al siguiente monomio de la lista
	}

	
	return resultado;

}
