#include <stdio.h>

int main(void) {
    long long FIB[100];  // Usamos 'long long' para manejar números grandes
    int i;

    // Inicialización de los dos primeros elementos
    FIB[0] = 0;
    FIB[1] = 1;

    // Cálculo de los siguientes 98 elementos
    for (i = 2; i < 100; i++) {
        FIB[i] = FIB[i - 1] + FIB[i - 2];
    }

    // Impresión del arreglo
    printf("Los primeros 100 números de Fibonacci son:\n");
    for (i = 0; i < 100; i++) {
        printf("%lld ", FIB[i]);
        if ((i + 1) % 5 == 0) printf("\n");  // Salto de línea cada 5 números para mayor legibilidad
    }

    return 0;
}
