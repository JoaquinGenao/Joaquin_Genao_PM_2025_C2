#include <stdio.h>

int main() {
    FILE *archivo;
    char car, c;
    int contador = 0;

    // Solicitar el carácter a buscar
    printf("Ingrese el carácter que desea buscar: ");
    scanf(" %c", &car); // Espacio antes de %c para evitar problemas con '\n'

    // Abrir archivo en modo lectura
    archivo = fopen("arch.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo arch.txt\n");
        return 1;
    }

    // Leer el archivo carácter por carácter y comparar
    while ((c = fgetc(archivo)) != EOF) {
        if (c == car) {
            contador++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Mostrar resultado
    printf("El carácter '%c' aparece %d veces en el archivo.\n", car, contador);

    return 0;
}
