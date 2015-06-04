#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
char titulo[256];
char autor[256];
float precio;
int unidades;
}libro;

struct n{
	libro contenido;
	struct n * siguiente;
}; 

typedef struct n nodo;//Alias para struct elemento

int compruebaFichero(char * nombre);
nodo * reservaMemoria();//Reserva memoria para un elemento de la lista
void nuevoNodo(nodo ** cabeza, libro elemento);//Inserta un nuevo elemento en una lista
void cargaFicheroEnLista(char * nombre, nodo ** cabeza);//Carga los datos del fichero en la lista
void imprimeLista(nodo * cabeza);//Imprime recursivamente la lista
void separaPorPrecio(nodo * cabeza,nodo ** mayores, nodo ** menores,float precio);//Separa en dos listas los items mayores y menores de la lista principal
void cargaListaEnFichero(char * nombre, nodo * cabeza);//Vuelca en un fichero binario una lista

#endif
