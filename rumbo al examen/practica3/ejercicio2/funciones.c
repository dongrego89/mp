#include "funciones.h"


int cuentaPares(int numero){
	int pares=0;

	if(numero>=10){
		if(((numero%10)%2==0) && (numero%10)!=0){//Si el digito es par y distinto de cero
			pares=1;
		}
		return pares+cuentaPares(numero/10);
	}
	else{//El numero es menor que diez, por tanto es la ultima iteración
		if(((numero%10)%2==0) && (numero%10)!=0){//Si el digito es par y distinto de cero
			return 1;
		}
		return 0;
	}
}
