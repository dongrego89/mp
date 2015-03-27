#include<stdio.h>

int main(){

int a=2,b=3,c=3;

int matrizA[2][3]={{3,3,4},{2,3,4}};
int matrizB[3][3]={{2,3,3},{5,4,2},{5,4,3}};
int matrizC[2][3];

int i,j,k,sumatorio;

for(i=0;i<a;i++){
	for(j=0;j<c;j++){
		sumatorio=0;
		for(k=0;k<b;k++){
			sumatorio=matrizA[i][j]*matrizB[i][k];
		}
		matrizC[i][j]=sumatorio;
	}
}

for(i=0;i<a;i++){
	printf("\n");
	for(j=0;j<b;j++){
		printf("[%d]",matrizC[i][j]);	
	}
	printf("\n");
}

return 0;
}
