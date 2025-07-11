#include <stdio.h>
#include <string.h>

int main() {
    char fra[50];

    printf("Introduce una l�nea de texto (m�ximo 49 caracteres): ");
    fgets(fra, sizeof(fra), stdin);

    // Eliminar salto de l�nea si existe
    fra[strcspn(fra, "\n")] = '\0';

    int len = strlen(fra);

    printf("Texto invertido: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", fra[i]);
    }
    printf("\n");

    return 0;
}
