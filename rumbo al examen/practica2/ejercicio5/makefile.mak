main.exe: main.c funciones.c
	gcc -c -g main.c funciones.c
	gcc -o main.exe funciones.o main.o
clean: main.o funciones.o
	rm *.o
