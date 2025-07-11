#include <stdio.h>

// Función para ordenar arreglo en orden descendente (burbuja)
void ordenar_descendente(int arr[], int tam) {
    int i, j, temp;
    for (i = 0; i < tam - 1; i++) {
        for (j = 0; j < tam - 1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                // Intercambio
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int VEC1[100], VEC2[100], VEC3[200];
    int N, M, i, k = 0;

    // Lectura de tamaño de VEC1
    do {
        printf("Ingrese la cantidad de elementos de VEC1 (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Lectura de elementos de VEC1
    printf("Ingrese los %d elementos de VEC1:\n", N);
    for (i = 0; i < N; i++) {
        printf("VEC1[%d]: ", i);
        scanf("%d", &VEC1[i]);
        VEC3[k++] = VEC1[i];  // Copiar a VEC3
    }

    // Lectura de tamaño de VEC2
    do {
        printf("Ingrese la cantidad de elementos de VEC2 (1 a 100): ");
        scanf("%d", &M);
    } while (M < 1 || M > 100);

    // Lectura de elementos de VEC2
    printf("Ingrese los %d elementos de VEC2:\n", M);
    for (i = 0; i < M; i++) {
        printf("VEC2[%d]: ", i);
        scanf("%d", &VEC2[i]);
        VEC3[k++] = VEC2[i];  // Copiar a VEC3
    }

    // Ordenar VEC3 en orden descendente
    ordenar_descendente(VEC3, N + M);

    // Mostrar el arreglo ordenado
    printf("\nArreglo combinado y ordenado en forma descendente:\n");
    for (i = 0; i < N + M; i++) {
        printf("%d ", VEC3[i]);
    }
    printf("\n");

    return 0;
}
