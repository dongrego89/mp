main.exe:main.c funciones.c
	gcc -c -g main.c funciones.c
	gcc -o main.exe main.o funciones.o

