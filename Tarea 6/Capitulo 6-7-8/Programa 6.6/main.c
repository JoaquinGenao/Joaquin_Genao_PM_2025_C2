#include <stdio.h>

int main(void) {
    int MAT[50][50];
    int B[50];
    int N, i, j;

    // Leer el tamaño de la matriz
    do {
        printf("Ingrese el tamaño de la matriz cuadrada (1 a 50): ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    // Leer la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("MAT[%d][%d]: ", i, j);
            scanf("%d", &MAT[i][j]);
        }
    }

    // Calcular el arreglo B según el criterio
    for (i = 0; i < N; i++) {
        if (i % 3 == 0) {
            // Suma de fila i desde columna 0 hasta i-1
            B[i] = 0;
            for (j = 0; j < i; j++) {
                B[i] += MAT[i][j];
            }
        } else if (i % 3 == 1) {
            // Suma de la columna i completa
            B[i] = 0;
            for (j = 0; j < N; j++) {
                B[i] += MAT[j][i];
            }
        } else {
            // Producto de la columna i completa
            B[i] = 1;
            for (j = 0; j < N; j++) {
                B[i] *= MAT[j][i];
            }
        }
    }

    // Mostrar el arreglo B
    printf("\nArreglo B calculado:\n");
    for (i = 0; i < N; i++) {
        printf("B[%d] = %d\n", i, B[i]);
    }

    return 0;
}
