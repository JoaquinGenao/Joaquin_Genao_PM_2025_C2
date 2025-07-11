#include <stdio.h>

int main(void) {
    int VEC[100];  // Arreglo de hasta 100 elementos
    int N;
    int i, positivos = 0, negativos = 0, nulos = 0;

    // Lectura del n�mero de elementos
    do {
        printf("Ingrese la cantidad de elementos del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Lectura de los elementos del arreglo
    for (i = 0; i < N; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);

        // Clasificaci�n del n�mero
        if (VEC[i] > 0)
            positivos++;
        else if (VEC[i] < 0)
            negativos++;
        else
            nulos++;
    }

    // Resultados
    printf("\nCantidad de n�meros positivos: %d\n", positivos);
    printf("Cantidad de n�meros negativos: %d\n", negativos);
    printf("Cantidad de n�meros nulos (cero): %d\n", nulos);

    return 0;
}
