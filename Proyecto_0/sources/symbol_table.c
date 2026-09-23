#include <stdio.h>
#include <string.h>
#include "../headers/symbol_table.h"
#include "../headers/generate.h"

// numero arbitrario
#define MAX_SYMBOLS 1000

// arreglo para los nombres de los símbolos
string symbol_table[MAX_SYMBOLS];
int symbol_amount = 0;

void check_id(string s)  {
    if ( ! lookup(s)) {
        enter(s);
        generate("Declare", s, "Integer", "");
    }
}


// "lookup() will check whether an entry named s is in the symbol table. 
// We will not need to store anything except the name of a symbol in the symbol table."
// retorna 1 si se encontró el símbolo, 0 si no
int lookup(string s) {

    // recorrer todos los simbolos almacenados
    for (int i = 0; i < symbol_amount; i++) {

        // simbolo actual == simbolo que se busca?
        if (strcmp(symbol_table[i], s) == 0) // strcmp devuelve 0 si son iguales
            return 1; // si se encuentra el simbolo
    }

    return 0;
}

// "enter() will enter string s into the symbol table unconditionally.""
void enter(string s) {
    // hay espacio en la tabla?
    if (symbol_amount < MAX_SYMBOLS) { 

        // copiar nombre del simbolo en la siguiente posicion
        strcpy(symbol_table[symbol_amount], s);
        symbol_amount++;
    }
}