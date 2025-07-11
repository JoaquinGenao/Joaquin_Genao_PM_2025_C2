#include <stdio.h>
#include <string.h>

#define MAX_PROPIEDADES 100

typedef struct {
    char clave[20];
    float superficie_cubierta;
    float superficie_terreno;
    char caracteristicas[100];
    char zona[30];
    char calle[30];
    char colonia[30];
    float precio;
    char disponibilidad;  // 'V' para venta, 'R' para renta
} PROPIEDAD;

void imprimirPropiedad(PROPIEDAD p) {
    printf("Clave: %s\n", p.clave);
    printf("Superficie cubierta: %.2f m2\n", p.superficie_cubierta);
    printf("Superficie terreno: %.2f m2\n", p.superficie_terreno);
    printf("Características: %s\n", p.caracteristicas);
    printf("Calle: %s\n", p.calle);
    printf("Colonia: %s\n", p.colonia);
    printf("Precio: %.2f soles\n\n", p.precio);
}

int main() {
    PROPIEDAD propie[MAX_PROPIEDADES];
    int n;

    printf("Ingrese el número de propiedades (máx 100): ");
    scanf("%d", &n);
    getchar();  // limpiar buffer

    // Entrada de propiedades
    for (int i = 0; i < n; i++) {
        printf("\n--- Propiedad %d ---\n", i + 1);
        printf("Clave: ");
        fgets(propie[i].clave, 20, stdin);
        propie[i].clave[strcspn(propie[i].clave, "\n")] = '\0';

        printf("Superficie cubierta (m2): ");
        scanf("%f", &propie[i].superficie_cubierta);

        printf("Superficie terreno (m2): ");
        scanf("%f", &propie[i].superficie_terreno);
        getchar();

        printf("Características: ");
        fgets(propie[i].caracteristicas, 100, stdin);
        propie[i].caracteristicas[strcspn(propie[i].caracteristicas, "\n")] = '\0';

        printf("Zona: ");
        fgets(propie[i].zona, 30, stdin);
        propie[i].zona[strcspn(propie[i].zona, "\n")] = '\0';

        printf("Calle: ");
        fgets(propie[i].calle, 30, stdin);
        propie[i].calle[strcspn(propie[i].calle, "\n")] = '\0';

        printf("Colonia: ");
        fgets(propie[i].colonia, 30, stdin);
        propie[i].colonia[strcspn(propie[i].colonia, "\n")] = '\0';

        printf("Precio (soles): ");
        scanf("%f", &propie[i].precio);

        printf("Disponibilidad (V = Venta, R = Renta): ");
        scanf(" %c", &propie[i].disponibilidad);
        getchar();  // limpiar buffer
    }

    // a) Propiedades en venta en Miraflores entre 450,000 y 650,000
    printf("\n--- Propiedades en venta en Miraflores entre 450,000 y 650,000 soles ---\n");
    for (int i = 0; i < n; i++) {
        if ((propie[i].disponibilidad == 'V' || propie[i].disponibilidad == 'v') &&
            strcmp(propie[i].zona, "Miraflores") == 0 &&
            propie[i].precio >= 450000 && propie[i].precio <= 650000) {
            imprimirPropiedad(propie[i]);
        }
    }

    // b) Propiedades en renta por zona y rango ingresado por el usuario
    char zonaBusqueda[30];
    float minPrecio, maxPrecio;

    printf("\n--- Búsqueda personalizada de propiedades en renta ---\n");
    printf("Ingrese zona: ");
    fgets(zonaBusqueda, 30, stdin);
    zonaBusqueda[strcspn(zonaBusqueda, "\n")] = '\0';

    printf("Ingrese precio mínimo: ");
    scanf("%f", &minPrecio);
    printf("Ingrese precio máximo: ");
    scanf("%f", &maxPrecio);

    printf("\n--- Propiedades en renta en %s entre %.2f y %.2f soles ---\n",
           zonaBusqueda, minPrecio, maxPrecio);

    for (int i = 0; i < n; i++) {
        if ((propie[i].disponibilidad == 'R' || propie[i].disponibilidad == 'r') &&
            strcmp(propie[i].zona, zonaBusqueda) == 0 &&
            propie[i].precio >= minPrecio && propie[i].precio <= maxPrecio) {
            imprimirPropiedad(propie[i]);
        }
    }

    return 0;
}
