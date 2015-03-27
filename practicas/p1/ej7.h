#ifndef EJ7_H
#define EJ7_H

float * reservaMemoria(int numExamenes);
void rellenaExamenes(float * examenes,int numExamenes);
void imprimeNotas(char * titulo,float * examenes,int numExamenes);

void calculaMedia(float * examenes, int numExamenes, float * mediaA, float * mediaB);
void calculaMax(float * examenes, int numExamenes, float * maxA, float * maxB);
void calculaMin(float * examenes, int numExamenes, float * minA, float * minB);

#endif
