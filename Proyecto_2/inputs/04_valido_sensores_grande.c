typedef struct Lectura {
    int valor;
    int calidad;
} Lectura;
int analizar_canal_01(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 11;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 1;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_02(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 12;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 2;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_03(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 13;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 3;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_04(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 14;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 4;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_05(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 15;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 5;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_06(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 16;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 6;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_07(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 17;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 7;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_08(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 18;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 8;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_09(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 19;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 9;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_10(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 20;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 10;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_11(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 21;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 11;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_12(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 22;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 12;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_13(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 23;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 13;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_14(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 24;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 14;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_15(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 25;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 15;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_16(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 26;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 16;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_17(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 27;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 17;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_18(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 28;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 18;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_19(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 29;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 19;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_20(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 30;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 20;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_21(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 31;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 21;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_22(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 32;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 22;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_23(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 33;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 23;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int analizar_canal_24(const Lectura *lecturas, int cantidad) {
    int suma = 0;
    int validas = 0;
    int i = 0;
    int umbral = 34;
    while (i < cantidad) {
        int valor = lecturas[i].valor;
        if (lecturas[i].calidad <= 0) {
            i++;
            continue;
        }
        if (valor < 0) {
            valor = -valor;
        }
        if (valor > umbral) {
            valor = umbral;
        }
        suma += valor * 24;
        validas++;
        i++;
    }
    if (validas == 0) {
        return 0;
    }
    return suma / validas;
}
int main(void) {
    Lectura lecturas[5] = {{12, 1}, {-4, 1}, {30, 0}, {8, 2}, {5, 1}};
    int resultado = 0;
    resultado += analizar_canal_01(lecturas, 5);
    resultado += analizar_canal_02(lecturas, 5);
    resultado += analizar_canal_03(lecturas, 5);
    resultado += analizar_canal_04(lecturas, 5);
    resultado += analizar_canal_05(lecturas, 5);
    resultado += analizar_canal_06(lecturas, 5);
    resultado += analizar_canal_07(lecturas, 5);
    resultado += analizar_canal_08(lecturas, 5);
    resultado += analizar_canal_09(lecturas, 5);
    resultado += analizar_canal_10(lecturas, 5);
    resultado += analizar_canal_11(lecturas, 5);
    resultado += analizar_canal_12(lecturas, 5);
    resultado += analizar_canal_13(lecturas, 5);
    resultado += analizar_canal_14(lecturas, 5);
    resultado += analizar_canal_15(lecturas, 5);
    resultado += analizar_canal_16(lecturas, 5);
    resultado += analizar_canal_17(lecturas, 5);
    resultado += analizar_canal_18(lecturas, 5);
    resultado += analizar_canal_19(lecturas, 5);
    resultado += analizar_canal_20(lecturas, 5);
    resultado += analizar_canal_21(lecturas, 5);
    resultado += analizar_canal_22(lecturas, 5);
    resultado += analizar_canal_23(lecturas, 5);
    resultado += analizar_canal_24(lecturas, 5);
    return resultado > 0 ? 0 : 1;
}
