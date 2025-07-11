#include <stdio.h>
#include <ctype.h>  // Para isupper y islower
#include <string.h> // Para strlen

int main() {
    FILE *archivo;
    char linea[256];
    int minusculas = 0, mayusculas = 0;

    // Abrir el archivo
    archivo = fopen("arc.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo arc.txt\n");
        return 1;
    }

    // Leer l�nea por l�nea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        for (int i = 0; i < strlen(linea); i++) {
            if (isupper(linea[i])) {
                mayusculas++;
            } else if (islower(linea[i])) {
                minusculas++;
            }
        }
    }

    fclose(archivo);

    // Mostrar resultados
    printf("Letras may�sculas: %d\n", mayusculas);
    printf("Letras min�sculas: %d\n", minusculas);

    return 0;
}
