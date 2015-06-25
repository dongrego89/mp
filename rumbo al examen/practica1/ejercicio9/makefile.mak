main.exe: funciones.o main.c
	gcc -c -g main.c
	gcc -o main.exe funciones.o main.o
funciones.o: funciones.c
	gcc -c -g funciones.c
clean: funciones.o main.o
	rm *.o
