#ifndef EJ4_H
#define EJ4_H

int ** reservaMemoria(int f,int c);
void rellenaMatriz(int ** matriz, int f, int c);
void imprimeMatriz(int ** matriz,int f,int c,char * mensaje);
int ** eliminaFila(int ** matriz,int f, int c, int fb);
void liberaMemoria(int *** matriz, int f);

#endif
