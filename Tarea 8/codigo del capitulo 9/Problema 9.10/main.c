#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 50
#define MAX_TELEFONO 20

typedef struct {
    int clave;
    char nombre[MAX_NOMBRE];
    int carrera; // 1 a 5
    float promedio_prepa;
    float calif_examen;
    char telefono[MAX_TELEFONO];
} Alumno;

int main() {
    FILE *archivo;
    FILE *archivosCarreras[5] = {NULL, NULL, NULL, NULL, NULL};
    Alumno alumno;

    int totalAlumnos = 0;
    float sumaExamenTotal = 0.0;

    // Variables para promedio por carrera
    int contCarrera[5] = {0,0,0,0,0};
    float sumaExamenCarrera[5] = {0,0,0,0,0};

    // Abrir archivo principal
    archivo = fopen("alu.dat", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo alu.dat\n");
        return 1;
    }

    // Abrir archivos de admitidos por carrera
    archivosCarreras[0] = fopen("Economia.dat", "wb");
    archivosCarreras[1] = fopen("Contabilidad.dat", "wb");
    archivosCarreras[2] = fopen("Derecho.dat", "wb");
    archivosCarreras[3] = fopen("IngComputacion.dat", "wb");
    archivosCarreras[4] = fopen("IngIndustrial.dat", "wb");

    for (int i=0; i<5; i++) {
        if (archivosCarreras[i] == NULL) {
            printf("Error al crear archivo de carrera %d\n", i+1);
            // Cerrar los que se abrieron y archivo principal antes de salir
            for (int j=0; j<i; j++) fclose(archivosCarreras[j]);
            fclose(archivo);
            return 1;
        }
    }

    // Procesar alumnos
    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
        totalAlumnos++;
        sumaExamenTotal += alumno.calif_examen;

        int carreraIdx = alumno.carrera - 1;
        if (carreraIdx < 0 || carreraIdx >= 5) {
            printf("Carrera inválida para alumno clave %d\n", alumno.clave);
            continue;
        }

        // Condiciones de admisión
        int admitido = 0;
        if ((alumno.calif_examen >= 1300 && alumno.promedio_prepa >= 8) ||
            (alumno.promedio_prepa >= 7 && alumno.calif_examen > 1399)) {
            admitido = 1;
        }

        if (admitido) {
            fwrite(&alumno, sizeof(Alumno), 1, archivosCarreras[carreraIdx]);
            contCarrera[carreraIdx]++;
            sumaExamenCarrera[carreraIdx] += alumno.calif_examen;
        }
    }

    fclose(archivo);

    for (int i=0; i<5; i++) fclose(archivosCarreras[i]);

    // Resultados
    printf("Promedio general del examen de admisión: %.2f\n",
           totalAlumnos ? sumaExamenTotal / totalAlumnos : 0);

    const char *nombresCarreras[] = {
        "Economía",
        "Contabilidad",
        "Derecho",
        "Ingeniería en Computación",
        "Ingeniería Industrial"
    };

    printf("\nPromedio del examen de admisión por carrera (solo admitidos):\n");
    for (int i=0; i<5; i++) {
        if (contCarrera[i] > 0) {
            printf("%s: %.2f (Admitidos: %d)\n",
                nombresCarreras[i], sumaExamenCarrera[i]/contCarrera[i], contCarrera[i]);
        } else {
            printf("%s: No hubo admitidos.\n", nombresCarreras[i]);
        }
    }

    return 0;
}
