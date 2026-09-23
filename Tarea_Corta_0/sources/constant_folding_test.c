// File name: constant_folding_test.c
int main(int argc, char *argv[]) {
    int w, x, y, z;
    w = 5 + 4 - 3 + 2;
    x = 5 * 4 + 3 / 2;
    y = 5 / 4 - 3 % 2;
    z = 5 * 4 * 3 * 2;
    return 0;
}