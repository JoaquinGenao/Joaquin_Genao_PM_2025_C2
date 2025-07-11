#include <stdio.h>

#define MESES 12
#define DEPARTAMENTOS 3
#define ANIOS 8

const char *nombresDepto[] = {"Hilos", "Lanas", "Licra"};

int main() {
    float PRO[MESES][DEPARTAMENTOS][ANIOS];
    int i, j, k;

    // Entrada de datos
    printf("Introduce los datos de ventas (en miles):\n");
    for (k = 0; k < ANIOS; k++) {
        printf("Año %d:\n", k + 1);
        for (j = 0; j < DEPARTAMENTOS; j++) {
            printf("  Departamento %s:\n", nombresDepto[j]);
            for (i = 0; i < MESES; i++) {
                printf("    Mes %d: ", i + 1);
                scanf("%f", &PRO[i][j][k]);
            }
        }
    }

    // a) Ventas totales en el segundo año (índice 1)
    float totalSegundoAnio = 0.0;
    for (j = 0; j < DEPARTAMENTOS; j++) {
        for (i = 0; i < MESES; i++) {
            totalSegundoAnio += PRO[i][j][1];
        }
    }

    // b) Departamento con mayores ventas en el último año (índice 7)
    float totalDepto[DEPARTAMENTOS] = {0};
    for (j = 0; j < DEPARTAMENTOS; j++) {
        for (i = 0; i < MESES; i++) {
            totalDepto[j] += PRO[i][j][7];
        }
    }

    int deptoMayor = 0;
    for (j = 1; j < DEPARTAMENTOS; j++) {
        if (totalDepto[j] > totalDepto[deptoMayor]) {
            deptoMayor = j;
        }
    }

    // c) Departamento, mes y año con la mayor venta (una sola celda)
    float maxVenta = -1.0;
    int mesMax = -1, deptoMax = -1, anioMax = -1;

    for (k = 0; k < ANIOS; k++) {
        for (j = 0; j < DEPARTAMENTOS; j++) {
            for (i = 0; i < MESES; i++) {
                if (PRO[i][j][k] > maxVenta) {
                    maxVenta = PRO[i][j][k];
                    mesMax = i;
                    deptoMax = j;
                    anioMax = k;
                }
            }
        }
    }

    // Resultados
    printf("\n--- RESULTADOS ---\n");

    printf("a) Ventas totales de la empresa en el segundo año: %.2f\n", totalSegundoAnio);

    printf("b) Departamento con mayores ventas en el último año:\n");
    printf("   %s con un total de %.2f\n", nombresDepto[deptoMayor], totalDepto[deptoMayor]);

    printf("c) Mayor venta individual:\n");
    printf("   Departamento: %s\n", nombresDepto[deptoMax]);
    printf("   Mes: %d, Año: %d, Venta: %.2f\n", mesMax + 1, anioMax + 1, maxVenta);

    return 0;
}
