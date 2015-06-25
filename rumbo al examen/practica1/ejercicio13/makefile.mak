main.exe: main.c funciones.c
	gcc -c -g funciones.c main.c
	gcc -o main.exe funciones.o main.o
clean: funciones.o main.o
	rm *.o
