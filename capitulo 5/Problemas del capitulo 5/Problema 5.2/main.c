#include <stdio.h>

int main(void) {
    int VEC[100], VEC_SIN_REP[100];
    int N, i, j = 0;

    // Lectura del número de elementos
    do {
        printf("Ingrese la cantidad de elementos del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Lectura del arreglo ordenado
    printf("Ingrese %d elementos del arreglo (ordenados de menor a mayor):\n", N);
    for (i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);
    }

    // Eliminación de elementos repetidos
    VEC_SIN_REP[0] = VEC[0]; // Siempre se guarda el primer elemento
    j = 1;
    for (i = 1; i < N; i++) {
        if (VEC[i] != VEC[i - 1]) {
            VEC_SIN_REP[j] = VEC[i];
            j++;
        }
    }

    // Mostrar resultado sin repetidos
    printf("\nArreglo sin elementos repetidos:\n");
    for (i = 0; i < j; i++) {
        printf("%d ", VEC_SIN_REP[i]);
    }
    printf("\n");

    return 0;
}
