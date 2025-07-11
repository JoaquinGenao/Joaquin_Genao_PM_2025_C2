#include <stdio.h>

int main(void) {
    int VEC[100];
    int N, i, es_palindromo = 1;

    // Leer el tama�o del arreglo
    do {
        printf("Ingrese el n�mero de elementos del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Leer los elementos del arreglo
    printf("Ingrese los %d elementos del arreglo:\n", N);
    for (i = 0; i < N; i++) {
        printf("VEC[%d]: ", i);
        scanf("%d", &VEC[i]);
    }

    // Verificar si el arreglo es pal�ndromo
    for (i = 0; i < N / 2; i++) {
        if (VEC[i] != VEC[N - 1 - i]) {
            es_palindromo = 0;
            break;
        }
    }

    // Mostrar resultado
    if (es_palindromo)
        printf("\nEl arreglo es pal�ndromo.\n");
    else
        printf("\nEl arreglo NO es pal�ndromo.\n");

    return 0;
}
