#include <stdio.h>

int main() {
    char cad[50];
    int longitud = 0;

    // Leer la cadena
    printf("Introduce una cadena (m�ximo 49 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Contar la longitud manualmente (hasta el car�cter nulo '\0' o salto de l�nea)
    while (cad[longitud] != '\0' && cad[longitud] != '\n') {
        longitud++;
    }

    printf("La longitud de la cadena es: %d\n", longitud);

    return 0;
}
