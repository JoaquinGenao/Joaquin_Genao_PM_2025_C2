#include <stdio.h>

int main() {
    FILE *archivo;

    // Abrir el archivo en modo "append" para agregar al final
    archivo = fopen("libro.txt", "a");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Agregar la cadena al final
    fputs("\nFin del texto\n", archivo);

    // Cerrar el archivo
    fclose(archivo);

    printf("Texto agregado correctamente al archivo.\n");

    return 0;
}
