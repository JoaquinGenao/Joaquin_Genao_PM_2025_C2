#include <stdio.h>

#define PROVINCIAS 24
#define MESES 12
#define ANIOS 10

int main() {
    float LLU[PROVINCIAS][MESES][ANIOS];
    int i, j, k;

    // Entrada de datos de lluvias
    printf("Introduce los datos de lluvia (en mm):\n");
    for (i = 0; i < PROVINCIAS; i++) {
        printf("Provincia %d:\n", i + 1);
        for (k = 0; k < ANIOS; k++) {
            printf("  Año %d:\n", k + 1);
            for (j = 0; j < MESES; j++) {
                printf("    Mes %d: ", j + 1);
                scanf("%f", &LLU[i][j][k]);
            }
        }
    }

    // a) Provincia con mayor lluvia en total en 10 años
    float maxTotal = -1.0;
    int provinciaMax = -1;

    for (i = 0; i < PROVINCIAS; i++) {
        float suma = 0.0;
        for (k = 0; k < ANIOS; k++) {
            for (j = 0; j < MESES; j++) {
                suma += LLU[i][j][k];
            }
        }
        if (suma > maxTotal) {
            maxTotal = suma;
            provinciaMax = i;
        }
    }

    // b) Provincia con menor lluvia en el último año (año 9)
    float minUltimoAnio = 1e9;
    int provinciaMin = -1;

    for (i = 0; i < PROVINCIAS; i++) {
        float suma = 0.0;
        for (j = 0; j < MESES; j++) {
            suma += LLU[i][j][9];  // Año 10 = índice 9
        }
        if (suma < minUltimoAnio) {
            minUltimoAnio = suma;
            provinciaMin = i;
        }
    }

    // c) Mes con mayor lluvia en la provincia 18 (índice 17), año 5 (índice 4)
    int provincia18 = 17;
    int anio5 = 4;
    float mayorMes = -1.0;
    int mesMayor = -1;

    for (j = 0; j < MESES; j++) {
        float lluvia = LLU[provincia18][j][anio5];
        if (lluvia > mayorMes) {
            mayorMes = lluvia;
            mesMayor = j;
        }
    }

    // Resultados
    printf("\n--- RESULTADOS ---\n");

    printf("a) Provincia con mayor lluvia acumulada en 10 años: Provincia %d\n", provinciaMax + 1);
    printf("   Total: %.2f mm\n", maxTotal);

    printf("b) Provincia con menor lluvia en el último año: Provincia %d\n", provinciaMin + 1);
    printf("   Total: %.2f mm\n", minUltimoAnio);

    printf("c) Mes con mayor lluvia en Provincia 18 en el 5to año: Mes %d\n", mesMayor + 1);
    printf("   Lluvia: %.2f mm\n", mayorMes);

    return 0;
}
