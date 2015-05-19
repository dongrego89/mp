#ifndef CONJUNTOS_H
#define CONJUNTOS_H

struct elem{
	struct elem * siguiente;
	int valor;
};

typedef struct elem elemento;//Alias para acortar

elemento * reservaMemoria(); //Reservar memoria de tipo elemento
int introduceElemento(elemento ** cabeza, int valor);//Introducir elementos a conjunto
void imprimeConjunto(elemento * cabeza, char * mensaje);//Imprimir conjunto con un mensaje de cabecera
int perteneceConjunto(elemento * cabeza,int valor);//Comprueba si un elemento está en un conjunto devolviendo 1 para SI y 0 para NO
int estaVacio(elemento * cabeza); //Comprueba si el conjunto está vacío devolviendo 1 para SI y 0 para NO 
int cuentaElementos(elemento * cabeza); //Devuelve el número de elementos existentes en un conjunto
elemento * uneConjuntos(elemento * conjuntoA, elemento * conjuntoB); //Devuelve un puntero a lista con el conjunto UNION de 2 conjuntos
elemento * intersectaConjuntos(elemento * conjuntoA, elemento * conjuntoB);//Devuelve un puntero a lista con el conjunto INTERSECCION de 2 conjuntos

#endif
