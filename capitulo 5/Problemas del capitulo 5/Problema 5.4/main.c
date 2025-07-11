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
        // Men� de opciones
        printf("\n--- MEN� ---\n");
        printf("1. Insertar un elemento\n");
        printf("2. Eliminar un elemento\n");
        printf("3. Mostrar arreglo\n");
        printf("4. Salir\n");
        printf("Seleccione una opci�n: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (N >= 100) {
                    printf("El arreglo est� lleno. No se puede insertar.\n");
                    break;
                }

                printf("Ingrese el n�mero a insertar: ");
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
                    printf("El n�mero ya existe. No se puede insertar duplicado.\n");
                } else {
                    VEC[N] = ELE;
                    N++;
                    printf("Elemento insertado.\n");
                }
                break;

            case 2:
                if (N == 0) {
                    printf("El arreglo est� vac�o.\n");
                    break;
                }

                printf("Ingrese el n�mero a eliminar: ");
                scanf("%d", &ELE);

                encontrado = 0;
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        // Mover todos los elementos hacia atr�s
                        for (j = i; j < N - 1; j++) {
                            VEC[j] = VEC[j + 1];
                        }
                        N--;  // Reducir el tama�o
                        printf("Elemento eliminado.\n");
                        break;
                    }
                }

                if (!encontrado) {
                    printf("El n�mero no se encontr� en el arreglo.\n");
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
                printf("Opci�n no v�lida.\n");
        }

    } while (opcion != 4);

    return 0;
}
