#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 50
#define MAX_MATERIAS 5
#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    float promedio;
} MATERIA;

typedef struct {
    int matricula;
    char nombre[MAX_NOMBRE];
    MATERIA materias[MAX_MATERIAS];
} ALUMNO;

int main() {
    ALUMNO alu[MAX_ALUMNOS];
    int n;  // Número de alumnos
    int i, j;

    printf("Ingrese el número de alumnos (máx. 50): ");
    scanf("%d", &n);
    getchar();  // Limpiar salto de línea

    // Entrada de datos
    for (i = 0; i < n; i++) {
        printf("\nAlumno %d\n", i + 1);
        printf("Matrícula: ");
        scanf("%d", &alu[i].matricula);
        getchar(); // limpiar buffer

        printf("Nombre completo: ");
        fgets(alu[i].nombre, MAX_NOMBRE, stdin);
        alu[i].nombre[strcspn(alu[i].nombre, "\n")] = '\0';

        for (j = 0; j < MAX_MATERIAS; j++) {
            printf("  Nombre de la materia %d: ", j + 1);
            fgets(alu[i].materias[j].nombre, MAX_NOMBRE, stdin);
            alu[i].materias[j].nombre[strcspn(alu[i].materias[j].nombre, "\n")] = '\0';

            printf("  Promedio en %s: ", alu[i].materias[j].nombre);
            scanf("%f", &alu[i].materias[j].promedio);
            getchar();  // Limpiar buffer
        }
    }

    // a) Matrícula y promedio general de cada alumno
    printf("\n--- Promedio general por alumno ---\n");
    for (i = 0; i < n; i++) {
        float suma = 0;
        for (j = 0; j < MAX_MATERIAS; j++) {
            suma += alu[i].materias[j].promedio;
        }
        float promedioGeneral = suma / MAX_MATERIAS;
        printf("Matrícula: %d | Nombre: %s | Promedio General: %.2f\n",
               alu[i].matricula, alu[i].nombre, promedioGeneral);
    }

    // b) Matrículas de los alumnos con calificación > 9 en la tercera materia
    printf("\n--- Alumnos con > 9 en la tercera materia ---\n");
    for (i = 0; i < n; i++) {
        if (alu[i].materias[2].promedio > 9.0) {
            printf("Matrícula: %d | Nombre: %s | Materia: %s | Calificación: %.2f\n",
                   alu[i].matricula, alu[i].nombre,
                   alu[i].materias[2].nombre, alu[i].materias[2].promedio);
        }
    }

    // c) Promedio general de la materia 4 (índice 3)
    float sumaMateria4 = 0;
    for (i = 0; i < n; i++) {
        sumaMateria4 += alu[i].materias[3].promedio;
    }
    float promedioMateria4 = sumaMateria4 / n;

    printf("\n--- Promedio general de la materia 4 (%s) ---\n", alu[0].materias[3].nombre);
    printf("Promedio: %.2f\n", promedioMateria4);

    return 0;
}
