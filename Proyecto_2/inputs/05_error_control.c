/*
Comentario
Comentario
Comentario
Comentario
Comentario
*/


// Comentarario
int sumar(int a, int b) {
    return a + b;
}
/*
Comentario
Comentario
Comentario
Comentario
Comentario
*/
int main(void) {
    int total = ;
    int datos[5] = {1, 2, 3, 4, 5};
    int i;
    for (i = 0; i < 5; i++) {
        total += datos[i];
    }
    if (total > 10) {
        total = sumar(total,, 2);
    } else {
        total -= 2;
    }
    while (total > 10) {
        total -= ;
    }
    do {
        total = (total + 1;
    } while (total < 12);
    switch (total) {
        case 12: total += 1; break;
        default: total = 0; break;
    }
    total = total > 0 ? : 1;
    total = (total * ) / 2;
    return total == 13 ? 0 : 1;
}
