main.exe: main.c funciones.c
	gcc -g -c main.c funciones.c
	gcc -o main.exe main.c funciones.o
clean: main.o funciones.o
	rm *.o
