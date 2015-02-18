float a = 0.001; // &a=1130
float b = 0.003; // &b=1134
float c //1138
float *pa, *pb

pa = &a;
*pa = 2 * a;
pb = &b;
c = 3 * (*pb # *pa ); 

Si el valor asignado a “a” empieza en la dirección 1130 (hexadecimal) y el valor asignado a “b”
empieza en 1134 y el valor asignado a “c” empieza en 1138, entonces:

a) ¿Qué valor es representado por &a? //1130
b) ¿Qué valor es representado por &b? //1134
c) ¿Qué valor es representado por &c? //1138
d) ¿Qué valor es asignado a pa? //1130
e) ¿Qué valor es representado por *pa? 2 * 0.001
f) ¿Qué valor es representado por &(*pa)?
g) ¿Qué valor es asignado a pb?
h) ¿Qué valor es representado por *pb?
i) ¿Qué valor es asignado a c?
