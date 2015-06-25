#ifndef FUNCIONES_H
#define FUNCIONES_H

int ** reservarMemoria (int nFil, int nCol);
void rellenaMatriz (int **matriz, int nFil, int nCol);
void imprimeMatriz (int **matriz, int nFil, int nCol);
int ** eliminarFila (int **matriz, int nFil, int nCol, int fila_borrada);
void liberarMemoria(int ***matriz, int nFil);

#endif
