#include <stdio.h>
#include <ctype.h>  // Para isupper y islower

int main() {
    FILE *archivo;
    char c;
    int minusculas = 0, mayusculas = 0;

    // Abrir archivo en modo lectura
    archivo = fopen("arc5.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo arc5.txt\n");
        return 1;
    }

    // Leer car�cter por car�cter
    while ((c = fgetc(archivo)) != EOF) {
        if (isupper(c)) {
            mayusculas++;
        } else if (islower(c)) {
            minusculas++;
        }
    }

    // Cerrar archivo
    fclose(archivo);

    // Mostrar resultados
    printf("Letras may�sculas: %d\n", mayusculas);
    printf("Letras min�sculas: %d\n", minusculas);

    return 0;
}
