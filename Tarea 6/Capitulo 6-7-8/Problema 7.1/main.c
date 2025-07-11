#include <stdio.h>
#include <string.h>

int main() {
    char cad[50];
    char car;
    int i, contador = 0;

    // Entrada de cadena
    printf("Introduce una cadena de caracteres (m�ximo 49): ");
    fgets(cad, sizeof(cad), stdin);  // Usa fgets para evitar desbordamientos

    // Eliminar salto de l�nea si existe
    cad[strcspn(cad, "\n")] = '\0';

    // Entrada del car�cter
    printf("Introduce un car�cter a buscar: ");
    scanf(" %c", &car);  // El espacio antes de %c evita leer un salto de l�nea previo

    // Contar ocurrencias
    for (i = 0; cad[i] != '\0'; i++) {
        if (cad[i] == car) {
            contador++;
        }
    }

    // Resultado
    printf("El car�cter '%c' aparece %d veces en la cadena.\n", car, contador);

    return 0;
}
