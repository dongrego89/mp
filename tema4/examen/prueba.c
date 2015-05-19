#include<stdio.h>
#include<string.h>

struct emp{
	char nombre[200];
	char apellidos[100];
};

typedef struct emp empleado;


int main(){
int num;
fscanf(stdin,"%d",num);
printf("%d",num);
/* POSIBLE EJERCICIO
	FILE * fichero;
	empleado aux_empleado;

	fichero=fopen("empleados.bin","w");

	strcpy(aux_empleado.nombre,"Ursula");
	strcpy(aux_empleado.apellidos,"Goldwing Meyer");
	
	fwrite(&aux_empleado,sizeof(empleado),1,fichero);

	fclose(fichero);
	

	fichero=fopen("empleados.bin","w");

	fread(&aux_empleado,sizeof(empleado),1,fichero);

	printf("\n%s %s",aux_empleado.nombre, aux_empleado.apellidos);

	fclose(fichero);

FIN DE POSIBLE EJERCICIO*/


	/*char nombre[200],caracter;
	int numero=5;
	FILE * binario;
	printf("\n[%p]\n%d",fgets(nombre,200,stdin),(int)sizeof(int));
	fputs(nombre,stdout);
	caracter=getchar();
	if(caracter==EOF){
		printf("fin");
	}
	else{
		printf("else pataki");
	}
	
	binario=fopen("archivo.bin","a");

	fwrite(&numero,sizeof(int),1,binario);
	
	fclose(binario);
	
	binario=fopen("archivo.bin","r");
	
	fread(&numero,sizeof(int),1,binario);

	printf("%d",numero);

	fclose(binario);*/



return 0;
}
