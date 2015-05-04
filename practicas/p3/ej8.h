#ifndef EJ8_H
#define EJ8_H

#define BBDD "registro_libreria.txt"
#define MAX_CHAR 900
#define MAX_FILENAME 250

typedef struct{
	char titulo[MAX_CHAR];
	char autor[MAX_CHAR];
	float precio;
	int unidades;
}registro;
	

int compruebaLibro(char * titulo);
void introduceLibro(registro libro);
int cuentaLibros();
registro * reservaMemoria(int regs);
void vuelcaFichero(registro * vector);
void listaLibros(registro * vector, int regs);
int vendeLibro(char * titulo);
void borraCero();


#endif
