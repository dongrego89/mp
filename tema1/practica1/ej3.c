int i, j = 25;
int *pi, *pj = &i:
*pj = j + 5;
i = *pj + 5:
pi = pj;
*pi = i + j;

Si el valor asignado a i empieza en la dirección F9C (hexadecimal) y el valor asignado a j empieza
en FE9 entonces:

a) ¿Qué valor es representado por &i? //La direccion de memoria de la variable entera i F9C 
b) ¿Qué valor es representado por &j? //La direccion de memoria de la variable entera j FE9
c) ¿Qué valor es asignado a pj? //F9C 
d) ¿Qué valor es asignado a *pj? //30
e) ¿Qué valor es asignado a i? //35 
f) ¿Qué valor es representado por pi? //F9C 
g) ¿Qué valor es asignado a *pi? //35+25=60
h) ¿Qué valor es representado por la expresión (*pi + 2)? // 62
