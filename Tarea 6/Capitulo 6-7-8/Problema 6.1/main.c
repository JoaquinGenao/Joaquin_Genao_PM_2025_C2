#include <stdio.h>

int main(void) {
    int MAT[100][100];
    int N, i, j;
    int simetrica = 1;

    // Leer tamaño de la matriz
    do {
        printf("Ingrese el tamaño de la matriz cuadrada (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Leer los elementos de la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("MAT[%d][%d]: ", i, j);
            scanf("%d", &MAT[i][j]);
        }
    }

    // Verificar si es simétrica
    for (i = 0; i < N && simetrica; i++) {
        for (j = 0; j < N; j++) {
            if (MAT[i][j] != MAT[j][i]) {
                simetrica = 0;
                break;
            }
        }
    }

    // Resultado
    if (simetrica)
        printf("\nLa matriz es simétrica.\n");
    else
        printf("\nLa matriz NO es simétrica.\n");

    return 0;
}
