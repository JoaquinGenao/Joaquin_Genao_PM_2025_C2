#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct {
    int matricula;
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

// Prototipos
void guardarAlumnos(const char *filename);
void cargarAlumnos(const char *filename, Alumno **alumnos, int *n);
void imprimirAlumnos(Alumno *alumnos, int n);
void bubbleSortPorNombre(Alumno *alumnos, int n);
void bubbleSortPorPromedio(Alumno *alumnos, int n);

int main() {
    int opcion;
    Alumno *alumnos = NULL;
    int n = 0;

    const char *filename = "alumnos.dat";

    do {
        printf("\n--- Menu ---\n");
        printf("1. Guardar alumnos\n");
        printf("2. Mostrar alumnos ordenados por nombre\n");
        printf("3. Mostrar alumnos ordenados por promedio\n");
        printf("4. Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d", &opcion);
        getchar(); // limpiar buffer

        switch(opcion) {
            case 1:
                guardarAlumnos(filename);
                break;
            case 2:
                cargarAlumnos(filename, &alumnos, &n);
                if (n > 0) {
                    bubbleSortPorNombre(alumnos, n);
                    imprimirAlumnos(alumnos, n);
                } else {
                    printf("No hay alumnos registrados.\n");
                }
                free(alumnos);
                alumnos = NULL;
                break;
            case 3:
                cargarAlumnos(filename, &alumnos, &n);
                if (n > 0) {
                    bubbleSortPorPromedio(alumnos, n);
                    imprimirAlumnos(alumnos, n);
                } else {
                    printf("No hay alumnos registrados.\n");
                }
                free(alumnos);
                alumnos = NULL;
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 4);

    return 0;
}

void guardarAlumnos(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error al abrir el archivo para escribir.\n");
        return;
    }

    int n;
    printf("Cuantos alumnos desea ingresar? ");
    scanf("%d", &n);
    getchar();

    Alumno alumno;
    for (int i = 0; i < n; i++) {
        printf("Alumno %d:\n", i + 1);
        printf("  Matricula: ");
        scanf("%d", &alumno.matricula);
        getchar();

        printf("  Nombre: ");
        fgets(alumno.nombre, MAX_NOMBRE, stdin);
        alumno.nombre[strcspn(alumno.nombre, "\n")] = 0; // eliminar \n

        printf("  Promedio: ");
        scanf("%f", &alumno.promedio);
        getchar();

        fwrite(&alumno, sizeof(Alumno), 1, file);
    }

    fclose(file);
    printf("Alumnos guardados correctamente.\n");
}

void cargarAlumnos(const char *filename, Alumno **alumnos, int *n) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("No se pudo abrir el archivo.\n");
        *n = 0;
        return;
    }

    // Calcular cantidad de registros
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    *n = size / sizeof(Alumno);
    rewind(file);

    *alumnos = (Alumno *) malloc(size);
    if (*alumnos == NULL) {
        printf("Error de memoria.\n");
        fclose(file);
        *n = 0;
        return;
    }

    fread(*alumnos, sizeof(Alumno), *n, file);
    fclose(file);
}

void imprimirAlumnos(Alumno *alumnos, int n) {
    printf("\n%-10s %-30s %-10s\n", "Matricula", "Nombre", "Promedio");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-30s %-10.2f\n", alumnos[i].matricula, alumnos[i].nombre, alumnos[i].promedio);
    }
}

// Bubble sort por nombre (alfabético ascendente)
void bubbleSortPorNombre(Alumno *alumnos, int n) {
    Alumno temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (strcmp(alumnos[j].nombre, alumnos[j+1].nombre) > 0) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = temp;
            }
        }
    }
}

// Bubble sort por promedio (descendente)
void bubbleSortPorPromedio(Alumno *alumnos, int n) {
    Alumno temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1-i; j++) {
            if (alumnos[j].promedio < alumnos[j+1].promedio) {
                temp = alumnos[j];
                alumnos[j] = alumnos[j+1];
                alumnos[j+1] = temp;
            }
        }
    }
}
