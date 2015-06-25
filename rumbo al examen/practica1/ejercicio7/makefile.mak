main.exe: funciones.c main.c
	gcc -c funciones.c main.c
	gcc -o main.exe funciones.o main.o
