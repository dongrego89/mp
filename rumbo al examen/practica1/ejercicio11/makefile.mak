main.exe: funciones.c main.c
	gcc -c -g main.c funciones.c
	gcc -o main.exe funciones.o main.o
clean:funciones.o main.o
	rm *.o
