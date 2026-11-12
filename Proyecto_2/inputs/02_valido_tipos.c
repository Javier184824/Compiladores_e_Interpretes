/*
Prueba 2
*/

typedef int Entero;
typedef int (*Operacion)(int, int);
struct Punto {
    int x;
    int y;
};
union Numero {
    int entero;
    double real;
};
enum Estado { APAGADO, ENCENDIDO = 3, PAUSA };
int sumar(int a, int b) {
    return a + b;
}
int main(void) {
    Entero valor = 4;
    struct Punto punto = {.x = 2, .y = 3};
    struct Punto *ptr = &punto;
    union Numero numero = {.entero = 7};
    enum Estado estado = ENCENDIDO;
    int tabla[2][2] = {{1, 2}, {3, 4}};
    int *p = &valor;
    Operacion op = sumar;
    const char *texto = "hola " "mundo";
    char letra = 'A';
    double decimal = 2.5e1;
    unsigned int mascara = 0x0FU;
    valor = op(ptr->x, punto.y);
    *p += tabla[1][0];
    mascara = (mascara << 1) | 1U;
    valor += (int)sizeof(struct Punto);
    valor += (int)decimal;
    if (estado == ENCENDIDO && numero.entero > 0) {
        valor += texto[0] == 'h' && letra == 'A';
    }
    return valor > 0 && mascara > 0 ? 0 : 1;
}
