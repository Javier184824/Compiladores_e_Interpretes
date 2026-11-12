/* 
 * Archivo de prueba con multiples errores sintacticos, lexicos y semanticos 
 * Diseñado para poner a prueba analizadores sintacticos (parsers) en C.
 */

#include <stdio.h>
#include <stdlib.h>

// Variable global con tipo faltante o mal declarado
global_var = 105;

// Estructura mal declarada (falta punto y coma al final)
struct Persona {
    char nombre[50];
    int edad
}

int x

int;

int{};

x = 2;


// Prototipo de funcion con parametros invalidos
void calcular_promedio(int a, float b, );


// Funcion principal con multiples errores
int main(void) {
    
    // Declaraciones de variables mal escritas
    int x = 10;
    float y = 20.5;
    char letra = 'A';
    doubl z = 99.9; // Tipo inexistente o mal escrito
    
    // Sentencia if mal estructurada (faltan parentesis o llave abierta)
    if x > y {
        printf("X es mayor\n")
    } else {
        printf("Y es mayor o igual\n");
    
    // Bucle for con sintaxis incompleta (falta expresion de incremento)
    for (int i = 0; i < 10; i++) {
        x += i;
    
    // Bucle while con asignacion en lugar de comparacion y parentesis mal cerrados
    while (x = 5 {
        x--;
    
    // Switch con casos mal formateados (faltan dos puntos o saltos)
    switch (letra) {
        case 'A'
            printf("Letra A\n");
            break;
        case 'B':
            printf("Letra B\n");
            // Falta el break o llave de cierre del switch
            
    // Llamada a funcion con argumentos mal separados por comas dobles
    calcular_promedio(x,, y);
    
    // Uso de operador invalido o desconocido
    int resultado = x # y;
    
    // Cadena de texto sin cerrar correctamente
    char *mensaje = "Esta cadena nunca cierra;
    
    // Expresion matematica mal formada
    int calculo = (10 + 5 * (2 - );
    
    // Retorno con error de sintaxis (falta punto y coma y valor invalido)
    return 0
}

// Funcion extra mal estructurada al final
void funcion_rota( {
    int a = 5;
    int b = 10;
    
    // Operador ternario incompleto
    a > b ? printf("Mayor") : ;
    
    // Uso ilegal de palabra reservada como identificador
    int return = 42;
    
    // Comentario multininea sin cerrar
    /* Este comentario se queda abierto hasta el infinito y mas alla...