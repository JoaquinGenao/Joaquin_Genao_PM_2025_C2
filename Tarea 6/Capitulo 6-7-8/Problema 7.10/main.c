#include <stdio.h>

#define MAX_CADENAS 20
#define MAX_LONG 50

// Función para calcular longitud sin strlen
int longitud_cadena(char *cad) {
    int len = 0;
    while (cad[len] != '\0' && cad[len] != '\n') {  // Evitar salto de línea si existe
        len++;
    }
    return len;
}

int main() {
    int n, i;
    char FRA[MAX_CADENAS][MAX_LONG];
    int max_len = -1;
    int indice_max = 0;

    printf("¿Cuántas cadenas deseas ingresar (máx 20)? ");
    scanf("%d", &n);
    getchar();  // limpiar buffer

    if (n < 1 || n > MAX_CADENAS) {
        printf("Número inválido de cadenas.\n");
        return 1;
    }

    // Leer las cadenas
    for (i = 0; i < n; i++) {
        printf("Introduce cadena %d: ", i + 1);
        fgets(FRA[i], MAX_LONG, stdin);

        // Eliminar salto de línea si existe
        for (int j = 0; FRA[i][j] != '\0'; j++) {
            if (FRA[i][j] == '\n') {
                FRA[i][j] = '\0';
                break;
            }
        }
    }

    // Buscar la cadena más larga
    for (i = 0; i < n; i++) {
        int len = longitud_cadena(FRA[i]);
        if (len > max_len) {
            max_len = len;
            indice_max = i;
        }
    }

    // Imprimir resultado
    printf("\nLa cadena más larga es:\n%s\nLongitud: %d\n", FRA[indice_max], max_len);

    return 0;
}
