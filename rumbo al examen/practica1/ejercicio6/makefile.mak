main.exe: main.c funciones.c
	gcc -c main.c funciones.c
	gcc -o main.exe funciones.o main.o
