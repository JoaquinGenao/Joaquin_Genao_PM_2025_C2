#include <stdio.h>

int main(void) {
    float ALU[50][4];
    int N, i, j;
    float suma, promedio_alumno, promedio_examen[4] = {0};
    int examen_mayor;
    float mayor_promedio = 0;

    // Leer número de alumnos
    do {
        printf("Ingrese el número de alumnos (1 a 50): ");
        scanf("%d", &N);
    } while (N < 1 || N > 50);

    // Leer calificaciones de cada alumno
    for (i = 0; i < N; i++) {
        printf("\nAlumno %d:\n", i + 1);
        for (j = 0; j < 4; j++) {
            printf("  Calificación examen %d: ", j + 1);
            scanf("%f", &ALU[i][j]);
        }
    }

    // a) Promedio por alumno
    printf("\n--- Promedio de cada alumno ---\n");
    for (i = 0; i < N; i++) {
        suma = 0;
        for (j = 0; j < 4; j++) {
            suma += ALU[i][j];
        }
        promedio_alumno = suma / 4;
        printf("Alumno %d: %.2f\n", i + 1, promedio_alumno);
    }

    // b) Promedio por examen
    for (j = 0; j < 4; j++) {
        for (i = 0; i < N; i++) {
            promedio_examen[j] += ALU[i][j];
        }
        promedio_examen[j] /= N;
    }

    printf("\n--- Promedio del grupo en cada examen ---\n");
    for (j = 0; j < 4; j++) {
        printf("Examen %d: %.2f\n", j + 1, promedio_examen[j]);
    }

    // c) Examen con mayor promedio
    for (j = 0; j < 4; j++) {
        if (promedio_examen[j] > mayor_promedio) {
            mayor_promedio = promedio_examen[j];
            examen_mayor = j;
        }
    }

    printf("\nEl examen con mayor promedio fue el examen %d con %.2f puntos\n", examen_mayor + 1, mayor_promedio);

    return 0;
}
