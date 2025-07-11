#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char fra[50];
    int palabras = 0;
    int i = 0;
    int enPalabra = 0;

    printf("Introduce una cadena (máximo 49 caracteres): ");
    fgets(fra, sizeof(fra), stdin);
    fra[strcspn(fra, "\n")] = '\0';  // Eliminar salto de línea

    while (fra[i] != '\0') {
        if (!isspace(fra[i]) && enPalabra == 0) {
            palabras++;
            enPalabra = 1;
        } else if (isspace(fra[i])) {
            enPalabra = 0;
        }
        i++;
    }

    printf("La cadena contiene %d palabras.\n", palabras);

    return 0;
}
