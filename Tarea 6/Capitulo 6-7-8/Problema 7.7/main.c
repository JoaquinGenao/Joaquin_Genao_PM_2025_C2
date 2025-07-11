#include <stdio.h>
#include <string.h>

int main() {
    char cad0[50], cad1[50];
    int count = 0;
    int len0, len1;

    printf("Introduce la primera cadena (máximo 49 caracteres): ");
    fgets(cad0, sizeof(cad0), stdin);
    cad0[strcspn(cad0, "\n")] = '\0';  // Eliminar salto de línea

    printf("Introduce la segunda cadena (máximo 49 caracteres): ");
    fgets(cad1, sizeof(cad1), stdin);
    cad1[strcspn(cad1, "\n")] = '\0';  // Eliminar salto de línea

    len0 = strlen(cad0);
    len1 = strlen(cad1);

    // Recorrer cad0 y buscar cad1 en cada posición posible
    for (int i = 0; i <= len0 - len1; i++) {
        int j;
        for (j = 0; j < len1; j++) {
            if (cad0[i + j] != cad1[j])
                break;
        }
        if (j == len1) {
            count++;
        }
    }

    printf("La cadena '%s' aparece %d veces en '%s'.\n", cad1, count, cad0);

    return 0;
}
