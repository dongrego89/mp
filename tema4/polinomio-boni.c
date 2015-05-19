#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct nodo {
	int a;
	int e;
	struct nodo *sig;
};



//CABEZERA FUNCIONES
struct nodo *nuevoElemento();
void insertarDetras(struct nodo ** cabeza, int a, int e);
void recorrerLista(struct nodo * cabeza);
int recorrerListax(struct nodo * cabeza, int x);



int main (){


	int nterminos,i,a,x,total;
	struct nodo *cabeza=NULL;

	printf("Introduzca el numero de terminos: ");
	scanf("%d",&nterminos);

	struct nodo *v[nterminos];

	for(i=0;i<nterminos;i++){
		printf("Nodo nº: %d\n",i);
		printf("Coeficiente del termino: ");
		scanf("%d",&a);
		insertarDetras(&cabeza,a,i);
	}

	printf("\nMOSTRANDO POLINOMIO...\n\n");
	recorrerLista(cabeza);

	printf("Introduzca el valor de x: ");	
	scanf("%d",&x);

	total=recorrerListax(cabeza,x);

	printf("El total es: %d\n",total);

 return 0;
}





//CUERPO FUNCIONES
struct nodo *nuevoElemento(){

	struct nodo *aux=NULL;

	aux=(struct nodo*)malloc(sizeof(struct nodo));

	return aux;
}






void insertarDetras(struct nodo ** cabeza, int a, int e) {
   struct nodo * nuevo=NULL;
   struct nodo * aux=NULL;

      
   nuevo=nuevoElemento();
   nuevo->a=a;
   nuevo->e=e;
   nuevo->sig=NULL;

   
   if (*cabeza==NULL){   
      *cabeza=nuevo;   

    } else {
      
      aux=*cabeza;
      while(aux->sig!=NULL) {
         aux=aux->sig;
      }
      aux->sig=nuevo;
   }      
}






void recorrerLista(struct nodo * cabeza){
   struct nodo * aux;
   aux=cabeza;

   while(aux!=NULL) {
      printf(" %d(x^%d)+",aux->a,aux->e);
      aux=aux->sig;
   }
 printf("\n");
}



int recorrerListax(struct nodo * cabeza, int x){

	struct nodo *aux;	
	aux=cabeza;
	int total=0;

	while(aux!=NULL){
		total=total+aux->a*(x^aux->e);
		aux=aux->sig;
	}
  return total;
}
