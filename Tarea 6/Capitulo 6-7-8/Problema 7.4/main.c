#include <stdio.h>
#include <ctype.h>  // Para islower() y isupper()

int main() {
    char cad[50];
    int i, minusculas = 0, mayusculas = 0;

    // Entrada de la frase
    printf("Introduce una frase (máximo 49 caracteres): ");
    fgets(cad, sizeof(cad), stdin);

    // Recorrer la cadena y contar letras
    for (i = 0; cad[i] != '\0'; i++) {
        if (islower(cad[i])) {
            minusculas++;
        } else if (isupper(cad[i])) {
            mayusculas++;
        }
    }

    // Resultados
    printf("\nNúmero de letras minúsculas: %d\n", minusculas);
    printf("Número de letras mayúsculas: %d\n", mayusculas);

    return 0;
}
