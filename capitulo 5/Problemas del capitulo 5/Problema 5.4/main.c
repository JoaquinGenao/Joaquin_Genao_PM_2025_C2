#include <stdio.h>

int main(void) {
    int VEC[100];
    int N, ELE, i, j, opcion, encontrado;

    // Leer la cantidad inicial de elementos
    do {
        printf("Ingrese la cantidad de elementos iniciales del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Leer los elementos iniciales del arreglo
    for (i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);
    }

    do {
        // Menú de opciones
        printf("\n--- MENÚ ---\n");
        printf("1. Insertar un elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Mostrar arreglo\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (N >= 100) {
                    printf("El arreglo está lleno. No se puede insertar.\n");
                    break;
                }

                printf("Ingrese el número a insertar: ");
                scanf("%d", &ELE);

                // Verificar si ya existe
                encontrado = 0;
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    printf("El número ya existe. No se puede insertar duplicado.\n");
                } else {
                    VEC[N] = ELE;
                    N++;
                    printf("Elemento insertado.\n");
                }
                break;

            case 2:
                if (N == 0) {
                    printf("El arreglo está vacío.\n");
                    break;
                }

                printf("Ingrese el número a eliminar: ");
                scanf("%d", &ELE);

                encontrado = 0;
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        // Mover todos los elementos hacia atrás
                        for (j = i; j < N - 1; j++) {
                            VEC[j] = VEC[j + 1];
                        }
                        N--;  // Reducir el tamaño
                        printf("Elemento eliminado.\n");
                        break;
                    }
                }

                if (!encontrado) {
                    printf("El número no se encontró en el arreglo.\n");
                }
                break;

            case 3:
                printf("Contenido actual del arreglo:\n");
                for (i = 0; i < N; i++) {
                    printf("%d ", VEC[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != 4);

    return 0;
}
