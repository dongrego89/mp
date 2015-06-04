#Makefile para el proyecto

main.exe:funciones.c main.c
	@echo Compilando main.exe
	@gcc -g -o $@ $^
clean:main.exe
	@echo Quitando el main.exe
	@rm main.exe
