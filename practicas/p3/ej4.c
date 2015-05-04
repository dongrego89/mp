#include<stdio.h>

#include "ej4.h"

int productoRecursivo(int * v, int n){
	
	int producto=1;

	if(n>=1){
		producto=producto * v[n-1];
		return producto * productoRecursivo(v,n-1);
	}
	else{
		return producto;
	}

}
