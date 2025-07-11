#include <stdio.h>

#define MAX 99  // Límite superior del orden N

void generarCuadradoMagico(int N) {
    int cuadrado[MAX][MAX] = {0};  // Inicializa todos los valores en 0

    int num = 1;
    int i = 0;
    int j = N / 2;  // Coloca el 1 en el centro de la primera fila

    while (num <= N * N) {
        cuadrado[i][j] = num;

        if (num % N == 0) {
            // Regla 4: Si es múltiplo de N, baja una fila
            i = (i + 1) % N;
        } else {
            // Regla 2 y 3: fila anterior, columna posterior
            i = (i - 1 + N) % N;  // Fila anterior (cíclica)
            j = (j + 1) % N;      // Columna posterior (cíclica)
        }

        num++;
    }

    // Imprime el cuadrado mágico
    printf("Cuadrado Mágico de orden %d:\n\n", N);
    for (int fila = 0; fila < N; fila++) {
        for (int col = 0; col < N; col++) {
            printf("%4d", cuadrado[fila][col]);
        }
        printf("\n");
    }
}

int main() {
    int N;

    printf("Introduce el orden impar del cuadrado mágico (N): ");
    scanf("%d", &N);

    if (N < 1 || N % 2 == 0 || N > MAX) {
        printf("El valor debe ser un número impar positivo menor o igual a %d.\n", MAX);
        return 1;
    }

    generarCuadradoMagico(N);
    return 0;
}
