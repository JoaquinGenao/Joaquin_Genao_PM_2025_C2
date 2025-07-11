#include <stdio.h>

int main(void) {
    int VEC[100];  // Arreglo de hasta 100 elementos
    int N;
    int i, positivos = 0, negativos = 0, nulos = 0;

    // Lectura del número de elementos
    do {
        printf("Ingrese la cantidad de elementos del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Lectura de los elementos del arreglo
    for (i = 0; i < N; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);

        // Clasificación del número
        if (VEC[i] > 0)
            positivos++;
        else if (VEC[i] < 0)
            negativos++;
        else
            nulos++;
    }

    // Resultados
    printf("\nCantidad de números positivos: %d\n", positivos);
    printf("Cantidad de números negativos: %d\n", negativos);
    printf("Cantidad de números nulos (cero): %d\n", nulos);

    return 0;
}
