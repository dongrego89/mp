#include<stdio.h>

int main(){

int a,*b,**c;
double d,*e,**f;

system("clear");

printf("\nEl tamaño de a: %d, b: %d, c: %d",sizeof(a),sizeof(b),sizeof(c));
printf("\nEl tamaño de d: %d, e: %d, f: %d\n",sizeof(d),sizeof(e),sizeof(f));

return 0;
}
