#include <stdio.h>

int main(void) {
    int MAT[50][50], TRANSPUESTA[50][50];
    int M, N, i, j;

    // Leer número de filas (M)
    do {
        printf("Ingrese el número de filas (1 a 50): ");
        scanf("%d", &M);
    } while (M < 1 || M > 50);

    // Leer número de columnas (N)
    do {
        printf("Ingrese el número de columnas (1 a 50): ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    // Leer la matriz original
    printf("Ingrese los elementos de la matriz (%d x %d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("MAT[%d][%d]: ", i, j);
            scanf("%d", &MAT[i][j]);
        }
    }

    // Calcular la transpuesta
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            TRANSPUESTA[j][i] = MAT[i][j];
        }
    }

    // Imprimir matriz original
    printf("\nMatriz original (%d x %d):\n", M, N);
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%4d", MAT[i][j]);
        }
        printf("\n");
    }

    // Imprimir matriz transpuesta
    printf("\nMatriz transpuesta (%d x %d):\n", N, M);
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%4d", TRANSPUESTA[i][j]);
        }
        printf("\n");
    }

    return 0;
}
📌 Ejemplo
Si ingresas:

makefile
Copy
Edit
M = 2, N = 3
1 2 3
4 5 6
La salida será:

java
Copy
Edit
Matriz original (2 x 3):
   1   2   3
   4   5   6


