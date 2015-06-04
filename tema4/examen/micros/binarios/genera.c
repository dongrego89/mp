/* ----------------------------------------------------------
   Codigo para generar un fichero binario de libros a partir
   de los datos en un fichero de texto
   
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

void convierteBinario(char * texto, char * binario);
void imprimeLibro(struct libro libro) ;

int main(int argc, char * argv[]) {
   
   char origen[256];
   char destino[256];
   
   if (argc!=3) {
      printf("Sintaxis incorrecta: %s <origen:fichero_texto> <destino:fichero_binario>\n",argv[0]);
      exit(-1);
   }
   
   strcpy(origen, argv[1]);
   strcpy(destino, argv[2]);
   
   convierteBinario(origen,destino);
   
   
   return 0;
}

/* ------------------------------------------------------
   Función que lee los registros de un fichero de texto
   y los vuelca a uno binario
   
   Se le pasa:  texto -> nombre del fichero de texto
                binario -> nombre del fichero binario
   Devuelve: nada
   Utiliza: nada
   -----------------------------------------------------*/
void convierteBinario(char * texto, char * binario){
   FILE * fT, * fB;
   struct libro reg;
   int leido;
   
   fT=fopen(texto,"r");
   if (fT==NULL){
      printf("El fichero <%s> no existe\n",texto);
      exit(-1);
   }
   
   fB=fopen(binario,"wb");
   if (fB==NULL){
      printf("Se ha producido un error al abrir el fichero <%s> en \"convierteBinario\"\n",binario);
      exit(-1);
   }
   
   //Lectura adelantada
   fgets(reg.titulo, 256, fT);
   fgets(reg.autor,256, fT);
   leido=fscanf(fT,"%f %d\n",&(reg.precio),&(reg.unidades));
   
   while(leido==2) {
      //Convertimos a binario
      fwrite(&reg,sizeof(struct libro), 1, fB);
     
      fgets(reg.titulo, 256, fT);
      fgets(reg.autor,256, fT);
      leido=fscanf(fT,"%f %d\n",&(reg.precio),&(reg.unidades));
     
   }
  
   fclose(fB);
   fclose(fT); 
}   
/* -----------------------------------------------
   Función que imprime por pantalla un registro
   
   Se le pasa: libro -> registro a imprimir
   Devuelve: nada
   Utiliza: nada
-------------------------------------------------*/
void imprimeLibro(struct libro libro) {
   printf("--------------------------------------------------\n");
   printf(" Titulo: %s\n",libro.titulo);
   printf(" Autor: %s\n",libro.autor);
   printf(" Precio: %.2f\n",libro.precio);
   printf(" Unidades: %d\n",libro.unidades);
   printf("--------------------------------------------------\n");
}
