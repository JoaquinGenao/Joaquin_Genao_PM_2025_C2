#include <stdio.h>

int main(void) {
    float ALU[100];  // Arreglo para almacenar las calificaciones
    int N, i;
    float suma = 0.0;
    int aprobados = 0;
    int mayores1500 = 0;

    // Leer la cantidad de alumnos
    do {
        printf("Ingrese el número de alumnos (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Leer las calificaciones de los alumnos
    for (i = 0; i < N; i++) {
        printf("Ingrese la calificación del alumno %d: ", i + 1);
        scanf("%f", &ALU[i]);

        suma += ALU[i];

        if (ALU[i] > 1300)
            aprobados++;

        if (ALU[i] >= 1500)
            mayores1500++;
    }

    // Cálculo del promedio general
    float promedio = suma / N;

    // Cálculo del porcentaje de aprobados
    float porcentaje_aprobados = (aprobados * 100.0) / N;

    // Resultados
    printf("\n--- Resultados ---\n");
    printf("a) Promedio general del grupo: %.2f\n", promedio);
    printf("b) Porcentaje de alumnos aprobados (>1300): %.2f%%\n", porcentaje_aprobados);
    printf("c) Número de alumnos con calificación >= 1500: %d\n", mayores1500);

    return 0;
}
