#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int matricula;
    float calif[3];
} Alumno;

int main() {
    FILE *f9, *f10, *f11;
    Alumno a9, a10;
    int leyo9 = 0, leyo10 = 0;

    // Abrir archivos binarios
    f9 = fopen("arc9.dat", "rb");
    f10 = fopen("arc10.dat", "rb");
    f11 = fopen("arc11.dat", "wb");

    if (!f9 || !f10 || !f11) {
        printf("Error al abrir uno de los archivos.\n");
        return 1;
    }

    // Leer primer registro de ambos archivos
    leyo9 = fread(&a9, sizeof(Alumno), 1, f9);
    leyo10 = fread(&a10, sizeof(Alumno), 1, f10);

    // Mezclar en orden ascendente
    while (leyo9 && leyo10) {
        if (a9.matricula < a10.matricula) {
            fwrite(&a9, sizeof(Alumno), 1, f11);
            leyo9 = fread(&a9, sizeof(Alumno), 1, f9);
        } else {
            fwrite(&a10, sizeof(Alumno), 1, f11);
            leyo10 = fread(&a10, sizeof(Alumno), 1, f10);
        }
    }

    // Si quedan registros en arc9.dat
    while (leyo9) {
        fwrite(&a9, sizeof(Alumno), 1, f11);
        leyo9 = fread(&a9, sizeof(Alumno), 1, f9);
    }

    // Si quedan registros en arc10.dat
    while (leyo10) {
        fwrite(&a10, sizeof(Alumno), 1, f11);
        leyo10 = fread(&a10, sizeof(Alumno), 1, f10);
    }

    fclose(f9);
    fclose(f10);
    fclose(f11);

    printf("Mezcla completada en arc11.dat\n");
    return 0;
}
