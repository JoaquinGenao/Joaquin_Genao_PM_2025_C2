#include <stdio.h>
#include <string.h>

#define MAX_PACIENTES 100
#define MAX_STR 50

typedef struct {
    char calle[MAX_STR];
    int numero;
    char colonia[MAX_STR];
    char cp[MAX_STR];
    char ciudad[MAX_STR];
    char telefono[MAX_STR];
} DOMICILIO;

typedef struct {
    char nombre[MAX_STR];
    int edad;
    char sexo;  // 'M' o 'F'
    int condicion;  // 1 a 5
    DOMICILIO domicilio;
} PACIENTE;

int main() {
    PACIENTE hospital[MAX_PACIENTES];
    int n;
    int i;

    // Estadísticas
    int hombres = 0, mujeres = 0;
    int condiciones[6] = {0};  // condiciones[1] a condiciones[5]

    // Entrada de pacientes
    printf("Ingrese el número de pacientes (máximo 100): ");
    scanf("%d", &n);
    getchar(); // limpiar buffer

    for (i = 0; i < n; i++) {
        printf("\n--- Paciente %d ---\n", i + 1);

        printf("Nombre y apellido: ");
        fgets(hospital[i].nombre, MAX_STR, stdin);
        hospital[i].nombre[strcspn(hospital[i].nombre, "\n")] = '\0';

        printf("Edad: ");
        scanf("%d", &hospital[i].edad);

        printf("Sexo (M/F): ");
        scanf(" %c", &hospital[i].sexo);

        printf("Condición (1 a 5): ");
        scanf("%d", &hospital[i].condicion);
        getchar(); // limpiar buffer

        printf("Calle: ");
        fgets(hospital[i].domicilio.calle, MAX_STR, stdin);
        hospital[i].domicilio.calle[strcspn(hospital[i].domicilio.calle, "\n")] = '\0';

        printf("Número: ");
        scanf("%d", &hospital[i].domicilio.numero);
        getchar();

        printf("Colonia: ");
        fgets(hospital[i].domicilio.colonia, MAX_STR, stdin);
        hospital[i].domicilio.colonia[strcspn(hospital[i].domicilio.colonia, "\n")] = '\0';

        printf("Código Postal: ");
        fgets(hospital[i].domicilio.cp, MAX_STR, stdin);
        hospital[i].domicilio.cp[strcspn(hospital[i].domicilio.cp, "\n")] = '\0';

        printf("Ciudad: ");
        fgets(hospital[i].domicilio.ciudad, MAX_STR, stdin);
        hospital[i].domicilio.ciudad[strcspn(hospital[i].domicilio.ciudad, "\n")] = '\0';

        printf("Teléfono: ");
        fgets(hospital[i].domicilio.telefono, MAX_STR, stdin);
        hospital[i].domicilio.telefono[strcspn(hospital[i].domicilio.telefono, "\n")] = '\0';

        // Contar sexo
        if (hospital[i].sexo == 'M' || hospital[i].sexo == 'm') {
            hombres++;
        } else if (hospital[i].sexo == 'F' || hospital[i].sexo == 'f') {
            mujeres++;
        }

        // Contar condición
        if (hospital[i].condicion >= 1 && hospital[i].condicion <= 5) {
            condiciones[hospital[i].condicion]++;
        }
    }

    // a) Porcentaje de hombres y mujeres
    float porHombres = (hombres * 100.0) / n;
    float porMujeres = (mujeres * 100.0) / n;

    printf("\n--- Porcentaje por sexo ---\n");
    printf("Hombres: %.2f%%\n", porHombres);
    printf("Mujeres: %.2f%%\n", porMujeres);

    // b) Pacientes por condición
    printf("\n--- Pacientes por condición ---\n");
    for (i = 1; i <= 5; i++) {
        printf("Condición %d: %d pacientes\n", i, condiciones[i]);
    }

    // c) Pacientes con condición 5
    printf("\n--- Pacientes con condición 5 (máxima gravedad) ---\n");
    for (i = 0; i < n; i++) {
        if (hospital[i].condicion == 5) {
            printf("Nombre: %s | Teléfono: %s\n",
                   hospital[i].nombre, hospital[i].domicilio.telefono);
        }
    }

    return 0;
}
