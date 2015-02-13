#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void calculaEstadisticas(float * notas, float * media, float * maxima, float * minima);
float calculaMaxima(float * notas);
float calculaMinima(float * notas);
float calculaMedia(float * notas);

int main(){

float media, maxima, minima, notas[50];
int i;

srand(time(NULL));

for(i=0;i<50;i++){
	notas[i]=(float)(rand()%1000) / 100;
	printf("%9.9s%2d: %2.2f","\n\tNOTA ",i+1,notas[i]);
}

calculaEstadisticas(notas,&media,&maxima,&minima);

printf("\n\n\tMedia: %2.2f",media);
printf("\n\tMaxima: %2.2f",maxima);
printf("\n\tMinima: %2.2f\n",minima);

return 0;
}


float calculaMaxima(float * notas){
		int i;
		float auxiliar=0;

		for(i=0;i<50;i++){
			if(notas[i]>auxiliar){
				auxiliar=notas[i];
			}			
		}	

		return auxiliar;
	
}
float calculaMinima(float * notas){
		int i;
		float auxiliar=10;

		for(i=0;i<50;i++){
			if(notas[i]<auxiliar){
				auxiliar=notas[i];
			}			
		}	
		return auxiliar;

}
float calculaMedia(float * notas){
		int i;
		float auxiliar=0;

		for(i=0;i<50;i++){
			auxiliar+=notas[i];
		}	

		return auxiliar/50;
}

void calculaEstadisticas(float * notas, float * media, float * maxima, float * minima){
	*media=calculaMedia(notas);
	*minima=calculaMinima(notas);
	*maxima=calculaMaxima(notas);
}
