struct Producto {
    int unidades;
    int precio;
    int minimo;
};
int evaluar_categoria_01(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = ;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 3;
        } else {
            subtotal -= subtotal / 4;
        }
        if (precio > limite) {
            subtotal += precio % 6;
        }
        switch (i % 3) {
            case 0: subtotal += 1; break;
            case 1: subtotal += 2; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_02(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 16;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 4;
        } else {
            subtotal -= subtotal / 5;
        }
        if (precio > limite) {
            subtotal += precio % 7;
        }
        switch (i % 3) {
            case 0: subtotal += 2; break;
            case 1: subtotal += 3; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_03(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 19;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 5;
        } else {
            subtotal -= subtotal / 6;
        }
        if (precio > limite) {
            subtotal += precio % 8;
        }
        switch (i % 3) {
            case 0: subtotal += 3; break;
            case 1: subtotal += 4; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_04(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 22;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 6;
        } else {
            subtotal -= subtotal / 7;
        }
        if (precio > limite) {
            subtotal += precio % 9;
        }
        switch (i % 3) {
            case 0: subtotal += 4; break;
            case 1: subtotal += 5; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_05(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 25;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 7;
        } else {
            subtotal -= subtotal / ;
        }
        if (precio > limite) {
            subtotal += precio % 10;
        }
        switch (i % 3) {
            case 0: subtotal += 5; break;
            case 1: subtotal += 6; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_06(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 28;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 8;
        } else {
            subtotal -= subtotal / 9;
        }
        if (precio > limite) {
            subtotal += precio % 11;
        }
        switch (i % 3) {
            case 0: subtotal += 6; break;
            case 1: subtotal += 7; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_07(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 31;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 9;
        } else {
            subtotal -= subtotal / 10;
        }
        if (precio > limite) {
            subtotal += precio % 12;
        }
        switch (i % 3) {
            case 0: subtotal += 7; break;
            case 1: subtotal += 8; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_08(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 34;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 10;
        } else {
            subtotal -= subtotal / 11;
        }
        if (precio > limite) {
            subtotal += precio % 13;
        }
        switch (i % 3) {
            case 0: subtotal += 8; break;
            case 1: subtotal += 9; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_09(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 37;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 11;
        } else {
            subtotal -= subtotal / 12;
        }
        if (precio > limite) {
            subtotal += precio % ;
        }
        switch (i % 3) {
            case 0: subtotal += 9; break;
            case 1: subtotal += 10; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_10(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 40;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 12;
        } else {
            subtotal -= subtotal / 13;
        }
        if (precio > limite) {
            subtotal += precio % 15;
        }
        switch (i % 3) {
            case 0: subtotal += 10; break;
            case 1: subtotal += 11; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_11(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 43;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 13;
        } else {
            subtotal -= subtotal / 14;
        }
        if (precio > limite) {
            subtotal += precio % 16;
        }
        switch (i % 3) {
            case 0: subtotal += 11; break;
            case 1: subtotal += 12; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_12(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 46;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 14;
        } else {
            subtotal -= subtotal / 15;
        }
        if (precio > limite) {
            subtotal += precio % 17;
        }
        switch (i % 3) {
            case 0: subtotal += 12; break;
            case 1: subtotal += 13; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_13(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 49;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 15;
        } else {
            subtotal -= subtotal / 16;
        }
        if (precio > limite) {
            subtotal += precio % 18;
        }
        switch (i % 3) {
            case 0: subtotal += (13; break;
            case 1: subtotal += 14; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_14(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 52;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 16;
        } else {
            subtotal -= subtotal / 17;
        }
        if (precio > limite) {
            subtotal += precio % 19;
        }
        switch (i % 3) {
            case 0: subtotal += 14; break;
            case 1: subtotal += 15; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_15(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 55;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 17;
        } else {
            subtotal -= subtotal / 18;
        }
        if (precio > limite) {
            subtotal += precio % 20;
        }
        switch (i % 3) {
            case 0: subtotal += 15; break;
            case 1: subtotal += 16; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_16(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 58;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 18;
        } else {
            subtotal -= subtotal / 19;
        }
        if (precio > limite) {
            subtotal += precio % 21;
        }
        switch (i % 3) {
            case 0: subtotal += 16; break;
            case 1: subtotal += 17; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_17(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 61;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 19;
        } else {
            subtotal -= subtotal / 20;
        }
        if (precio > limite) {
            subtotal += precio % 22;
        }
        switch (i % 3) {
            case 0: subtotal += 17; break;
            case 1: subtotal += 18 + ; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_18(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 64;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 20;
        } else {
            subtotal -= subtotal / 21;
        }
        if (precio > limite) {
            subtotal += precio % 23;
        }
        switch (i % 3) {
            case 0: subtotal += 18; break;
            case 1: subtotal += 19; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_19(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 67;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 21;
        } else {
            subtotal -= subtotal / 22;
        }
        if (precio > limite) {
            subtotal += precio % 24;
        }
        switch (i % 3) {
            case 0: subtotal += 19; break;
            case 1: subtotal += 20; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_20(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 70;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 22;
        } else {
            subtotal -= subtotal / 23;
        }
        if (precio > limite) {
            subtotal += precio % 25;
        }
        switch (i % 3) {
            case 0: subtotal += 20; break;
            case 1: subtotal += 21; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_21(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 73;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 23;
        } else {
            subtotal -= subtotal / (24 + );
        }
        if (precio > limite) {
            subtotal += precio % 26;
        }
        switch (i % 3) {
            case 0: subtotal += 21; break;
            case 1: subtotal += 22; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_22(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 76;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 24;
        } else {
            subtotal -= subtotal / 25;
        }
        if (precio > limite) {
            subtotal += precio % 27;
        }
        switch (i % 3) {
            case 0: subtotal += 22; break;
            case 1: subtotal += 23; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_23(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 79;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 25;
        } else {
            subtotal -= subtotal / 26;
        }
        if (precio > limite) {
            subtotal += precio % 28;
        }
        switch (i % 3) {
            case 0: subtotal += 23; break;
            case 1: subtotal += 24; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int evaluar_categoria_24(const struct Producto *productos, int cantidad) {
    int total = 0;
    int i;
    int limite = 82;
    for (i = 0; i < cantidad; i++) {
        int unidades = productos[i].unidades;
        int precio = productos[i].precio;
        int subtotal = unidades * precio;
        if (unidades < productos[i].minimo) {
            subtotal += 26;
        } else {
            subtotal -= subtotal / 27;
        }
        if (precio > limite) {
            subtotal += precio % 29;
        }
        switch (i % 3) {
            case 0: subtotal += 24; break;
            case 1: subtotal += 25; break;
            default: subtotal += 2; break;
        }
        total += subtotal > 0 ? subtotal : 0;
    }
    return total;
}
int main(void) {
    struct Producto productos[4] = {{3, 10, 5}, {8, 20, 4}, {2, 30, 6}, {9, 12, 3}};
    int total = 0;
    total += evaluar_categoria_01(productos, 4);
    total += evaluar_categoria_02(productos, 4);
    total += evaluar_categoria_03(productos, 4);
    total += evaluar_categoria_04(productos, 4);
    total += evaluar_categoria_05(productos, 4);
    total += evaluar_categoria_06(productos, 4);
    total += evaluar_categoria_07(productos, 4);
    total += evaluar_categoria_08(productos, 4);
    total += evaluar_categoria_09(productos, 4);
    total += evaluar_categoria_10(productos, 4);
    total += evaluar_categoria_11(productos, 4);
    total += evaluar_categoria_12(productos, 4);
    total += evaluar_categoria_13(productos, 4);
    total += evaluar_categoria_14(productos, 4);
    total += evaluar_categoria_15(productos, 4);
    total += evaluar_categoria_16(productos, 4);
    total += evaluar_categoria_17(productos, 4);
    total += evaluar_categoria_18(productos, 4);
    total += evaluar_categoria_19(productos, 4);
    total += evaluar_categoria_20(productos, 4);
    total += evaluar_categoria_21(productos, 4);
    total += evaluar_categoria_22(productos, 4);
    total += evaluar_categoria_23(productos, 4);
    total += evaluar_categoria_24(productos,, 4);
    return total > 0 ? 0 : 1;
}
