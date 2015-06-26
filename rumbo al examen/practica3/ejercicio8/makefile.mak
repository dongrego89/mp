main.exe: funciones.c main.c
	gcc -c -g funciones.c main.c
	gcc -o main.exe main.o funciones.o
clean: funciones.o main.o
	rm *.o
