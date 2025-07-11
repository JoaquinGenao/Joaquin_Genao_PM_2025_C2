#include <stdio.h>

int main(void) {
    int VEC[100];
    int N, ELE, i, j, opcion, pos, encontrado;

    // Leer la cantidad inicial de elementos
    do {
        printf("Ingrese la cantidad de elementos iniciales del arreglo (1 a 100): ");
        scanf("%d", &N);
    } while (N < 1 || N > 100);

    // Leer los elementos ordenados
    printf("Ingrese los elementos del arreglo (ordenados de menor a mayor):\n");
    for (i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &VEC[i]);

        // Validar orden creciente
        if (i > 0 && VEC[i] < VEC[i - 1]) {
            printf("Error: el arreglo debe estar ordenado en forma creciente.\n");
            return 1;
        }
    }

    do {
        // Men�
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

                // Buscar si ya existe
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
                    // Encontrar la posici�n donde debe insertarse (para mantener el orden)
                    for (pos = 0; pos < N && VEC[pos] < ELE; pos++);

                    // Desplazar a la derecha para hacer espacio
                    for (j = N; j > pos; j--) {
                        VEC[j] = VEC[j - 1];
                    }

                    VEC[pos] = ELE;
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

                // Buscar el elemento
                encontrado = 0;
                for (i = 0; i < N; i++) {
                    if (VEC[i] == ELE) {
                        encontrado = 1;
                        break;
                    }
                }

                if (encontrado) {
                    // Eliminar el elemento desplazando hacia la izquierda
                    for (j = i; j < N - 1; j++) {
                        VEC[j] = VEC[j + 1];
                    }
                    N--;
                    printf("Elemento eliminado.\n");
                } else {
                    printf("El n�mero no se encuentra en el arreglo.\n");
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
