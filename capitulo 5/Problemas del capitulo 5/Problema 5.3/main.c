#include <stdio.h>

int main(void) {
    long long FIB[100];  // Usamos 'long long' para manejar n�meros grandes
    int i;

    // Inicializaci�n de los dos primeros elementos
    FIB[0] = 0;
    FIB[1] = 1;

    // C�lculo de los siguientes 98 elementos
    for (i = 2; i < 100; i++) {
        FIB[i] = FIB[i - 1] + FIB[i - 2];
    }

    // Impresi�n del arreglo
    printf("Los primeros 100 n�meros de Fibonacci son:\n");
    for (i = 0; i < 100; i++) {
        printf("%lld ", FIB[i]);
        if ((i + 1) % 5 == 0) printf("\n");  // Salto de l�nea cada 5 n�meros para mayor legibilidad
    }

    return 0;
}
