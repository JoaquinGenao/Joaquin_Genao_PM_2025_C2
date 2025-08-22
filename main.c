#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    char placa[20];
    char marca[30];
    char modelo[30];
    char tipoCombustible[15];
    float kmGalonCarretera;
    float kmGalonCiudad;
} Vehiculo;

void guardarVehiculo(Vehiculo v) {
    FILE *f = fopen("vehiculos.txt", "a"); // "a" = append
    if (!f) {
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(f, "%s %s %s %s %.2f %.2f\n",
            v.placa, v.marca, v.modelo, v.tipoCombustible,
            v.kmGalonCarretera, v.kmGalonCiudad);
    fclose(f);
}

void listarVehiculos() {
    FILE *f = fopen("vehiculos.txt", "r");
    if (!f) {
        printf("No hay vehículos guardados.\n");
        return;
    }

    Vehiculo v;
    while (fscanf(f, "%s %s %s %s %f %f",
                  v.placa, v.marca, v.modelo, v.tipoCombustible,
                  &v.kmGalonCarretera, &v.kmGalonCiudad) == 6) {
        printf("Placa: %s | Marca: %s | Modelo: %s | Combustible: %s | Carretera: %.2f km/gal | Ciudad: %.2f km/gal\n",
               v.placa, v.marca, v.modelo, v.tipoCombustible,
               v.kmGalonCarretera, v.kmGalonCiudad);
    }
    fclose(f);
}

int main() {
    int opcion;
    do {
        printf("\n--- GESTIÓN DE VEHÍCULOS ---\n");
        printf("1. Agregar vehículo\n");
        printf("2. Listar vehículos\n");
        printf("3. Salir\n");
        printf("Seleccione: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            Vehiculo v;
            printf("Placa: "); scanf("%s", v.placa);
            printf("Marca: "); scanf("%s", v.marca);
            printf("Modelo: "); scanf("%s", v.modelo);
            printf("Tipo Combustible: "); scanf("%s", v.tipoCombustible);
            printf("Km x galon carretera: "); scanf("%f", &v.kmGalonCarretera);
            printf("Km x galon ciudad: "); scanf("%f", &v.kmGalonCiudad);

            guardarVehiculo(v);
            printf("Vehículo guardado!\n");
        }
        else if (opcion == 2) {
            listarVehiculos();
        }
    } while (opcion != 3);

    return 0;
}

