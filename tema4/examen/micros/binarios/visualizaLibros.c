/* ----------------------------------------------------------
   Codigo para visualizar el contenido de un fichero binario
   que contiene información sobre libros:
   Titulo
   Autor
   Precio, unidades.
   
   Junio 2014
   -----------------------------------------------------------*/
   
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura para almacenar los libros en el fichero

struct libro {
   char titulo[256];
   char autor[256];
   float precio;
   int unidades;
};

void visualiza(char * nombre);
void imprimeLibro(struct libro libro);

int main(int argc, char * argv[]) {

   char fichero[256];
   
   if (argc!=2){
      printf("Sintaxis incorrecta: %s <archivo binario>\n",argv[0]);
      exit(-1);
   }
   
   strcpy(fichero,argv[1]);
   
   visualiza(fichero);
   
   return 0;
}

/* -----------------------------------------------
   Función que visualiza por pantalla un fichero
   binario de libros
   
   Se le pasa: nombre -> fichero a visualizar
   Devuelve: nada
   Utiliza: imprimeLibro
   -----------------------------------------------*/
void visualiza(char * nombre){
   FILE * f;
   struct libro reg;
   int cont=1;
   
   f=fopen(nombre,"r");
   if (f==NULL){
      printf("El fichero <%s> no existe\n",nombre);
      exit(-1);
   }
   
   fread(&reg,sizeof(struct libro), 1, f);
   while (!feof(f)){
      imprimeLibro(reg);
      fread(&reg,sizeof(struct libro), 1, f);
   }   
   
   fclose(f);
}


/* -----------------------------------------------
   Función que imprime por pantalla un registro
   
   Se le pasa: libro -> registro a imprimir
   Devuelve: nada
   Utiliza: nada
-------------------------------------------------*/
void imprimeLibro(struct libro libro) {
   printf("\n--------------------------------------------------\n");
   printf(" Titulo: %s",libro.titulo);
   printf(" Autor: %s",libro.autor);
   printf(" Precio: %.2f\n",libro.precio);
   printf(" Unidades: %d\n",libro.unidades);
   printf("--------------------------------------------------\n");
}
