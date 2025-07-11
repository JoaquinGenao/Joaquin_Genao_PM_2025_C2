#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct {
    int matricula;
    char nombre[MAX_NOMBRE];
    float promedio;
} Alumno;

void guardarAlumnos(const char *filename);
Alumno* leerAlumnos(const char *filename, int *cantidad);
void imprimirAlumnos(Alumno *alumnos, int cantidad);

int main() {
    const char *archivo = "alumnos.dat";
    int cantidad = 0;
    Alumno *alumnos = NULL;

    guardarAlumnos(archivo);

    alumnos = leerAlumnos(archivo, &cantidad);

    if (alumnos != NULL && cantidad > 0) {
        imprimirAlumnos(alumnos, cantidad);
        free(alumnos);
    } else {
        printf("No se pudieron leer alumnos o archivo vacío.\n");
    }

    return 0;
}

void guardarAlumnos(const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error al abrir archivo para escribir.\n");
        return;
    }

    int n;
    printf("¿Cuántos alumnos desea ingresar? ");
    scanf("%d", &n);
    getchar();

    Alumno temp;
    for (int i = 0; i < n; i++) {
        printf("Alumno %d:\n", i + 1);
        printf(" Matrícula: ");
        scanf("%d", &temp.matricula);
        getchar();

        printf(" Nombre: ");
        fgets(temp.nombre, MAX_NOMBRE, stdin);
        temp.nombre[strcspn(temp.nombre, "\n")] = '\0';

        printf(" Promedio: ");
        scanf("%f", &temp.promedio);
        getchar();

        fwrite(&temp, sizeof(Alumno), 1, file);
    }

    fclose(file);
    printf("Alumnos guardados.\n");
}

Alumno* leerAlumnos(const char *filename, int *cantidad) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error al abrir archivo para lectura.\n");
        *cantidad = 0;
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    *cantidad = size / sizeof(Alumno);
    if (*cantidad == 0) {
        fclose(file);
        return NULL;
    }

    Alumno *alumnos = (Alumno*) malloc(size);
    if (!alumnos) {
        printf("Error de memoria.\n");
        fclose(file);
        *cantidad = 0;
        return NULL;
    }

    fread(alumnos, sizeof(Alumno), *cantidad, file);
    fclose(file);

    return alumnos;
}

void imprimirAlumnos(Alumno *alumnos, int cantidad) {
    Alumno *ptr = alumnos;
    printf("\nAlumnos leídos:\n");
    printf("%-10s %-30s %-10s\n", "Matrícula", "Nombre", "Promedio");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < cantidad; i++, ptr++) {
        printf("%-10d %-30s %-10.2f\n", ptr->matricula, ptr->nombre, ptr->promedio);
    }
}
