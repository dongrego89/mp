main.exe: main.c binario.c texto.c
	gcc -g -c main.c binario.c texto.c
	gcc -o main.exe binario.o texto.o main.o
clean: main.o binario.o texto.o
	rm *.o
