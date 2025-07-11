#include <stdio.h>
#include <string.h>

#define MAX_FILAS 20
#define MAX_COLS 30

int main() {
    int n, m;
    char FRA[MAX_FILAS][MAX_COLS];
    char temp[MAX_COLS];

    printf("Ingresa el número de filas (1-20): ");
    scanf("%d", &n);
    printf("Ingresa el tamaño máximo de cada cadena (1-30): ");
    scanf("%d", &m);
    getchar();  // Limpiar buffer

    if (n < 1 || n > MAX_FILAS || m < 1 || m > MAX_COLS) {
        printf("Valores fuera de rango.\n");
        return 1;
    }

    // Leer las cadenas
    for (int i = 0; i < n; i++) {
        printf("Introduce cadena fila %d: ", i + 1);
        fgets(FRA[i], m, stdin);

        // Eliminar salto de línea si existe
        size_t len = strlen(FRA[i]);
        if (len > 0 && FRA[i][len - 1] == '\n') {
            FRA[i][len - 1] = '\0';
        }
    }

    // Intercambiar filas: primera con última, segunda con penúltima, etc.
    for (int i = 0; i < n / 2; i++) {
        strcpy(temp, FRA[i]);
        strcpy(FRA[i], FRA[n - 1 - i]);
        strcpy(FRA[n - 1 - i], temp);
    }

    // Mostrar arreglo modificado
    printf("\nArreglo después del intercambio:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", FRA[i]);
    }

    return 0;
}
