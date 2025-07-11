#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *archivo;
    char linea[256];
    float suma = 0.0;
    int contador = 0;

    archivo = fopen("arc2.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo arc2.txt\n");
        return 1;
    }

    // Procesar línea por línea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int i = 0;
        while (linea[i] != '\0') {
            // Buscar inicio de número
            if (isdigit(linea[i]) ||
               (linea[i] == '.' && isdigit(linea[i+1]))) {
                char numero[20];
                int j = 0;

                // Extraer número como cadena
                while (isdigit(linea[i]) || linea[i] == '.') {
                    numero[j++] = linea[i++];
                }
                numero[j] = '\0';

                // Convertir y acumular
                float valor = atof(numero);
                suma += valor;
                contador++;
            } else {
                i++;
            }
        }
    }

    fclose(archivo);

    // Resultados
    if (contador > 0) {
        float promedio = suma / contador;
        printf("Suma de los números: %.2f\n", suma);
        printf("Promedio: %.2f\n", promedio);
    } else {
        printf("No se encontraron números válidos.\n");
    }

    return 0;
}
