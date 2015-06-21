main.exe:main.c ficheros.c crucigrama.c libMemoria.a
	gcc -c ficheros.c crucigrama.c main.c
	gcc ficheros.o crucigrama.o main.o libMemoria.a -o main.exe

libMemoria.a:liberaMemoria.c reservaMemoria.c
	gcc -c liberaMemoria.c reservaMemoria.c
	ar -rsv libMemoria.a liberaMemoria.o reservaMemoria.o
clean:
	rm *.o
