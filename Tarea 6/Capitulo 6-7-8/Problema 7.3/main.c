#include <stdio.h>

int main() {
    char cad[50];
    int n;

    // Entrada de la cadena
    printf("Introduce una cadena de máximo 49 caracteres: ");
    fgets(cad, sizeof(cad), stdin);  // Lee cadena con espacios

    // Entrada de la posición
    printf("Introduce la posición (empezando desde 0): ");
    scanf("%d", &n);

    // Verificar que la posición esté dentro del rango válido
    if (n < 0 || cad[n] == '\0') {
        printf("Posición fuera de los límites de la cadena.\n");
    } else {
        if (cad[n] >= 'a' && cad[n] <= 'z') {
            printf("El carácter en la posición %d es una letra minúscula: '%c'\n", n, cad[n]);
        } else {
            printf("El carácter en la posición %d NO es una letra minúscula: '%c'\n", n, cad[n]);
        }
    }

    return 0;
}
