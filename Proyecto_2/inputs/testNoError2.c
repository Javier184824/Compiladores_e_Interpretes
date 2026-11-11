/* 
- Archivo corregido a partir de la prueba con múltiples errores sintácticos, léxicos y semánticos.
- Diseñado para compilar correctamente en C.
 */

#include <stdio.h>
#include <stdlib.h>

// Variable global con tipo declarado correctamente
int global_var = 105;

// Prototipo de función con parámetros válidos (eliminada la coma colgante)
void calcular_promedio(int a, float b);

// Implementación de la función auxiliar
void calcular_promedio(int a, float b) {
    float promedio = (a + b) / 2.0f;
    printf("Promedio: %.2f\n", promedio);
}

// Función principal corregida
int main(void) {
    
    // Declaraciones de variables corregidas
    int x = 10;
    float y = 20.5f;
    char letra = 'A';
    double z = 99.9; // Tipo corregido de 'doubl' a 'double'
    
    // Sentencia if corregida (con paréntesis y llaves bien cerradas)
    if (x > y) {
        printf("X es mayor\n");
    } else {
        printf("Y es mayor o igual\n");
    }
    
    // Bucle for corregido con sus llaves cerradas
    for (int i = 0; i < 10; i++) {
        x += i;
    }
    
    // Bucle while corregido (comparación correcta y paréntesis cerrados)
    while (x == 5) {
        x--;
    }
    
    // Switch corregido (casos bien formateados y llaves cerradas)
    switch (letra) {
        case 'A':
            printf("Letra A\n");
            break;
        case 'B':
            printf("Letra B\n");
            break;
        default:
            break;
    }
    
    // Llamada a función con argumentos separados correctamente (sin coma doble)
    calcular_promedio(x, (int)y);
    
    // Operador inválido '#' reemplazado por una operación válida (ej. suma o máscara)
    int resultado = x + 2; 
    
    // Cadena de texto cerrada correctamente
    char *mensaje = "Esta cadena ahora sí cierra";
    printf("%s\n", mensaje);
    
    // Expresión matemática bien formada
    int calculo = (10 + 5 * (2 - 1));
    
    // Función extra integrada o llamada si es necesario, o corregida su definición fuera de main.
    // (Nota: Las funciones en C no se anidan, por lo que 'funcion_rota' se define fuera de main).

    // Retorno con sintaxis correcta
    return 0;
}

// Función extra estructurada correctamente fuera de main
void funcion_rota(void) {
    int a = 5;
    int b = 10;
    
    // Operador ternario completado correctamente
    a > b ? printf("Mayor\n") : printf("Menor o igual\n");
    
    // Uso de un identificador válido (evitando la palabra reservada 'return')
    int mi_return = 42;
    (void)mi_return;
    
    /* Este comentario multininea ahora está cerrado correctamente */
}