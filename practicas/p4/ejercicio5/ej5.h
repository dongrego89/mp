#ifndef EJ5_H
#define EJ5_H

struct mo{
	struct mo * siguiente;
	int coeficiente;
	int exponente;
};

typedef struct mo monomio;


monomio * reservaMemoria();//Reserva de memoria para un nuevo elemento de monomio
void pushFront(monomio ** cabeza, int c, int e); //Cabeza de la lista, coeficiente y exponente
/*void eliminaMonomio(monomio ** cabeza, int e); //Exponente a buscar y eliminar
*/
float evaluaPolinomio(monomio * polinomio,float x);
void muestraPolinomio(monomio * polinomio);

#endif
