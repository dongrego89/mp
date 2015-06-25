main.exe: main.c funciones.c
	gcc -c -g funciones.c main.c
	gcc -o main.exe main.c funciones.c
clean: main.o funciones.o
	rm *.o
