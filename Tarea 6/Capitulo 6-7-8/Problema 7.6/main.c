#include <stdio.h>

int main() {
    char cad[50];
    int i = 0;

    printf("Introduce la cadena (ejemplo: 3p6c4a5q): ");
    scanf("%s", cad);

    while (cad[i] != '\0') {
        char numChar = cad[i];
        char letra = cad[i + 1];

        // Convertir carácter numérico a entero
        int veces = numChar - '0';

        // Imprimir la letra 'veces' veces
        for (int j = 0; j < veces; j++) {
            printf("%c", letra);
        }

        i += 2;  // Saltar al siguiente par número-letra
    }

    printf("\n");
    return 0;
}
