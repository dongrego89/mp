main.exe: main.c funciones2.c libMatrices.a
	gcc -g -c main.c funciones2.c
	gcc -o main.exe main.o funciones2.o libMatrices.a
clean:funciones.o main.o
	rm *.o


