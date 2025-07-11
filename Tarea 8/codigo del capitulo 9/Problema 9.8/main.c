#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    char nombre[50];
    int carrera;
    float promedio;
} Alumno;

int main() {
    FILE *archivoOriginal, *archivoNuevo;
    Alumno *alumnos = NULL;
    int contador = 0, capacidad = 10;

    archivoOriginal = fopen("ad5.dat", "rb");
    if (archivoOriginal == NULL) {
        printf("No se pudo abrir el archivo ad5.dat\n");
        return 1;
    }

    // Reservar memoria inicial para 10 alumnos
    alumnos = (Alumno *) malloc(capacidad * sizeof(Alumno));
    if (alumnos == NULL) {
        printf("Error de memoria.\n");
        fclose(archivoOriginal);
        return 1;
    }

    // Leer todos los registros del archivo
    while (fread(&alumnos[contador], sizeof(Alumno), 1, archivoOriginal) == 1) {
        contador++;
        if (contador >= capacidad) {
            capacidad *= 2;
            alumnos = (Alumno *) realloc(alumnos, capacidad * sizeof(Alumno));
            if (alumnos == NULL) {
                printf("Error de memoria.\n");
                fclose(archivoOriginal);
                return 1;
            }
        }
    }
    fclose(archivoOriginal);

    // Abrir archivo nuevo para escritura
    archivoNuevo = fopen("ad5_ordenado.dat", "wb");
    if (archivoNuevo == NULL) {
        printf("No se pudo crear el archivo ad5_ordenado.dat\n");
        free(alumnos);
        return 1;
    }

    // Escribir en orden invertido (de menor a mayor matrícula)
    for (int i = contador - 1; i >= 0; i--) {
        fwrite(&alumnos[i], sizeof(Alumno), 1, archivoNuevo);
    }

    fclose(archivoNuevo);
    free(alumnos);

    printf("Archivo ordenado generado como ad5_ordenado.dat\n");
    return 0;
}
