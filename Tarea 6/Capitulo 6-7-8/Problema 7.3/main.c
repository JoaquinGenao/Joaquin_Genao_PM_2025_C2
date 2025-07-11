#include <stdio.h>

int main() {
    char cad[50];
    int n;

    // Entrada de la cadena
    printf("Introduce una cadena de m�ximo 49 caracteres: ");
    fgets(cad, sizeof(cad), stdin);  // Lee cadena con espacios

    // Entrada de la posici�n
    printf("Introduce la posici�n (empezando desde 0): ");
    scanf("%d", &n);

    // Verificar que la posici�n est� dentro del rango v�lido
    if (n < 0 || cad[n] == '\0') {
        printf("Posici�n fuera de los l�mites de la cadena.\n");
    } else {
        if (cad[n] >= 'a' && cad[n] <= 'z') {
            printf("El car�cter en la posici�n %d es una letra min�scula: '%c'\n", n, cad[n]);
        } else {
            printf("El car�cter en la posici�n %d NO es una letra min�scula: '%c'\n", n, cad[n]);
        }
    }

    return 0;
}
