#include <stdio.h>
#include <stdlib.h>

#define MAX_MATERIAS 5
#define MAX_NOMBRE 50

typedef struct {
    char materia[MAX_NOMBRE];
    float promedio;
} Materia;

typedef struct {
    int matricula;
    char nombre[MAX_NOMBRE];
    Materia materias[MAX_MATERIAS];
} Alumno;

int main() {
    FILE *archivo;
    Alumno alumno;
    int totalAlumnos = 0;
    float sumaMateria4 = 0.0;

    archivo = fopen("esc.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo esc.dat\n");
        return 1;
    }

    printf("Matrícula y promedio general de cada alumno:\n");
    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
        totalAlumnos++;

        // Calcular promedio general del alumno
        float sumaPromedios = 0.0;
        for (int i = 0; i < MAX_MATERIAS; i++) {
            sumaPromedios += alumno.materias[i].promedio;
        }
        float promedioGeneral = sumaPromedios / MAX_MATERIAS;
        printf("Matricula: %d - Promedio general: %.2f\n", alumno.matricula, promedioGeneral);

        // Sumar para el promedio general de materia 4
        sumaMateria4 += alumno.materias[3].promedio;  // índice 3 = cuarta materia

        // Verificar calificación en tercera materia (índice 2)
        if (alumno.materias[2].promedio > 9.0) {
            printf("  -> Alumno con calificación > 9 en 3ra materia: matrícula %d\n", alumno.matricula);
        }
    }

    if (totalAlumnos > 0) {
        float promedioMateria4 = sumaMateria4 / totalAlumnos;
        printf("\nPromedio general de la materia 4: %.2f\n", promedioMateria4);
    } else {
        printf("No se encontraron alumnos en el archivo.\n");
    }

    fclose(archivo);
    return 0;
}
