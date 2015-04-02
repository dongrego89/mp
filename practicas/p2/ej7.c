#include "ej7.h"

void multiplica(int ** a,int fa, int ca, int ** b, int fb, int cb, int ** mc, int fc, int cc){
	int i,j,k,sumatorio;

	for(i=0;i<fa;i++){
		for(j=0;j<cb;j++){
			sumatorio=0;
			for(k=0;k<ca;k++){
				sumatorio+=(a[i][k] * b[k][j]);
			}
			mc[i][j]=sumatorio;
		}
	}

}

