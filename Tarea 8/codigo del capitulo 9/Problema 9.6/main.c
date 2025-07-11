#include <stdio.h>
#include <string.h>

void reemplazarMexico(FILE *entrada, FILE *salida) {
    char linea[256];
    char *ptr;

    while (fgets(linea, sizeof(linea), entrada) != NULL) {
        char resultado[512] = "";
        char *inicio = linea;

        while ((ptr = strstr(inicio, "m�xico")) != NULL) {
            // Copiar texto antes de "m�xico"
            strncat(resultado, inicio, ptr - inicio);
            strcat(resultado, "M�xico");  // Agregar reemplazo
            inicio = ptr + 6; // Avanzar despu�s de "m�xico"
        }

        // Copiar el resto de la l�nea
        strcat(resultado, inicio);

        // Escribir l�nea procesada al archivo de salida
        fputs(resultado, salida);
    }
}

int main() {
    FILE *in, *out;

    in = fopen("arc.txt", "r");
    out = fopen("arc1.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Error al abrir los archivos.\n");
        return 1;
    }

    reemplazarMexico(in, out);

    fclose(in);
    fclose(out);

    printf("Archivo procesado correctamente. Salida: arc1.txt\n");
    return 0;
}
