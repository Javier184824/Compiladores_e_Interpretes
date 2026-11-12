typedef int Entero;
typedef Entero Otro;
typedef int *Puntero;
typedef int (*Operacion)(int);
typedef int Primero, Segundo;

Entero x;
Otro y;
Puntero p;
Operacion op;
Primero a;
Segundo b;

int f(void) {
    return sizeof(Entero);
}