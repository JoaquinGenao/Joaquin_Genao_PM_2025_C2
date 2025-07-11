#include <stdio.h>

#define FONDOS 5
#define MESES 12

int main() {
    float FON[FONDOS][MESES];  // Valores mensuales de 2004
    float PRE[FONDOS];         // Valores al 31 de diciembre de 2003
    float rendimiento[FONDOS]; // Rendimientos anuales
    float promedio[FONDOS];    // Promedios anuales
    int i, j;

    // Entrada de precios al 31 de diciembre de 2003
    printf("Introduce los precios al 31 de diciembre de 2003 para cada fondo:\n");
    for (i = 0; i < FONDOS; i++) {
        printf("Fondo %d: ", i + 1);
        scanf("%f", &PRE[i]);
    }

    // Entrada de precios mensuales de 2004
    printf("\nIntroduce los valores mensuales del año 2004:\n");
    for (i = 0; i < FONDOS; i++) {
        printf("Fondo %d:\n", i + 1);
        for (j = 0; j < MESES; j++) {
            printf("Mes %d: ", j + 1);
            scanf("%f", &FON[i][j]);
        }
    }

    // Cálculos de rendimiento y promedio
    float mayorRendimiento = -1e9, menorRendimiento = 1e9;
    int fondoMayor = -1, fondoMenor = -1;

    printf("\nResultados:\n");
    for (i = 0; i < FONDOS; i++) {
        float suma = 0.0;
        for (j = 0; j < MESES; j++) {
            suma += FON[i][j];
        }

        promedio[i] = suma / MESES;
        rendimiento[i] = ((FON[i][MESES - 1] - PRE[i]) / PRE[i]) * 100.0;

        if (rendimiento[i] > mayorRendimiento) {
            mayorRendimiento = rendimiento[i];
            fondoMayor = i;
        }
        if (rendimiento[i] < menorRendimiento) {
            menorRendimiento = rendimiento[i];
            fondoMenor = i;
        }
    }

    // Imprimir resultados
    for (i = 0; i < FONDOS; i++) {
        printf("Fondo %d: Promedio Anual = %.2f, Rendimiento Anual = %.2f%%\n",
               i + 1, promedio[i], rendimiento[i]);
    }

    printf("\nFondo con mayor rendimiento: Fondo %d con %.2f%%\n", fondoMayor + 1, mayorRendimiento);
    printf("Fondo con menor rendimiento: Fondo %d con %.2f%%\n", fondoMenor + 1, menorRendimiento);

    return 0;
}
