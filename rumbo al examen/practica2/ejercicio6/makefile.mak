main.exe: main.c libMatrices.a
	gcc -g -c main.c
	gcc -o main.exe main.o libMatrices.a
clean:funciones.o main.o
	rm *.o
libMatrices.a:funciones.c
	gcc -g -c funciones.c
	ar -rsv libMatrices.a funciones.o

